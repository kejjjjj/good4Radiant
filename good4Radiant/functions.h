#pragma once

#ifndef funcs
#define funcs

#include "d3dsetup.h"
#include "structs.h"

namespace game
{
	inline game::DxGlobals* dx = reinterpret_cast<game::DxGlobals*>(0x1365684);
	inline game::qeglobals_t* g_qeglobals = reinterpret_cast<game::qeglobals_t*>(0x25F39C0);
	inline game::r_globals_t* rg = reinterpret_cast<game::r_globals_t*>(0x13683F0);
	inline game::r_global_permanent_t* rgp = reinterpret_cast<game::r_global_permanent_t*>(0x136C700);
	inline game::GfxScene* scene = reinterpret_cast<game::GfxScene*>(0x1370980);
	inline game::GfxCmdBufSourceState* gfxCmdBufSourceState = reinterpret_cast<game::GfxCmdBufSourceState*>(0x174D760);
	inline game::GfxCmdBufState* gfxCmdBufState = reinterpret_cast<game::GfxCmdBufState*>(0x174E660);
	inline game::GfxCmdBufInput* gfxCmdBufInput = reinterpret_cast<game::GfxCmdBufInput*>(0x174F070);
	inline game::GfxBackEndData* gfx_frontend_data = reinterpret_cast<game::GfxBackEndData*>(0x73D480);
	inline game::GfxBackEndData* gfx_backend_data = reinterpret_cast<game::GfxBackEndData*>(0x73D500);


	static DWORD* active_brushes_ptr = (DWORD*)(0x23F189C);
	static DWORD* active_brushes_next_ptr = (DWORD*)(0x23F18A0);
	static DWORD* currSelectedBrushes = (DWORD*)(0x23F1864); // (selected_brushes array pointer)
	static DWORD* worldEntity_ptr = (DWORD*)(0x25D5B30); // holds pointer to worldEntity
	static DWORD* g_pParentWnd_ptr = (DWORD*)(0x25D5A70);

	extern game::selbrush_def_t* g_active_brushes();
	extern game::selbrush_def_t* g_active_brushes_next();
	extern game::selbrush_def_t* g_selected_brushes();
	extern game::selbrush_def_t* g_selected_brushes_next();
	extern game::selface_t* g_selected_faces();
}
#endif