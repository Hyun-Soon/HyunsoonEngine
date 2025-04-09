#include "UIHUD.h"
#include "enums/Enums.h"
#include "Resource/ResourceManager.h"
#include "Application.h"

extern hs::Application app;

namespace hs
{
	UIHUD::UIHUD()
		: UIBase(enums::eUIType::BottomBar)
	{
	}

	UIHUD::~UIHUD()
	{
	}

	void UIHUD::OnInit()
	{
		mTexture = ResourceManager::Find<graphics::Texture>(L"BottomBar");
	}

	void UIHUD::OnActive()
	{
		// int* p = new int;
	}

	void UIHUD::OnInactive()
	{
	}

	void UIHUD::OnUpdate()
	{
	}

	void UIHUD::OnLateUpdate()
	{
	}

	void UIHUD::OnRender(HDC& hdc)
	{
		Vector2 appRes = app.GetResolution();
		Vector2 renderPos = appRes - mTexture->GetResolution();

		// BLENDFUNCTION func = {};
		// func.BlendOp = AC_SRC_OVER;
		// func.BlendFlags = 0;
		// func.AlphaFormat = AC_SRC_ALPHA;
		// func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)
		// AlphaBlend(hdc, renderPos.x, renderPos.y, mTexture->GetResolution().x, mTexture->GetResolution().y, mTexture->GetHdc(), 0, 0, mTexture->GetResolution().x, mTexture->GetResolution().y, func);
		TransparentBlt(hdc, 0, renderPos.y - 71, mTexture->GetResolution().x, mTexture->GetResolution().y, mTexture->GetHdc(), 0, 0, mTexture->GetResolution().x, mTexture->GetResolution().y, RGB(255, 0, 255));
	}

	void UIHUD::OnClear()
	{
		// delete p;
	}

} // namespace hs
