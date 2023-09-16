
#ifndef KAFKACOMLAYER_H_
#define KAFKACOMLAYER_H_

#include "comlayer.h"
#include "../../core/datatypes/forte_string.h"
#include <rdkafkacpp.h>
#include <devlog.h>

using namespace forte::com_infra;

class KafkaComLayer: public forte::com_infra::CComLayer{
public:
  
  KafkaComLayer(CComLayer* paUpperLayer, CBaseCommFB * paFB);
  virtual ~KafkaComLayer();

  EComResponse sendData(void* paData, unsigned int paSize);

  EComResponse recvData(const void *paData, unsigned int paSize);

  EComResponse processInterrupt();

  char const* getTopicName() const {
    return mTopicName.getValue();
  }

  //pointer to the producer
  RdKafka::Producer *producer;
  //consumer instance
  RdKafka::Consumer *consumer;
  //public topic
  RdKafka::Topic *topic_obj;
private:
  CIEC_STRING mTopicName;

  static const unsigned int mNoOfParameters = 1;
  static const unsigned int mBufferSize = 512;
  std::string topic;
  char mDataBuffer[mBufferSize];
  unsigned int mUsedBuffer;
  EComResponse mInterruptResp;

  EComResponse openConnection(char* paLayerParameter);
  void closeConnection();

  enum Parameters {
    Topic
  };

};

#endif
