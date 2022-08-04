/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: Camera
 *** Description: Basic FB with empty ECC
 *** Version:
***     1.0: 2021-08-03/AK121668 -  - 
 *************************************************************************/

#include "Camera.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Camera_gen.cpp"
#endif


DEFINE_FIRMWARE_FB(FORTE_Camera, g_nStringIdCamera)

const CStringDictionary::TStringId FORTE_Camera::scm_anDataInputNames[] = {g_nStringIdProduct_Color};

const CStringDictionary::TStringId FORTE_Camera::scm_anDataInputTypeIds[] = {g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_Camera::scm_anDataOutputNames[] = {g_nStringIdPick_Pos_X, g_nStringIdPick_Pos_Y, g_nStringIdPick_Pos_Z};

const CStringDictionary::TStringId FORTE_Camera::scm_anDataOutputTypeIds[] = {g_nStringIdSINT, g_nStringIdSINT, g_nStringIdSINT};

const TDataIOID FORTE_Camera::scm_anEIWith[] = {0, 255};
const TForteInt16 FORTE_Camera::scm_anEIWithIndexes[] = {0, -1, -1, -1};
const CStringDictionary::TStringId FORTE_Camera::scm_anEventInputNames[] = {g_nStringIdCAP_REQUIRED, g_nStringIdBUNKER_FEED_CAPS, g_nStringIdVIBRATOR_ORIENTED_CORRECT, g_nStringIdVIBRATOR_CAP_REACHABLE};

const TDataIOID FORTE_Camera::scm_anEOWith[] = {0, 1, 2, 255};
const TForteInt16 FORTE_Camera::scm_anEOWithIndexes[] = {-1, -1, -1, 0};
const CStringDictionary::TStringId FORTE_Camera::scm_anEventOutputNames[] = {g_nStringIdDESIRED_COLOR_CAP_NOT_AVAILABLE, g_nStringIdWRONG_CAP_ORIENTATION, g_nStringIdCAP_NOT_REACHANBLE, g_nStringIdCAP_RECHANBLE};


const SFBInterfaceSpec FORTE_Camera::scm_stFBInterfaceSpec = {
  4, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes,
  4, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes,
  1, scm_anDataInputNames, scm_anDataInputTypeIds,
  3, scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, nullptr
};

void FORTE_Camera::setInitialValues() {
}

void FORTE_Camera::alg_alg_find_object(void) {
  st_Pick_Pos_X() = 100;
  st_Pick_Pos_Y() = 50;
  st_Pick_Pos_Z() = 5;
}


void FORTE_Camera::enterStateSTART(void) {
  m_nECCState = scm_nStateSTART;
}

void FORTE_Camera::enterStates_find_Object(void) {
  m_nECCState = scm_nStates_find_Object;
  sendOutputEvent(scm_nEventDESIRED_COLOR_CAP_NOT_AVAILABLEID);
}

void FORTE_Camera::enterStates_Bunker_Adding_more_Caps(void) {
  m_nECCState = scm_nStates_Bunker_Adding_more_Caps;
  sendOutputEvent(scm_nEventWRONG_CAP_ORIENTATIONID);
}

void FORTE_Camera::enterStates_vibrator_worked(void) {
  m_nECCState = scm_nStates_vibrator_worked;
  alg_alg_find_object();
  sendOutputEvent(scm_nEventCAP_RECHANBLEID);
}

void FORTE_Camera::enterStates_Cap_not_Reachable(void) {
  m_nECCState = scm_nStates_Cap_not_Reachable;
  sendOutputEvent(scm_nEventCAP_NOT_REACHANBLEID);
}


void FORTE_Camera::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do {
    bTransitionCleared = true;
    switch(m_nECCState) {
      case scm_nStateSTART:
        if(scm_nEventCAP_REQUIREDID == pa_nEIID)
          enterStates_find_Object();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStates_find_Object:
        if(scm_nEventBUNKER_FEED_CAPSID == pa_nEIID)
          enterStates_Bunker_Adding_more_Caps();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStates_Bunker_Adding_more_Caps:
        if(scm_nEventVIBRATOR_ORIENTED_CORRECTID == pa_nEIID)
          enterStates_Cap_not_Reachable();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStates_vibrator_worked:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStates_Cap_not_Reachable:
        if(scm_nEventVIBRATOR_CAP_REACHABLEID == pa_nEIID)
          enterStates_vibrator_worked();
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


