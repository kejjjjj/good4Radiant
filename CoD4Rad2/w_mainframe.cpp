
#include "h.h"

void __fastcall MainFrame_OnKeyDown(void* mainframe, uint32_t nChar, uint32_t nRepCnt, uint32_t nFlags)
{
	std::cout << "key[" << (char)nChar << "]\n";

	if (nChar == 'S') { //S is the new hotkey for scaling
		switch (r::mCurrentGizmoOperation)
		{
		case ImGuizmo::OPERATION::TRANSLATE:
			r::mCurrentGizmoOperation = ImGuizmo::OPERATION::SCALE;
			break;
		case ImGuizmo::OPERATION::SCALE:
			r::mCurrentGizmoOperation = ImGuizmo::OPERATION::TRANSLATE;
			break;
		default:
			r::mCurrentGizmoOperation = ImGuizmo::OPERATION::TRANSLATE;
			break;
		}
		return;
	}
	if (nChar == 'O') { //O is the new hotkey for surf inspector

		nChar == 'S';
		nRepCnt = 'S';
		nFlags = 1;
	}


	return MainFrame_OnKeyDown_f(mainframe, nChar, nRepCnt, nFlags);
}