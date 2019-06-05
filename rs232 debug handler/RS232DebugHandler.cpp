/*
 * RS232DebugHandler.cpp
 *
 *  Created on: 13 мая 2019 г.
 *      Author: Developer
 */

#include "Core/Internal_periferial/RS232/RS232.h"
#include "Core/System/allocator.h"
#include "RS232DebugHandler.h"
#include "Core/System/system.h"

RS232DebugHandler::RS232DebugHandler(SerialPortHandle port): _port(port)
{
}

bool RS232DebugHandler::channelIsActive(DiSw numchan) const
{
	return true;
}

void RS232DebugHandler::print(DiSw numchan, const char* msg)
{
	if(clearToSend(_port))
		SerialPutString(_port, msg);
}


//===================================================================
//                          Handler
//===================================================================
RS232Debug::Handler::Handler(SerialPortHandle port, DiSw msgType) : _port(port), _msgType(msgType)
{
	SerialInit(port, 115200, 10, UART_1_STOP_BIT, UART_8_BIT_CHAR, UART_NO_PARITY, UART_PACKET_MODE_OFF);
	delay(1000);
}
//===================================================================
size_t RS232Debug::Handler::handle()
{
	if(handler == nullptr)
	{
		handler = newnt RS232DebugHandler(_port);
		addDebugHandler(handler);
	}
	return 1000;
}
//===================================================================



