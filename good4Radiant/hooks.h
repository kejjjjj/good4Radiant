#pragma once
#include "d3dsetup.h"
namespace hooks
{
	extern void NOP(DWORD address, size_t bytes);
	extern void modMemory(DWORD address, BYTE byteVal[], size_t bytes);
}
namespace game
{
	void Hooks();
}