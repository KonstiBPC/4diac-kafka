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

#ifndef _VIBRATOR_H_
#define _VIBRATOR_H_

#include "basicfb.h"
#include "forte_string.h"
#include "forte_array_at.h"
#include "ARTimeOut.h"


class FORTE_Vibrator: public CBasicFB {
  DECLARE_FIRMWARE_FB(FORTE_Vibrator)

private:
  
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  
  static const TEventID scm_nEventWRONG_CAP_ORIENTATIONID = 0;
  static const TEventID scm_nEventCAP_NOT_REACHABLEID = 1;
  
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];
  
  static const TEventID scm_nEventCAPS_FLIPPEDID = 0;
  static const TEventID scm_nEventCAPS_REACHABLEID = 1;
  
   static const TDataIOID scm_anEOWith[]; 
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];
  
  static const int scm_nTimerAdpNum = 0;
  
  static const SAdapterInstanceDef scm_astAdapterInstances[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

virtual void setInitialValues();
  CIEC_STRING &st_Status() {
    return *static_cast<CIEC_STRING*>(getDO(0));
  }
  
  FORTE_ARTimeOut& st_Timer() {
    return (*static_cast<FORTE_ARTimeOut*>(m_apoAdapters[0]));
  };
  

  void alg_alg_flip_init(void);
  void alg_alg_flip(void);
  void alg_alg_flip_exit(void);
  void alg_alg_separate_init(void);
  void alg_alg_separate(void);
  void alg_alg_separate_exit(void);

  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStates_Flip = 1;
  static const TForteInt16 scm_nStates_Separate = 2;
  static const TForteInt16 scm_nStates_Flip_done = 3;
  static const TForteInt16 scm_nStates_Seperate_done = 4;
  
  void enterStateSTART(void);
  void enterStates_Flip(void);
  void enterStates_Separate(void);
  void enterStates_Flip_done(void);
  void enterStates_Seperate_done(void);

  virtual void executeEvent(int pa_nEIID);

  FORTE_BASIC_FB_DATA_ARRAY(2, 0, 1, 0, 1);

public:
  FORTE_Vibrator(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
      CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, nullptr, m_anFBConnData, m_anFBVarsData) {
  };

  virtual ~FORTE_Vibrator() = default;
};

#endif // _VIBRATOR_H_


