#include "Npc.h"

namespace hs
{

	Npc::Npc(Vector2 pos)
		: GameObject(eLayerType::Npc)
	{
	}

	Npc::~Npc()
	{
	}

	void Npc::Update()
	{
	}

	void Npc::LateUpdate()
	{
	}

	void Npc::Render(HDC& hdc)
	{
		// int	   color = RGB(0, 255, 0);
		// HBRUSH newBrush = CreateSolidBrush(color);
		// HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, newBrush);

		// HPEN newPen = CreatePen(PS_SOLID, 2, color);
		// HPEN oldPen = (HPEN)SelectObject(hdc, newPen);

		// Rectangle(hdc, 100.0f + mPos.x, 100.0f + mPos.y, 200.0f + mPos.x, 200.0f + mPos.y);

		// SelectObject(hdc, oldBrush);
		// SelectObject(hdc, oldPen);
		// DeleteObject(newBrush);
		// DeleteObject(newPen);
	}

	void Npc::showDialogue()
	{
	}
} // namespace hs