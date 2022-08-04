

#include "KafkaComLayer.h"
#include "commfb.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <csignal>
#include <cstring>
#include "KafkaHandler.h"
#include "utils/configFileParser.h"

using namespace forte::com_infra;

KafkaComLayer::KafkaComLayer(CComLayer* paUpperLayer, CBaseCommFB * pFB) : CComLayer(paUpperLayer, pFB),
    mUsedBuffer(0), mInterruptResp(e_Nothing){
  memset(mDataBuffer, 0, mBufferSize); //TODO change this to  dataBuffer{0} in the extended list when fully switching to C++11
}

KafkaComLayer::~KafkaComLayer() {
}

EComResponse KafkaComLayer::sendData(void* paData, unsigned int paSize) {
  producer->poll(0);
  RdKafka::ErrorCode resp = producer->produce(topic,RdKafka::Topic::PARTITION_UA,RdKafka::Producer::RK_MSG_COPY,paData,paSize,NULL, 0,0,NULL,NULL);
  producer->poll(0);
  if(resp != RdKafka::ERR_NO_ERROR){
    return e_ProcessDataNoSocket;
  }else{
    return e_ProcessDataOk;
  }
}

EComResponse KafkaComLayer::recvData(const void* paData,  unsigned int paSize) {
  DEVLOG_DEBUG("paSize %o \n", paSize);
  if(paSize > mBufferSize){
    paSize = mBufferSize; //Rest of the message is discarded
  }
  memcpy(mDataBuffer, paData, paSize);
  mUsedBuffer = paSize;
  mInterruptResp = e_ProcessDataOk;
  m_poFb->interruptCommFB(this);
  return mInterruptResp;
}

EComResponse KafkaComLayer::processInterrupt() {
  DEVLOG_DEBUG("processing interrupt \n");
  if((0 < mUsedBuffer) && (0 != m_poTopLayer)){
    DEVLOG_DEBUG("calling top layer \n");
     mInterruptResp = m_poTopLayer->recvData(mDataBuffer, mUsedBuffer);
     mUsedBuffer = 0;
  }
  return mInterruptResp;
}

bool loadConfig(std::string &paFileLocation, RdKafka::Conf *config){
  CConfigFileParser configFileParser(paFileLocation);
  std::pair<std::string, std::string> resultPair;
  std::string errstr;
  bool moreLinesToRead = true;
  while(moreLinesToRead){
    switch(configFileParser.parseNextLine(resultPair)){
      case CConfigFileParser::eOk:
        config->set(resultPair.first,resultPair.second,errstr);
        DEVLOG_DEBUG("errors: %s \n",errstr.c_str());
        break;
      case CConfigFileParser::eEmptyLine:
        break;
      case CConfigFileParser::eEndOfFile:
      default:
        moreLinesToRead = false;
        break;
    }
  }
  return true;
}

int32_t partition;
EComResponse KafkaComLayer::openConnection(char* paLayerParameter) {
  EComResponse eRetVal = e_InitInvalidId;
  
  std::string brokers;
  brokers = strtok(paLayerParameter, ",");
  topic = strtok(NULL, ",");
  std::string file;
  char* fileRead;

  fileRead = strtok(NULL, ",");
  if(fileRead != NULL){
    file.assign(fileRead);
  }
  //DEVLOG_DEBUG(const_cast<char*>(brokers.c_str()),'\n');
  //DEVLOG_DEBUG(const_cast<char*>(topic.c_str()),'\n');
  
  RdKafka::Conf *conf_prod = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
  RdKafka::Conf *conf_con= RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
  
  std::string errstr_prod;
  std::string errstr_con;

  switch (m_poFb->getComServiceType()){
    case e_Server:
      // TODO: Not implemented yet
      eRetVal = e_InitTerminated;
      break;
    case e_Client:
      // TODO: Not implemented yet
      eRetVal = e_InitTerminated;
      break;
    case e_Publisher:
      conf_prod->set("bootstrap.servers", brokers, errstr_prod);
      if(!errstr_prod.empty()){
        DEVLOG_ERROR("%s",errstr_prod.c_str());
      }
      if(!file.empty()){
        loadConfig(file,conf_prod);
      }
      producer = RdKafka::Producer::create(conf_prod, errstr_prod);
      eRetVal = e_InitOk;
      break;
    case e_Subscriber:
      //write configuration
      conf_con->set("bootstrap.servers", brokers, errstr_con);
      if(!file.empty()){
        loadConfig(file,conf_con);
      }
      //create topic
      RdKafka::Conf *tconf = RdKafka::Conf::create(RdKafka::Conf::CONF_TOPIC);
      //create consumer
      consumer = RdKafka::Consumer::create(conf_con, errstr_con);
      topic_obj = RdKafka::Topic::create(consumer, topic, tconf, errstr_con);

      RdKafka::ErrorCode resp = consumer->start(topic_obj, 0, RdKafka::Topic::OFFSET_END);
      partition = 0;
      if(resp != RdKafka::ERR_NO_ERROR){
        eRetVal = e_ProcessDataNoSocket;
        break;
      }
      getExtEvHandler<KafkaHandler>().registerLayer(this);
      eRetVal = e_InitOk;
      break;
    }
  return eRetVal;
}



void KafkaComLayer::closeConnection() {
  switch(m_poFb->getComServiceType()){
    case e_Subscriber:
      consumer->stop(topic_obj, partition);
      getExtEvHandler<KafkaHandler>().unregisterLayer(this);
      delete consumer;
      //delete topic_obj;
      break;
    case e_Publisher:
      break;
  }
}

