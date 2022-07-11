#pragma once

#include "h.h"

#ifndef radoffsets
#define radoffsets

namespace rad
{
	inline DxGlobals* dx = reinterpret_cast<DxGlobals*>(0x1365684);
	inline qeglobals_t* g_qeglobals = reinterpret_cast<qeglobals_t*>(0x25F39C0);
	inline r_globals_t* rg = reinterpret_cast<r_globals_t*>(0x13683F0);
	inline r_global_permanent_t* rgp = reinterpret_cast<r_global_permanent_t*>(0x136C700);
	inline GfxScene* scene = reinterpret_cast<GfxScene*>(0x1370980);
	inline GfxCmdBufSourceState* gfxCmdBufSourceState = reinterpret_cast<GfxCmdBufSourceState*>(0x174D760);
	inline GfxCmdBufState* gfxCmdBufState = reinterpret_cast<GfxCmdBufState*>(0x174E660);
	inline GfxCmdBufInput* gfxCmdBufInput = reinterpret_cast<GfxCmdBufInput*>(0x174F070);
	inline GfxBackEndData* gfx_frontend_data = reinterpret_cast<GfxBackEndData*>(0x73D480);
	inline GfxBackEndData* gfx_backend_data = reinterpret_cast<GfxBackEndData*>(0x73D500);
	inline GfxImage** imageGlobals = reinterpret_cast<GfxImage**>(0x14C6CF8);

	inline ComWorld* comworld = reinterpret_cast<ComWorld*>(0x241DDC8);
	inline GfxWorld* s_world = reinterpret_cast<GfxWorld*>(0x174F688);

	inline HWND* entitywnd_hwnds = reinterpret_cast<HWND*>(0x240A118);

	//CLayerDlg* layer_dlg = reinterpret_cast<CLayerDlg*>(0x25d6ea0);

	static DWORD* active_brushes_ptr = (DWORD*)(0x23F189C);
	static DWORD* active_brushes_next_ptr = (DWORD*)(0x23F18A0);
	static DWORD* currSelectedBrushes = (DWORD*)(0x23F1864); // (selected_brushes array pointer)
	static DWORD* worldEntity_ptr = (DWORD*)(0x25D5B30); // holds pointer to worldEntity
	static DWORD* g_pParentWnd_ptr = (DWORD*)(0x25D5A70);

	inline uint32_t* g_nUpdateBits = (uint32_t*)0x25D5A74;
	inline float gridSizes[12];
	
}

#endif