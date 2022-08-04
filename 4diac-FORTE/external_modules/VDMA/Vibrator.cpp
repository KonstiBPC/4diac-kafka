/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: Vibrator
 *** Description: Basic FB with empty ECC
 *** Version:
***     1.0: 2021-08-04/AK121668 -  - 
 *************************************************************************/

#include "Vibrator.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Vibrator_gen.cpp"
#endif


DEFINE_FIRMWARE_FB(FORTE_Vibrator, g_nStringIdVibrator)


const CStringDictionary::TStringId FORTE_Vibrator::scm_anDataOutputNames[] = {g_nStringIdStatus};

const CStringDictionary::TStringId FORTE_Vibrator::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING};

const TForteInt16 FORTE_Vibrator::scm_anEIWithIndexes[] = {-1, -1};
const CStringDictionary::TStringId FORTE_Vibrator::scm_anEventInputNames[] = {g_nStringIdWRONG_CAP_ORIENTATION, g_nStringIdCAP_NOT_REACHABLE};

const TDataIOID FORTE_Vibrator::scm_anEOWith[] = {0, 255, 0, 255};
const TForteInt16 FORTE_Vibrator::scm_anEOWithIndexes[] = {0, 2};
const CStringDictionary::TStringId FORTE_Vibrator::scm_anEventOutputNames[] = {g_nStringIdCAPS_FLIPPED, g_nStringIdCAPS_REACHABLE};

const SAdapterInstanceDef FORTE_Vibrator::scm_astAdapterInstances[] = {
  {g_nStringIdARTimeOut, g_nStringIdTimer, true}
};

const SFBInterfaceSpec FORTE_Vibrator::scm_stFBInterfaceSpec = {
  2, scm_anEventInputNames, nullptr, scm_anEIWithIndexes,
  2, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes,
  0, nullptr, nullptr,
  1, scm_anDataOutputNames, scm_anDataOutputTypeIds,
  1, scm_astAdapterInstances
};

void FORTE_Vibrator::setInitialValues() {
}

void FORTE_Vibrator::alg_alg_flip_init(void) {
  st_Timer().DT() = CIEC_TIME("T#10s");
  st_Status() = "init";
}

void FORTE_Vibrator::alg_alg_flip(void) {
  st_Status() = "flipping";
}

void FORTE_Vibrator::alg_alg_flip_exit(void) {
  st_Status() = "flipping Done";
}

void FORTE_Vibrator::alg_alg_separate_init(void) {
  st_Timer().DT() = CIEC_TIME("T#10s");
  st_Status() = "init";
}

void FORTE_Vibrator::alg_alg_separate(void) {
  st_Status() = "seperating";
}

void FORTE_Vibrator::alg_alg_separate_exit(void) {
  st_Status() = "seperating Done";
}


void FORTE_Vibrator::enterStateSTART(void) {
  m_nECCState = scm_nStateSTART;
}

void FORTE_Vibrator::enterStates_Flip(void) {
  m_nECCState = scm_nStates_Flip;
  alg_alg_flip_init();
  alg_alg_flip();
  sendAdapterEvent(scm_nTimerAdpNum, FORTE_ARTimeOut::scm_nEventSTARTID);
}

void FORTE_Vibrator::enterStates_Separate(void) {
  m_nECCState = scm_nStates_Separate;
  alg_alg_separate_init();
  alg_alg_separate();
  sendAdapterEvent(scm_nTimerAdpNum, FORTE_ARTimeOut::scm_nEventSTARTID);
}

void FORTE_Vibrator::enterStates_Flip_done(void) {
  m_nECCState = scm_nStates_Flip_done;
  alg_alg_flip_exit();
  sendOutputEvent(scm_nEventCAPS_FLIPPEDID);
}

void FORTE_Vibrator::enterStates_Seperate_done(void) {
  m_nECCState = scm_nStates_Seperate_done;
  alg_alg_separate_exit();
  sendOutputEvent(scm_nEventCAPS_REACHABLEID);
}


void FORTE_Vibrator::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do {
    bTransitionCleared = true;
    switch(m_nECCState) {
      case scm_nStateSTART:
        if(scm_nEventWRONG_CAP_ORIENTATIONID == pa_nEIID)
          enterStates_Flip();
        else
        if(scm_nEventCAP_NOT_REACHABLEID == pa_nEIID)
          enterStates_Separate();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStates_Flip:
        if(st_Timer().TimeOut() == pa_nEIID)
          enterStates_Flip_done();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStates_Separate:
        if(st_Timer().TimeOut() == pa_nEIID)
          enterStates_Seperate_done();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStates_Flip_done:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStates_Seperate_done:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
        DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 5.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; // 0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID; // we have to clear the event after the first check in order to ensure correct behavior
  } while(bTransitionCleared);
}


