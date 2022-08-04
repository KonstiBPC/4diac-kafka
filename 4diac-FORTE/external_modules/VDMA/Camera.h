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

#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "basicfb.h"
#include "forte_sint.h"
#include "forte_string.h"
#include "forte_array_at.h"


class FORTE_Camera: public CBasicFB {
  DECLARE_FIRMWARE_FB(FORTE_Camera)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  
  static const TEventID scm_nEventCAP_REQUIREDID = 0;
  static const TEventID scm_nEventBUNKER_FEED_CAPSID = 1;
  static const TEventID scm_nEventVIBRATOR_ORIENTED_CORRECTID = 2;
  static const TEventID scm_nEventVIBRATOR_CAP_REACHABLEID = 3;
  
   static const TDataIOID scm_anEIWith[];
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];
  
  static const TEventID scm_nEventDESIRED_COLOR_CAP_NOT_AVAILABLEID = 0;
  static const TEventID scm_nEventWRONG_CAP_ORIENTATIONID = 1;
  static const TEventID scm_nEventCAP_NOT_REACHANBLEID = 2;
  static const TEventID scm_nEventCAP_RECHANBLEID = 3;
  
   static const TDataIOID scm_anEOWith[]; 
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];
  

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

virtual void setInitialValues();
  CIEC_STRING &st_Product_Color() {
    return *static_cast<CIEC_STRING*>(getDI(0));
  }
  
  CIEC_SINT &st_Pick_Pos_X() {
    return *static_cast<CIEC_SINT*>(getDO(0));
  }
  
  CIEC_SINT &st_Pick_Pos_Y() {
    return *static_cast<CIEC_SINT*>(getDO(1));
  }
  
  CIEC_SINT &st_Pick_Pos_Z() {
    return *static_cast<CIEC_SINT*>(getDO(2));
  }
  

  void alg_alg_find_object(void);

  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStates_find_Object = 1;
  static const TForteInt16 scm_nStates_Bunker_Adding_more_Caps = 2;
  static const TForteInt16 scm_nStates_vibrator_worked = 3;
  static const TForteInt16 scm_nStates_Cap_not_Reachable = 4;
  
  void enterStateSTART(void);
  void enterStates_find_Object(void);
  void enterStates_Bunker_Adding_more_Caps(void);
  void enterStates_vibrator_worked(void);
  void enterStates_Cap_not_Reachable(void);

  virtual void executeEvent(int pa_nEIID);

  FORTE_BASIC_FB_DATA_ARRAY(4, 1, 3, 0, 0);

public:
  FORTE_Camera(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
      CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, nullptr, m_anFBConnData, m_anFBVarsData) {
  };

  virtual ~FORTE_Camera() = default;
};

#endif // _CAMERA_H_


