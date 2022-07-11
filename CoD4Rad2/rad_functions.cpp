#include "h.h"


rad::selbrush_def_t* rad::g_active_brushes()
{
	const auto brush = reinterpret_cast<rad::selbrush_def_t*>(*rad::active_brushes_ptr);
	return brush;
}

rad::selbrush_def_t* rad::g_active_brushes_next()
{
	const auto brush = reinterpret_cast<rad::selbrush_def_t*>(*rad::active_brushes_next_ptr);
	return brush;
}

rad::selbrush_def_t* rad::g_selected_brushes()
{
	const auto brush = reinterpret_cast<rad::selbrush_def_t*>(*rad::currSelectedBrushes);
	return brush;
}

rad::selbrush_def_t* rad::g_selected_brushes_next()
{
	const auto brush = reinterpret_cast<rad::selbrush_def_t*>(*(DWORD*)0x23F1868);
	return brush;
}
rad::selface_t* rad::g_selected_faces()
{
	const auto selfaces = reinterpret_cast<rad::selface_t*>(*(DWORD*)0x73C710);
	return selfaces;
}
void rad::GetBrushOrigin(selbrush_def_t* brush, vec3_t out)
{
	brush_t_with_custom_def* def = brush->def;

	for (int i = 0; i < 3; i++)
		out[i] = def->mins[i] + (def->maxs[i] - def->mins[i]) / 2;

}
void rad::GetBrushBounds(selbrush_def_t* brush, vec3_t out)
{
	brush_t_with_custom_def* def = brush->def;

	for (int i = 0; i < 3; i++)
		out[i] = fabs(def->maxs[i] - def->mins[i]);
}