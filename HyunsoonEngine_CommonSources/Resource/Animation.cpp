﻿#include "Animation.h"
#include "Component/Animator.h"
#include "Time.h"
#include "Component/Transform.h"
#include "GameObject/GameObject.h"
#include "Renderer.h"
#include "Component/Camera.h"

namespace hs
{
	Animation::Animation()
		: Resource(enums::eResourceType::Animation)
		, mAnimator(nullptr)
		, mTexture(nullptr)
		, mAnimationSheet{}
		, mIndex(-1)
		, mTime(0.0f)
		, mbComplete(false)
	{
	}

	Animation::~Animation()
	{
	}

	HRESULT Animation::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}

	void Animation::Update()
	{
		if (mbComplete)
			return;

		mTime += TimeUtils::GetDeltaTime();

		if (mAnimationSheet[mIndex].duration < mTime)
		{
			mTime = 0.0f;
			if (mIndex < mAnimationSheet.size() - 1)
				mIndex++;
			else
				mbComplete = true;
		}
	}

	void Animation::Render(HDC& hdc)
	{
		if (mTexture == nullptr)
			return;

		GameObject* gameObj = mAnimator->GetOwner();
		Transform*	tr = gameObj->GetComponent<Transform>();
		Vector2		pos = tr->GetPosition();
		// float		rot = tr->GetRotation();
		Vector2 scale = tr->GetScale();

		// camera
		if (renderer::mainCamera)
			pos = renderer::mainCamera->CalculatePosition(pos);

		Sprite sprite = mAnimationSheet[mIndex];
		HDC	   imgHdc = mTexture->GetHdc();

		float renderWidth = sprite.size.x * scale.x;
		float renderHeight = sprite.size.y * scale.y;

		// debug
		// Rectangle(hdc, std::round(pos.x) - renderWidth, std::round(pos.y) - renderHeight, std::round(pos.x), std::round(pos.y));

		graphics::Texture::eTextureType type = mTexture->GetTextureType();
		if (type == graphics::Texture::eTextureType::Bmp)
		{
			if (mTexture->IsAlpha())
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

				AlphaBlend(hdc, std::round(pos.x - renderWidth), std::round(pos.y - renderHeight), renderWidth, renderHeight, imgHdc, sprite.leftTop.x, sprite.leftTop.y, sprite.size.x, sprite.size.y, func);
			}
			else
			{
				TransparentBlt(hdc, std::round(pos.x - renderWidth), std::round(pos.y - renderHeight), renderWidth, renderHeight, imgHdc, sprite.leftTop.x, sprite.leftTop.y, sprite.size.x, sprite.size.y, RGB(255, 0, 255));
			}
		}
		else if (type == graphics::Texture::eTextureType::Png)
		{
			// 1.
			BLENDFUNCTION func = {};
			func.BlendOp = AC_SRC_OVER;
			func.BlendFlags = 0;
			func.AlphaFormat = AC_SRC_ALPHA;
			func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

			Sprite sprite = mAnimationSheet[mIndex];
			HDC	   imgHdc = mTexture->GetHdc();

			AlphaBlend(hdc, std::round(pos.x - renderWidth), std::round(pos.y - renderHeight), renderWidth, renderHeight, imgHdc, sprite.leftTop.x, sprite.leftTop.y, sprite.size.x, sprite.size.y, func);

			// 2.
			// 내가 원하는 픽셀을 투명화 시킬
			// Gdiplus::ImageAttributes imgAtt = {};
			//// 투명화 시킬 픽셀의 색 범위
			// imgAtt.SetColorKey(Gdiplus::Color(255, 255, 255), Gdiplus::Color(255, 255, 255));
			// Gdiplus::Graphics graphics(hdc);
			// graphics.TranslateTransform(pos.x, pos.y);
			// graphics.RotateTransform(rot);
			// graphics.TranslateTransform(-pos.x, -pos.y);
			// graphics.DrawImage(mTexture->GetImage(), Gdiplus::Rect(pos.x - (sprite.size.x / 2.0f), pos.y - (sprite.size.y / 2.0f), sprite.size.x, sprite.size.y), sprite.leftTop.x, sprite.leftTop.y, sprite.size.x, sprite.size.y, Gdiplus::UnitPixel, /*&imgAtt*/ nullptr);
		}
	}

	void Animation::CreateAnimation(const std::wstring& name, graphics::Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLegth, float duration)
	{
		mTexture = spriteSheet;
		for (size_t i = 0; i < spriteLegth; i++)
		{
			Sprite sprite = {};
			sprite.leftTop.x = leftTop.x + (size.x * i);
			sprite.leftTop.y = leftTop.y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;

			mAnimationSheet.push_back(sprite);
		}
	}

	void Animation::Reset()
	{
		mTime = 0.0f;
		mIndex = 0;
		mbComplete = false;
	}
	const Vector2 Animation::GetCenterOffset() const
	{
		return mAnimationSheet[mIndex].size / -2.0f;
	}
} // namespace hs
