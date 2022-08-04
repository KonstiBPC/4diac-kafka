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

#include "forte_spinner.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "forte_spinner_gen.cpp"
#endif

DEFINE_FIRMWARE_DATATYPE(spinner, g_nStringIdspinner);

CIEC_spinner::CIEC_spinner() :
    CIEC_STRUCT(g_nStringIdspinner, 4, scmElementTypes, scmElementNames, e_APPLICATION + e_CONSTRUCTED + 1) {
}

const CStringDictionary::TStringId CIEC_spinner::scmElementNames[] = {g_nStringIdname, g_nStringIdid, g_nStringIdcolour, g_nStringIdcurrent_pos};
const CStringDictionary::TStringId CIEC_spinner::scmElementTypes[] = {g_nStringIdSTRING, g_nStringIdINT, g_nStringIdSTRING, g_nStringIdUSINT};


