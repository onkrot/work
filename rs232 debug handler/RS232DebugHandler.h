/*
 * RS232DebugHandler.h
 *
 *  Created on: 13 ��� 2019 �.
 *      Author: Developer
 */
#pragma once

#include "CoreConfig.h"
#include "Core/System/Debug/print.h"
#include "Core/System/Utils/SafeString.h"
#include "Core/Internal_periferial/RS232/RS232.h"

class RS232DebugHandler : public IDebugHandler
{
	SerialPortHandle _port;
  public:
	RS232DebugHandler(SerialPortHandle port);
	//! ���� �� �������� ����������� ��� ����� ������?
	bool channelIsActive(DiSw numchan) const;

	//! ����������� ����������� ����� ���� ����������
	void print(DiSw numchan, const char* msg);
};

namespace RS232Debug
{
	class Handler : public SerialPortHandler
	{
		SerialPortHandle _port;
		DiSw _msgType;
		RS232DebugHandler *handler = nullptr;

	  public:
		Handler(SerialPortHandle port, DiSw msgType);

		size_t handle();

		static uint32_t value;
	};
}
