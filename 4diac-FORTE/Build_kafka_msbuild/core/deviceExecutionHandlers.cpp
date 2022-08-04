/*******************************************************************************
 * Copyright (c) 2017 fortiss GmbH 
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *    Jose Cabral - initial implementation and rework handler infrastructure
 *******************************************************************************/

#include <timerha.h>
#include <devexec.h>

#include <sockhand.h>
#include <KafkaHandler.h>


const size_t CTimerHandler::mHandlerIdentifier = 0;
const size_t CFDSelectHandler::mHandlerIdentifier = 1;
const size_t KafkaHandler::mHandlerIdentifier = 2;
 

void CDeviceExecution::createHandlers(CDeviceExecution& paDeviceExecution){

  paDeviceExecution.mRegisteredEventHandlers[0].mHandler = CTimerHandler::createTimerHandler(paDeviceExecution);
  paDeviceExecution.mRegisteredEventHandlers[1].mHandler = new CFDSelectHandler(paDeviceExecution);
  paDeviceExecution.mRegisteredEventHandlers[2].mHandler = new KafkaHandler(paDeviceExecution);

}
