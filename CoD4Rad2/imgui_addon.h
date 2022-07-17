#pragma once

#ifndef imaddd
#define imaddd

#include "h.h"

struct ImGui_ImplWin32_Data // he
{
	HWND                        hWnd;
	HWND                        MouseHwnd;
	bool                        MouseTracked;
	int                         MouseButtonsDown;
	INT64                       Time;
	INT64                       TicksPerSecond;
	ImGuiMouseCursor            LastMouseCursor;
	bool                        HasGamepad;
	bool                        WantUpdateHasGamepad;
	bool                        WantUpdateMonitors;
};

void	HandleKeyIO(HWND hwnd, UINT key, SHORT zDelta = 0, UINT nChar = 0);
static ImGuiKey ImGui_ImplWin32_VirtualKeyToImGuiKey(WPARAM wParam);
static void ImGui_ImplWin32_AddKeyEvent(ImGuiKey key, bool down, int native_keycode, int native_scancode = -1);
static bool IsVkDown(int vk);
#endif