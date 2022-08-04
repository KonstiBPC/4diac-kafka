/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: ContentFilter
 *** Description: FB to check if a member value is changed or no!
 *** Version:
***     1.0: 2021-07-23/AK121668 -  - 
 *************************************************************************/

#include "ContentFilter.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "ContentFilter_gen.cpp"
#endif


DEFINE_FIRMWARE_FB(FORTE_ContentFilter, g_nStringIdContentFilter)

const CStringDictionary::TStringId FORTE_ContentFilter::scm_anDataInputNames[] = {g_nStringIdStruct_Message, g_nStringIdFilter_name};

const CStringDictionary::TStringId FORTE_ContentFilter::scm_anDataInputTypeIds[] = {g_nStringIdspinner, g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_ContentFilter::scm_anDataOutputNames[] = {g_nStringIdError, g_nStringIdNew_Value};

const CStringDictionary::TStringId FORTE_ContentFilter::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING};

const TDataIOID FORTE_ContentFilter::scm_anEIWith[] = {1, 0, 255};
const TForteInt16 FORTE_ContentFilter::scm_anEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_ContentFilter::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_ContentFilter::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FORTE_ContentFilter::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_ContentFilter::scm_anEventOutputNames[] = {g_nStringIdCNF};


const SFBInterfaceSpec FORTE_ContentFilter::scm_stFBInterfaceSpec = {
  1, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes,
  1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes,
  2, scm_anDataInputNames, scm_anDataInputTypeIds,
  2, scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, nullptr
};

const SCFB_FBInstanceData FORTE_ContentFilter::scm_astInternalFBs[] = {
  {g_nStringIdGET_STRUCT_VALUE_2, g_nStringIdGET_STRUCT_VALUE},
  {g_nStringIdE_SWITCH_1, g_nStringIdE_SWITCH},
  {g_nStringIdGET_STRUCT_VALUE_3, g_nStringIdGET_STRUCT_VALUE},
  {g_nStringIdSTRING2STRING, g_nStringIdSTRING2STRING},
  {g_nStringIdF_EQ, g_nStringIdF_EQ},
  {g_nStringIdUSINT2USINT, g_nStringIdUSINT2USINT}
};

const SCFB_FBParameter FORTE_ContentFilter::scm_astParamters[] = {
  {0, g_nStringIdmember, "'current_pos'"},
  {2, g_nStringIdmember, "'colour'"},
  {4, g_nStringIdIN2, "USINT#3"},
};

const SCFB_FBConnectionData FORTE_ContentFilter::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_EQ, g_nStringIdCNF), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_SWITCH_1, g_nStringIdEI), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdGET_STRUCT_VALUE_3, g_nStringIdCNF), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSTRING2STRING, g_nStringIdREQ), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdGET_STRUCT_VALUE_2, g_nStringIdCNF), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdGET_STRUCT_VALUE_3, g_nStringIdREQ), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_SWITCH_1, g_nStringIdEO1), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNF), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdGET_STRUCT_VALUE_2, g_nStringIdREQ), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdUSINT2USINT, g_nStringIdCNF), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_EQ, g_nStringIdREQ), 4},
};

const SCFB_FBFannedOutConnectionData FORTE_ContentFilter::scm_astFannedOutEventConnections[] = {
  {2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdUSINT2USINT, g_nStringIdREQ), 5},
};

const SCFB_FBConnectionData FORTE_ContentFilter::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdGET_STRUCT_VALUE_3, g_nStringIdoutput), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSTRING2STRING, g_nStringIdIN), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_EQ, g_nStringIdOUT), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_SWITCH_1, g_nStringIdG), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSTRING2STRING, g_nStringIdOUT), 3, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdNew_Value), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdFilter_name), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdGET_STRUCT_VALUE_3, g_nStringIdmember), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdUSINT2USINT, g_nStringIdOUT), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdF_EQ, g_nStringIdIN1), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdGET_STRUCT_VALUE_2, g_nStringIdoutput), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdUSINT2USINT, g_nStringIdIN), 5},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdStruct_Message), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdGET_STRUCT_VALUE_2, g_nStringIdin_struct), 0},
};

const SCFB_FBFannedOutConnectionData FORTE_ContentFilter::scm_astFannedOutDataConnections[] = {
  {6, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdGET_STRUCT_VALUE_3, g_nStringIdin_struct), 2},
};

const SCFB_FBNData FORTE_ContentFilter::scm_stFBNData = {
  6, scm_astInternalFBs,
  6, scm_astEventConnections,
  1, scm_astFannedOutEventConnections,
  7, scm_astDataConnections,
  1, scm_astFannedOutDataConnections,
  3, scm_astParamters
};



