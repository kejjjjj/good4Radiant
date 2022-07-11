#include "hooks.h"
namespace hooks
{
	void NOP(DWORD address, size_t bytes) {
		BYTE NOPPED[5] = { 0x90, 0x90, 0x90, 0x90, 0x90 };
		WriteProcessMemory(GetCurrentProcess(), (void*)(address), &NOPPED, bytes, 0);
	}
	void modMemory(DWORD address, BYTE byteVal[], size_t bytes)
	{
		WriteProcessMemory(GetCurrentProcess(), (void*)(address), byteVal, bytes, 0);
	}
}
namespace game
{
	void Hooks() {
		hooks::NOP(0x4FD417, 5); //call va for release hooks
		hooks::NOP(0x4FD433, 5); //release leaks

		hooks::NOP(0x4FD50F, 5); //call va for release hooks
		hooks::NOP(0x4FD52B, 5); //release leaks
		hooks::NOP(0x53B2C3, 5); //shader constants

	}
}