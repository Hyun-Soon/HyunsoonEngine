#include "SpriteRenderer.h"
#include "Component/Transform.h"
#include "GameObject.h"
#include <iostream>

namespace hs
{
	SpriteRenderer::SpriteRenderer()
		: mImage(nullptr)
		, mWidth(0)
		, mHeight(0)
	{
	}

	SpriteRenderer::~SpriteRenderer()
	{
	}

	void SpriteRenderer::Initialize()
	{
	}

	void SpriteRenderer::Update()
	{
	}

	void SpriteRenderer::LateUpdate()
	{
	}

	void SpriteRenderer::Render(HDC& hdc)
	{
		Transform*		  transform = GetOwner()->GetComponent<Transform>(L"Transform");
		Vector2			  pos = transform->GetPosition();
		Gdiplus::Graphics graphcis(hdc);
		graphcis.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));
	}

	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{
		mImage = Gdiplus::Image::FromFile(path.c_str());
		if (!mImage)
		{
			OutputDebugString(L"is null!\n");
		}

		mWidth = mImage->GetWidth();
		mHeight = mImage->GetHeight();
	}
} // namespace hs
