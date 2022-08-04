#include <fbdkSelectLayer.h>
#include <string>
#include <stdexcept> 
#include <algorithm> 
#include <devlog.h>


using namespace forte::com_infra;

fbdkSelectLayer::fbdkSelectLayer(CComLayer* pa_poUpperLayer, CBaseCommFB * pa_poFB) : CFBDKASN1ComLayer(pa_poUpperLayer, pa_poFB) {

}
fbdkSelectLayer::~fbdkSelectLayer(){

}

EComResponse fbdkSelectLayer::openConnection(char* paLayerParameter) {
    char* param;
    param = strtok(paLayerParameter, ",");
    while(param != NULL){
        try{
            selected.push_back(std::stoi(param));
        }catch (const std::invalid_argument& ia){
            return e_InitInvalidId;
        }
        param = strtok(NULL, ",");
    }
    if(m_poFb->getNumRD() < selected.size()){
        return e_InitInvalidId;
    }else{
        while(m_poFb->getNumRD() > selected.size()){
            selected.push_back(selected.size()+1);
        }
    }
    return e_InitOk;
}

//main implementation taken from super class
EComResponse fbdkSelectLayer::recvData(const void *paData, unsigned int paSize){
  TForteByte *receivedData = const_cast<TForteByte*>(static_cast<const TForteByte *>(paData));
  EComResponse eRetVal = e_Nothing;
  int loopCount = 1;
  if(m_poFb != 0){
    CIEC_ANY *apoRDs = m_poFb->getRDs();
    unsigned int unNumRD = m_poFb->getNumRD();
    unsigned int usedBufferSize = 0;
    TForteByte *usedBuffer = 0;

    // TODO: only copy if necessary
    if(0 == mDeserBufPos){
      usedBuffer = receivedData;
      usedBufferSize = paSize;
    }
    else{
      if((paSize + mDeserBufPos) > mDeserBufSize){
        resizeDeserBuffer(paSize + mDeserBufPos);
      }
      memcpy((mDeserBuf + mDeserBufPos), receivedData, paSize);
      usedBuffer = mDeserBuf;
      mDeserBufPos = mDeserBufPos + paSize;
      usedBufferSize = mDeserBufPos;
    }
    int nBuf;
    while(usedBufferSize != 0){
      if(unNumRD == 0){
        nBuf = 1;
      }
      else{
        if(0 == apoRDs && loopCount < unNumRD){
          DEVLOG_ERROR("Data type error\n");
          eRetVal = e_ProcessDataDataTypeError;
          break;
        }
        if(loopCount - 1 == unNumRD){
          mDOPos = 0;
          mDeserBufPos = 0;
          return e_ProcessDataOk;
        }
        nBuf = deserializeDataPoint(usedBuffer, usedBufferSize, apoRDs[mDOPos]);
      }

      // deserialize failed, copy data into buffer for next package
      if(nBuf <= 0){
        if(-2 == nBuf){
          //We had a data type problem
          eRetVal = e_ProcessDataDataTypeError;
          break;
        }
        else{
          if(0 == mDeserBufPos){ //usedBuffer == recvData
            if((mDeserBufSize) < usedBufferSize){
              resizeDeserBuffer(usedBufferSize);
            }
            memcpy(mDeserBuf, usedBuffer, usedBufferSize);
            mDeserBufPos = usedBufferSize;
          }
          nBuf = usedBufferSize;
        }
      }
      else{
        mDOPos++; //instead set the buffer to the point we want it
        loopCount++;
        mDeserBufPos = 0; // TODO: MH: think on this
      }

      usedBufferSize -= nBuf;
      usedBuffer += nBuf;

      // required if e.g. the first element is an bool and the second element is "fragmented" - otherwise the resize in the buffer will not be resized
      receivedData += nBuf;

      if(mDOPos >= unNumRD){
        mDOPos = 0;
        eRetVal = e_ProcessDataOk;
        //FIXME if at this point data is left it is from a second run. Better first deliver this packet and afterwards handle second run
      }
    }
  }
  return eRetVal;
}


