/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FB_Detect_VarChange
 *** Description: Simple FB with one algorithm
 *** Version:
***     1.0: 2021-08-03/AK121668 -  - 
 *************************************************************************/

#include "FB_Detect_VarChange.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FB_Detect_VarChange_gen.cpp"
#endif


DEFINE_FIRMWARE_FB(FORTE_FB_Detect_VarChange, g_nStringIdFB_Detect_VarChange)

const CStringDictionary::TStringId FORTE_FB_Detect_VarChange::scm_anDataInputNames[] = {g_nStringIdIN_Var};

const CStringDictionary::TStringId FORTE_FB_Detect_VarChange::scm_anDataInputTypeIds[] = {g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_FB_Detect_VarChange::scm_anDataOutputNames[] = {g_nStringIdOUT_Var, g_nStringIdChanged};

const CStringDictionary::TStringId FORTE_FB_Detect_VarChange::scm_anDataOutputTypeIds[] = {g_nStringIdUSINT, g_nStringIdBOOL};

const TDataIOID FORTE_FB_Detect_VarChange::scm_anEIWith[] = {0, 255};
const TForteInt16 FORTE_FB_Detect_VarChange::scm_anEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FB_Detect_VarChange::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_FB_Detect_VarChange::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FORTE_FB_Detect_VarChange::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FB_Detect_VarChange::scm_anEventOutputNames[] = {g_nStringIdCNF};


const SFBInterfaceSpec FORTE_FB_Detect_VarChange::scm_stFBInterfaceSpec = {
  1, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes,
  1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes,
  1, scm_anDataInputNames, scm_anDataInputTypeIds,
  2, scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, nullptr
};

        const CStringDictionary::TStringId FORTE_FB_Detect_VarChange::scm_anInternalsNames[] = {g_nStringIdiValue_Changed};
        const CStringDictionary::TStringId FORTE_FB_Detect_VarChange::scm_anInternalsTypeIds[] = {g_nStringIdBOOL};
        const SInternalVarsInformation FORTE_FB_Detect_VarChange::scm_stInternalVars = {1, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_FB_Detect_VarChange::setInitialValues() {
}
void FORTE_FB_Detect_VarChange::alg_REQ(void) {
  if((st_OUT_Var() != st_IN_Var())) {
  	st_iValue_Changed() = true;
  	st_OUT_Var() = st_IN_Var();
  }
  st_Changed() = st_iValue_Changed();
  if((st_OUT_Var() == st_IN_Var())) {
  	st_iValue_Changed() = false;
  }
}


