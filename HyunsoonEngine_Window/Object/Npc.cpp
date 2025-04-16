#include "../../HyunsoonEngine_Window/Object/Npc.h"
#include "Component/SpriteRenderer.h"
#include "Resource/ResourceManager.h"

namespace hs
{

	Npc::Npc()
		: GameObject()
	{
	}

	Npc::~Npc()
	{
	}

	void Npc::Initialize()
	{
		SetLayerType(enums::eLayerType::Npc);
		AddComponent<SpriteRenderer>();
	}

	void Npc::SetTexture(std::wstring texName)
	{
		graphics::Texture* tex = ResourceManager::Find<graphics::Texture>(texName);
		GetComponent<SpriteRenderer>()->SetTexture(tex);
	}

	// void Npc::Update()
	//{
	// }

	// void Npc::LateUpdate()
	//{
	// }

	// void Npc::Render(HDC& hdc)
	//{
	//	// int	   color = RGB(0, 255, 0);
	//	// HBRUSH newBrush = CreateSolidBrush(color);
	//	// HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, newBrush);

	//	// HPEN newPen = CreatePen(PS_SOLID, 2, color);
	//	// HPEN oldPen = (HPEN)SelectObject(hdc, newPen);

	//	// Rectangle(hdc, 100.0f + mPos.x, 100.0f + mPos.y, 200.0f + mPos.x, 200.0f + mPos.y);

	//	// SelectObject(hdc, oldBrush);
	//	// SelectObject(hdc, oldPen);
	//	// DeleteObject(newBrush);
	//	// DeleteObject(newPen);
	//}

	void Npc::showDialogue()
	{
	}
} // namespace hs