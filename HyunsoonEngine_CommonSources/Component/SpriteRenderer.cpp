#include "Component/SpriteRenderer.h"
#include "Component/Transform.h"
#include "GameObject/GameObject.h"
#include "Renderer.h"
#include "Application.h"

extern hs::Application app;

namespace hs
{
	SpriteRenderer::SpriteRenderer()
		: Component(enums::eComponentType::SpriteRenderer)
		, mTexture(nullptr)
		, mScale(Vector2::One)
		, mbStretch(false)
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
		Vector2	   res = mTexture->GetResolution();
		Transform* transform = GetOwner()->GetComponent<Transform>();
		Vector2	   pos = transform->GetPosition();
		Vector2	   scale = transform->GetScale();
		// float	   rotation = transform->GetRotation();

		// camera
		if (renderer::mainCamera)
			pos = renderer::mainCamera->CalculatePosition(pos);

		float renderWidth = res.x * mScale.x * scale.x;
		float renderHeight = res.y * mScale.y * scale.y;

		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Bmp)
		{
			if (mTexture->IsAlpha())
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

				AlphaBlend(hdc, std::round(pos.x - renderWidth), std::round(pos.y - renderHeight), renderWidth, renderHeight, mTexture->GetHdc(), 0, 0, res.x, res.y, func);
			}
			else
				TransparentBlt(hdc, std::round(pos.x - renderWidth), std::round(pos.y - renderHeight), renderWidth, renderHeight, mTexture->GetHdc(), 0, 0, res.x, res.y, RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Png)
		{
			// 투명화 시킬 픽셀의 색 범위
			Gdiplus::ImageAttributes imgAtt = {};
			imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphics(hdc);
			// graphics.TranslateTransform(pos.x, pos.y);
			// graphics.RotateTransform(rotation);
			// graphics.TranslateTransform(-pos.x, -pos.y);
			// graphics.DrawImage(mTexture->GetImage(), Gdiplus::Rect(pos.x, pos.y, res.x * mScale.x * scale.x, res.y * mScale.y * scale.y));
			if (mbStretch == false)
				graphics.DrawImage(mTexture->GetImage(), Gdiplus::Rect(std::round(pos.x - renderWidth), std::round(pos.y - renderHeight), renderWidth, renderHeight), 0, 0, res.x, res.y, Gdiplus::UnitPixel, nullptr /*&imgAtt*/);
			else
				StretchBlt(hdc, 0, 0, app.GetResolution().x, app.GetResolution().y, mTexture->GetHdc(), 0, 0, res.x, res.y, SRCCOPY);
		}
	}

	void SpriteRenderer::SetTexture(graphics::Texture* texture)
	{
		mTexture = texture;
	}

	void SpriteRenderer::SetScale(Vector2 scale)
	{
		mScale = scale;
	}

} // namespace hs
