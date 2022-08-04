/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: Bunker
 *** Description: Basic FB with empty ECC
 *** Version:
***     1.0: 2021-08-03/AK121668 -  - 
 *************************************************************************/

#include "Bunker.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Bunker_gen.cpp"
#endif


DEFINE_FIRMWARE_FB(FORTE_Bunker, g_nStringIdBunker)


const CStringDictionary::TStringId FORTE_Bunker::scm_anDataOutputNames[] = {g_nStringIdStatus};

const CStringDictionary::TStringId FORTE_Bunker::scm_anDataOutputTypeIds[] = {g_nStringIdSTRING};

const TForteInt16 FORTE_Bunker::scm_anEIWithIndexes[] = {-1};
const CStringDictionary::TStringId FORTE_Bunker::scm_anEventInputNames[] = {g_nStringIdDESIRED_COLOUR_CAP_NOT_AVAILABLE};

const TDataIOID FORTE_Bunker::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_Bunker::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_Bunker::scm_anEventOutputNames[] = {g_nStringIdMORE_CAPS_AVAILABLE};

const SAdapterInstanceDef FORTE_Bunker::scm_astAdapterInstances[] = {
  {g_nStringIdARTimeOut, g_nStringIdTimer, true}
};

const SFBInterfaceSpec FORTE_Bunker::scm_stFBInterfaceSpec = {
  1, scm_anEventInputNames, nullptr, scm_anEIWithIndexes,
  1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes,
  0, nullptr, nullptr,
  1, scm_anDataOutputNames, scm_anDataOutputTypeIds,
  1, scm_astAdapterInstances
};

void FORTE_Bunker::setInitialValues() {
}

void FORTE_Bunker::alg_alg_init(void) {
  st_Timer().DT() = CIEC_TIME("T#10s");
  st_Status() = "init mode";
}

void FORTE_Bunker::alg_alg_feeding(void) {
  st_Status() = "feeding now";
}

void FORTE_Bunker::alg_alg_feed_done(void) {
  st_Status() = "feeding Done";
}

void FORTE_Bunker::alg_alg_no_cap_alarm(void) {
  st_Status() = "Caps not available";
}


void FORTE_Bunker::enterStateSTART(void) {
  m_nECCState = scm_nStateSTART;
}

void FORTE_Bunker::enterStates_feed(void) {
  m_nECCState = scm_nStates_feed;
  alg_alg_feeding();
  sendAdapterEvent(scm_nTimerAdpNum, FORTE_ARTimeOut::scm_nEventSTARTID);
}

void FORTE_Bunker::enterStateState(void) {
  m_nECCState = scm_nStateState;
  alg_alg_feed_done();
  sendOutputEvent(scm_nEventMORE_CAPS_AVAILABLEID);
}

void FORTE_Bunker::enterStates_init(void) {
  m_nECCState = scm_nStates_init;
  alg_alg_init();
}


void FORTE_Bunker::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do {
    bTransitionCleared = true;
    switch(m_nECCState) {
      case scm_nStateSTART:
        if(scm_nEventDESIRED_COLOUR_CAP_NOT_AVAILABLEID == pa_nEIID)
          enterStates_init();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStates_feed:
        if(st_Timer().TimeOut() == pa_nEIID)
          enterStateState();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateState:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStates_init:
        if(1)
          enterStates_feed();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
        DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 4.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; // 0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID; // we have to clear the event after the first check in order to ensure correct behavior
  } while(bTransitionCleared);
}


