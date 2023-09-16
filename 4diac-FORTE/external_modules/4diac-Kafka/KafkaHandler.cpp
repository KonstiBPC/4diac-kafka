#include <KafkaHandler.h>
#include "../../core/cominfra/commfb.h"
#include <criticalregion.h>
#include <string>
#include <devlog.h>
#include <algorithm>

DEFINE_HANDLER(KafkaHandler);

CSyncObject KafkaHandler::smKafkaMutex;
forte::arch::CSemaphore KafkaHandler::mStateSemaphore = forte::arch::CSemaphore();
bool KafkaHandler::mIsSemaphoreEmpty = true;

KafkaHandler::KafkaHandler(CDeviceExecution& paDeviceExecution) : CExternalEventHandler(paDeviceExecution)  {

}
KafkaHandler::~KafkaHandler(){
    if(isAlive()){
        setAlive(false);
    }
}

int KafkaHandler::getPriority() const{
  return 0;
}

void KafkaHandler::enableHandler(){
    if(!isAlive()){
        DEVLOG_DEBUG("enabled handler \n");
        start();
    }
}
void KafkaHandler::disableHandler(){
    if (isAlive()){
        setAlive(false);
        //resumeSuspend();
        end();
  }
}
void KafkaHandler::setPriority(int pa_prio){

}

void KafkaHandler::registerLayer(KafkaComLayer* paLayer){
    CCriticalRegion section(smKafkaMutex);
    //m_lstKafkaFBList.push_back(paLayer);
    m_toAdd.push_back(paLayer);
    enableHandler();
}
void KafkaHandler::unregisterLayer(KafkaComLayer* paLayer){
    CCriticalRegion section(smKafkaMutex);
    m_toRemove.push_back(paLayer);
    /*
    KafkaFBContainer::iterator it = std::find(m_lstKafkaFBList.begin(),m_lstKafkaFBList.end(),paLayer);
    if(it != m_lstKafkaFBList.end()){
        m_lstKafkaFBList.erase(it);
    }
    */
}

void KafkaHandler::run(){
    KafkaFBContainer::iterator it = m_lstKafkaFBList.begin();
    KafkaComLayer* layer;
    while(isAlive()){
        if(it != m_lstKafkaFBList.end()){
            layer = (*it);
            if(layer->consumer){
                //DEVLOG_DEBUG("CHECKING LAYER \n");
                RdKafka::Message *msg = layer->consumer->consume(layer->topic_obj, 0, 100); //blocking wait for message
                if(msg){
                    if(msg->len() >= 0){
                        switch(msg->err()){
                            case RdKafka::ERR_NO_ERROR:{
                                char* payload = static_cast<char *>(msg->payload());
                                DEVLOG_DEBUG("Handler Recv \n");
                                layer->recvData(payload,static_cast<unsigned int>(msg->len()));
                                startNewEventChain(layer->getCommFB());
                                }
                                break;
                            case RdKafka::ERR__PARTITION_EOF:
                                //ignore
                                break;
                            case RdKafka::ERR__UNKNOWN_TOPIC:
                            case RdKafka::ERR__UNKNOWN_PARTITION:
                                //report wrong configuration
                                break;
                            default:
                                //something went wrong
                                break;
                        }
                    }
                    delete msg;
                }
                layer->consumer->poll(0);
            }
        }
        if(it != m_lstKafkaFBList.end()){
            ++it;
        }
        if (it == m_lstKafkaFBList.end()){
            //do all necessary changes
            if(!m_toAdd.empty()){
                addRegisteredLayers();
            }
            if(!m_toRemove.empty()){
                removeDerigesteredLayers();
            }
            if(m_lstKafkaFBList.empty()){
                sleepThread(50);
                if(isAlive()){
                    //disableHandler();
                }
            }
            it = m_lstKafkaFBList.begin(); 
        }
    }
}

void KafkaHandler::addRegisteredLayers(){
    CCriticalRegion section(smKafkaMutex);
    KafkaFBContainer::iterator it = m_toAdd.begin();
    while(it != m_toAdd.end()){
        m_lstKafkaFBList.push_back(*it);
        ++it;
    }
    m_toAdd.clear();
}
void KafkaHandler::removeDerigesteredLayers(){
    CCriticalRegion section(smKafkaMutex);
    KafkaFBContainer::iterator it_remove = m_toRemove.begin();
    while(it_remove != m_toRemove.end()){
        KafkaFBContainer::iterator it = std::find(m_lstKafkaFBList.begin(),m_lstKafkaFBList.end(),*it_remove);
        if(it != m_lstKafkaFBList.end()){
            m_lstKafkaFBList.erase(it);
        }
        ++it_remove;
    }
    m_toRemove.clear();
}

void KafkaHandler::resumeSuspend(){
    if(mIsSemaphoreEmpty){
        mStateSemaphore.inc();
        mIsSemaphoreEmpty = false;
    }
}

void KafkaHandler::selfSuspend(){
    mStateSemaphore.waitIndefinitely();
}
