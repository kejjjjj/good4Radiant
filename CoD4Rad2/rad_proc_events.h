#pragma once

#ifndef radprocs
#define radprocs

#include "h.h"

void __fastcall test(rad::ccamwnd* pThis, [[maybe_unused]]void* edx, UINT nFlags, CPoint point);

typedef void(__thiscall* on_ccamwnd_msg)(rad::ccamwnd*, UINT, CPoint);

inline char (*f_OnLButtonDown)(rad::ccamwnd* pThis, UINT nFlags, CPoint point) = (char(__cdecl*)(rad::ccamwnd * , UINT , CPoint ))0x00403160;
inline void* (*f_SetFocus)(void* ok) = (void* (__cdecl*)(void* ok))0x058EAAC;
inline void* (*f_FromHandle)(HWND hwnd) = (void*(__cdecl*)(HWND))0x5871BD;
inline void (*f_CamWnd_DropModelsToPlane)(void* dis, int x, int y, int nFlags) = (void(__cdecl*)(void* dis, int x, int y, int nFlags))0x403D30;

#endif