#pragma once

#ifndef radentry
#define radentry

#include "h.h"

namespace rad
{
	void CG_DllEntry(HMODULE hModule, LPTHREAD_START_ROUTINE startAddr);
	void Rad_ExternalMsgHandler();
}

#endif