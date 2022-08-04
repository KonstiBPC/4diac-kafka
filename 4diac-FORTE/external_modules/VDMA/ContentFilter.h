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

#ifndef _CONTENTFILTER_H_
#define _CONTENTFILTER_H_

#include "cfb.h"
#include "typelib.h"
#include "forte_bool.h"
#include "forte_string.h"
#include "forte_spinner.h"
#include "forte_array_at.h"


class FORTE_ContentFilter: public CCompositeFB {
  DECLARE_FIRMWARE_FB(FORTE_ContentFilter)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  
  static const TEventID scm_nEventREQID = 0;
  
   static const TDataIOID scm_anEIWith[];
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];
  
  static const TEventID scm_nEventCNFID = 0;
  
   static const TDataIOID scm_anEOWith[]; 
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];
  

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

  static const SCFB_FBInstanceData scm_astInternalFBs[];
  static const SCFB_FBParameter scm_astParamters[];
  static const SCFB_FBConnectionData scm_astEventConnections[];
  static const SCFB_FBFannedOutConnectionData scm_astFannedOutEventConnections[];
  static const SCFB_FBConnectionData scm_astDataConnections[];
  static const SCFB_FBFannedOutConnectionData scm_astFannedOutDataConnections[];
  static const SCFB_FBNData scm_stFBNData;

  CIEC_spinner &st_Struct_Message() {
    return *static_cast<CIEC_spinner*>(getDI(0));
  }
  
  CIEC_STRING &st_Filter_name() {
    return *static_cast<CIEC_STRING*>(getDI(1));
  }
  
  CIEC_BOOL &st_Error() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  }
  
  CIEC_STRING &st_New_Value() {
    return *static_cast<CIEC_STRING*>(getDO(1));
  }
  

  FORTE_FB_DATA_ARRAY(1, 2, 2, 0);

public:
  FORTE_ContentFilter(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
      CCompositeFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, &scm_stFBNData, m_anFBConnData, m_anFBVarsData) {
  };

  virtual ~FORTE_ContentFilter() = default;
};

#endif // _CONTENTFILTER_H_


