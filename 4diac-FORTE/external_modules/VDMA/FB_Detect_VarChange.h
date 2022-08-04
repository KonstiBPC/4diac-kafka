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

#ifndef _FB_DETECT_VARCHANGE_H_
#define _FB_DETECT_VARCHANGE_H_

#include "simplefb.h"
#include "forte_bool.h"
#include "forte_usint.h"
#include "forte_array_at.h"


class FORTE_FB_Detect_VarChange: public CSimpleFB {
  DECLARE_FIRMWARE_FB(FORTE_FB_Detect_VarChange)

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
static const CStringDictionary::TStringId scm_anInternalsNames[];
static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
static const SInternalVarsInformation scm_stInternalVars;

virtual void setInitialValues();
          CIEC_USINT &st_IN_Var() {
            return *static_cast<CIEC_USINT*>(getDI(0));
          }
          
  CIEC_USINT &st_OUT_Var() {
    return *static_cast<CIEC_USINT*>(getDO(0));
  }
  
  CIEC_BOOL &st_Changed() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
  }
  
  CIEC_BOOL &st_iValue_Changed() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(0));
  }
  

  void alg_REQ(void);

  FORTE_BASIC_FB_DATA_ARRAY(1, 1, 2, 1, 0);

public:
  FORTE_FB_Detect_VarChange(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
       CSimpleFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, &scm_stInternalVars, m_anFBConnData, m_anFBVarsData) {
  };

  virtual ~FORTE_FB_Detect_VarChange() = default;
};

#endif // _FB_DETECT_VARCHANGE_H_


