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

#ifndef _BUNKER_H_
#define _BUNKER_H_

#include "basicfb.h"
#include "forte_string.h"
#include "forte_array_at.h"
#include "ARTimeOut.h"


class FORTE_Bunker: public CBasicFB {
  DECLARE_FIRMWARE_FB(FORTE_Bunker)

private:
  
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  
  static const TEventID scm_nEventDESIRED_COLOUR_CAP_NOT_AVAILABLEID = 0;
  
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];
  
  static const TEventID scm_nEventMORE_CAPS_AVAILABLEID = 0;
  
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
  

  void alg_alg_init(void);
  void alg_alg_feeding(void);
  void alg_alg_feed_done(void);
  void alg_alg_no_cap_alarm(void);

  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStates_feed = 1;
  static const TForteInt16 scm_nStateState = 2;
  static const TForteInt16 scm_nStates_init = 3;
  
  void enterStateSTART(void);
  void enterStates_feed(void);
  void enterStateState(void);
  void enterStates_init(void);

  virtual void executeEvent(int pa_nEIID);

  FORTE_BASIC_FB_DATA_ARRAY(1, 0, 1, 0, 1);

public:
  FORTE_Bunker(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
      CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, nullptr, m_anFBConnData, m_anFBVarsData) {
  };

  virtual ~FORTE_Bunker() = default;
};

#endif // _BUNKER_H_


