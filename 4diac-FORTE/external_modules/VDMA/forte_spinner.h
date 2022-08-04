/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: spinner
 *** Description: Reponse sent by the orchestrator
 *** Version:
***     1.0: 2018-09-26/Jose Cabral - fortiss GmbH - 
 *************************************************************************/

#ifndef _SPINNER_H_
#define _SPINNER_H_

#include "forte_struct.h"

#include "forte_int.h"
#include "forte_string.h"
#include "forte_usint.h"
#include "forte_array_at.h"


class CIEC_spinner: public CIEC_STRUCT {
  DECLARE_FIRMWARE_DATATYPE(spinner)

  public:
      CIEC_spinner();

      virtual ~CIEC_spinner() {
      }

          CIEC_STRING &name() {
            return *static_cast<CIEC_STRING*>(getMember(0));
          }
          
          CIEC_INT &id() {
            return *static_cast<CIEC_INT*>(getMember(1));
          }
          
          CIEC_STRING &colour() {
            return *static_cast<CIEC_STRING*>(getMember(2));
          }
          
          CIEC_USINT &current_pos() {
            return *static_cast<CIEC_USINT*>(getMember(3));
          }
          

  private:
    static const CStringDictionary::TStringId scmElementTypes[];
    static const CStringDictionary::TStringId scmElementNames[];

};

#endif // _SPINNER_H_


