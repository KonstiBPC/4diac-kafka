/*******************************************************************************
 * Copyright (c) 2010, 2011 ACIN and Profactor GmbH.
 *     
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0  
 *
 * Contributors:
 *    Alois Zoitl - initial implementation and rework communication infrastructure
 *    Ingo Hegny - moved encoding of adapter-event-ids to a single point
 *    Michael Hofmann - rework communication infrastructure
 *******************************************************************************/

#include <fortenew.h>
#include "comlayersmanager.h"
#include <string.h>

#include<ipcomlayer.h>
#include<fbdkasn1layer.h>
#include<localcomlayer.h>
#include<rawdatacomlayer.h>
#include<KafkaComLayer.h>
#include<fbdkSelectLayer.h>


using namespace forte::com_infra;

CComLayer* CComLayersManager::createCommunicationLayer(char *pa_acLayerIdentifier, CComLayer* pa_poUpperLayer, CBaseCommFB * pa_poComFB){
  CComLayer* m_poNewLayer = 0;
  if(0 == strcmp("ip", pa_acLayerIdentifier)){
    m_poNewLayer = new CIPComLayer(pa_poUpperLayer, pa_poComFB);
  }
  else if(0 == strcmp("fbdk", pa_acLayerIdentifier)){
    m_poNewLayer = new CFBDKASN1ComLayer(pa_poUpperLayer, pa_poComFB);
  }
  else if(0 == strcmp("loc", pa_acLayerIdentifier)){
    m_poNewLayer = new CLocalComLayer(pa_poUpperLayer, pa_poComFB);
  }
  else if(0 == strcmp("raw", pa_acLayerIdentifier)){
    m_poNewLayer = new CRawDataComLayer(pa_poUpperLayer, pa_poComFB);
  }
  else if(0 == strcmp("kafka", pa_acLayerIdentifier)){
    m_poNewLayer = new KafkaComLayer(pa_poUpperLayer, pa_poComFB);
  }
  else if(0 == strcmp("fbdkSel", pa_acLayerIdentifier)){
    m_poNewLayer = new fbdkSelectLayer(pa_poUpperLayer, pa_poComFB);
  }


  return m_poNewLayer;
}
