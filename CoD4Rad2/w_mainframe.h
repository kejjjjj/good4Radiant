#pragma once

#ifndef surfins
#define surfins

#include "h.h"

typedef void(__fastcall* MainFrame_OnKeyDown_hook)(void* mainframe, uint32_t nChar, uint32_t nRepCnt, uint32_t nFlags);
inline MainFrame_OnKeyDown_hook MainFrame_OnKeyDown_f;

void __fastcall MainFrame_OnKeyDown(void* mainframe, uint32_t nChar, uint32_t nRepCnt, uint32_t nFlags);
inline void (__cdecl*MainFrame_Nudge)(int Dir, float fNudge) = (void(__cdecl*)(int, float))0x4298B0;

#endif