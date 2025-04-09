#include "UIBase.h"

namespace hs
{
	UIBase::UIBase(eUIType type)
		: mType(type)
		, mbMouseOn(false)
	{
	}

	UIBase::~UIBase()
	{
	}

	void UIBase::Initialize()
	{
		OnInit();
	}

	void UIBase::Active()
	{
		mbEnabled = true;
		OnActive();
	}

	void UIBase::Inactive()
	{
		mbEnabled = false;
		OnInactive();
	}

	void UIBase::Update()
	{
		if (mbEnabled)
			OnUpdate();
	}

	void UIBase::LateUpdate()
	{
		if (mbEnabled)
			OnLateUpdate();
	}

	void UIBase::Render(HDC& hdc)
	{
		if (mbEnabled)
			OnRender(hdc);
	}

	void UIBase::UIClear()
	{
		OnClear();
	}

	void UIBase::OnInit()
	{
	}

	void UIBase::OnActive()
	{
	}

	void UIBase::OnInactive()
	{
	}

	void UIBase::OnUpdate()
	{
	}

	void UIBase::OnLateUpdate()
	{
	}

	void UIBase::OnRender(HDC& hdc)
	{
	}

	void UIBase::OnClear()
	{
	}

} // namespace hs