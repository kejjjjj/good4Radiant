


#include "h.h"

void __fastcall test(rad::ccamwnd* pThis, [[maybe_unused]]void* edx, UINT nFlags, CPoint point)
{
	std::cout << "yo!\n";
	
	f_OnLButtonDown(pThis, nFlags, point);
}
typedef  void(__thiscall* CamWnd__DropModelsToPlane_t)(rad::ccamwnd*, int x, int y, int buttons);
const auto CamWnd__DropModelsToPlane = reinterpret_cast<CamWnd__DropModelsToPlane_t>(0x403D30);
void __fastcall rad::ccamwnd::on_lbutton_down(ccamwnd* pThis,  void* edx, UINT nFlags, CPoint point)
{
	//HWND v4; // eax
	//HWND__* v5; // [esp-8h] [ebp-28h]


	//v5 = pThis->m_hWnd;
	pThis->m_ptLastCursor = point;
	//GetClientRect(v5, &Rect);
	SetFocus(pThis->GetWindow());
	SetCapture(pThis->GetWindow());

	CamWnd__DropModelsToPlane(pThis, pThis->m_ptLastCursor.x, pThis->camera.height - pThis->m_ptLastCursor.y - 1, nFlags);

	HandleKeyIO(rad::dx->windows[0].hwnd, WM_LBUTTONDOWN);
}
