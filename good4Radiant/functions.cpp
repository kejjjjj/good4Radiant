#include "d3dsetup.h"
#include "structs.h"

namespace game
{
	game::selbrush_def_t* g_active_brushes()
	{
		const auto brush = reinterpret_cast<game::selbrush_def_t*>(*game::active_brushes_ptr);
		return brush;
	}

	game::selbrush_def_t* g_active_brushes_next()
	{
		const auto brush = reinterpret_cast<game::selbrush_def_t*>(*game::active_brushes_next_ptr);
		return brush;
	}

	game::selbrush_def_t* g_selected_brushes()
	{
		const auto brush = reinterpret_cast<game::selbrush_def_t*>(*game::currSelectedBrushes);
		return brush;
	}

	game::selbrush_def_t* g_selected_brushes_next()
	{
		const auto brush = reinterpret_cast<game::selbrush_def_t*>(*(DWORD*)0x23F1868);
		return brush;
	}
	game::selface_t* g_selected_faces()
	{
		const auto selfaces = reinterpret_cast<game::selface_t*>(*(DWORD*)0x73C710);
		return selfaces;
	}
}