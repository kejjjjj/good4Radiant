#pragma once

#ifndef h_h_h
#define h_h_h

#pragma warning(disable: 26495)
#define PI 3.14159265f
typedef float vec_t;
typedef vec_t vec2_t[2];
typedef vec_t vec3_t[3];
typedef vec_t vec4_t[4];

#define ASSERT_MSG(expr, msg) assert((msg, expr))
#define STRINGIZE_(x) #x
#define STRINGIZE(x) STRINGIZE_(x)
#define AssertSize(x, size)								static_assert(sizeof(x) == size, STRINGIZE(x) " structure has an invalid size.")
#define STATIC_ASSERT_SIZE(struct, size)				static_assert(sizeof(struct) == size, "Size check")
#define STATIC_ASSERT_OFFSET(struct, member, offset)	static_assert(offsetof(struct, member) == offset, "Offset check")

#define PITCH 0
#define YAW 1
#define ROLL 2

#define MENU_KEY VK_HOME


#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <direct.h>
#include <thread>
#include <TlHelp32.h>
#include <psapi.h>
#include <corecrt_math.h>
#include <corecrt_math_defines.h>

typedef tagPOINT CPoint;

//detours
#include "detours/detours.h"
#pragma comment(lib, "detours.lib")

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

//DIRECTX
#include <d3d9.h>
#include <d3dx9.h>
#include <d3dx9core.h>


//IMGUI
#include "../good4radiant\CoD4Rad2/imGui/imgui.h"
#include "../good4radiant\CoD4Rad2/imGui/imgui_impl_dx9.h"
#include "../good4radiant\CoD4Rad2/imGui/imgui_impl_win32.h"
#include "../good4radiant\CoD4Rad2/imGui/imgui_internal.h"

#include "../good4radiant\CoD4Rad2/imGui/ImGuizmo.h"
#include "../good4radiant\CoD4Rad2/imGui/ImSequencer.h"
#include "../good4radiant\CoD4Rad2/imGui/ImZoomSlider.h"
#include "../good4radiant\CoD4Rad2/imGui/ImCurveEdit.h"
#include "../good4radiant\CoD4Rad2/imGui/GraphEditor.h"

namespace fs = std::filesystem;
using namespace std::chrono_literals;

#include "afx.h"

#include "D:\what\aavikko\aavikko\koukku.h"
#include "rad_local.h"
#include "rad_offsets.h"
#include "rad_functions.h"
#include "rad_entrypoint.h"
#include "rad_vars.h"

#include "r_init.h"
#include "r_ui.h"
#include "r_quizmo.h"
#include "r_3d.h"
#include "r_on_camera.h"

#include "w_mainframe.h"

#include "math.h"
#include "matrix.h"
#include "vector.h"

#include "r_wnd.h"

#include "imgui_addon.h"
#include "rad_proc_events.h"

#endif