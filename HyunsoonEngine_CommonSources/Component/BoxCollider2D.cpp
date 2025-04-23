#include "Component/BoxCollider2D.h"
#include "Component/Animator.h"
#include "Component/Transform.h"
#include "GameObject/GameObject.h"
#include "Renderer.h"
#include "Camera.h"

namespace hs
{
	BoxCollider2D::BoxCollider2D()
		: Collider(enums::eColliderType::Rect2D)
	{
	}

	BoxCollider2D::~BoxCollider2D()
	{
	}

	void BoxCollider2D::Update()
	{
		Animator* animator = GetOwner()->GetComponent<Animator>();
		if (animator)
			SetSize(animator->GetAnimationSize());
	}

	void BoxCollider2D::LateUpdate()
	{
	}

	void BoxCollider2D::Render(HDC& hdc)
	{
		//// debug
		 /*Transform* tr = GetOwner()->GetComponent<Transform>();
		 Vector2	   pos = tr->GetPosition();

		
		 if (renderer::mainCamera)
			pos = renderer::mainCamera->CalculatePosition(pos);

		 Vector2 offset = GetOffset();

		 HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		 HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

		 HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		 HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);

		 Rectangle(hdc, pos.x + offset.x - GetSize().x, pos.y + offset.y - GetSize().y, pos.x + offset.x, pos.y + offset.y);

		 SelectObject(hdc, oldBrush);
		 SelectObject(hdc, oldPen);
		 DeleteObject(greenPen);*/
	}
} // namespace hs
