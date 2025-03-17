#include "Component/SpriteRenderer.h"
#include "Component/Transform.h"
#include "GameObject/GameObject.h"
#include "Renderer.h"

namespace hs
{
	SpriteRenderer::SpriteRenderer()
		: Component(enums::eComponentType::SpriteRenderer)
		, mTexture(nullptr)
		, mScale(Vector2::One)
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
		assert(mTexture);

		Transform* transform = GetOwner()->GetComponent<Transform>();
		Vector2	   pos = transform->GetPosition();
		Vector2	   scale = transform->GetScale();
		// float	   rotation = transform->GetRotation();

		// camera
		// pos = renderer::mainCamera->CalculatePosition(pos);

		float renderWidth = mTexture->GetWidth() * mScale.x * scale.x;
		float renderHeight = mTexture->GetHeight() * mScale.y * scale.y;

		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Bmp)
		{
			TransparentBlt(hdc, std::round(pos.x - renderWidth), std::round(pos.y - renderHeight), renderWidth, renderHeight, mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight(), RGB(255, 0, 255));
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
			// graphics.DrawImage(mTexture->GetImage(), Gdiplus::Rect(pos.x, pos.y, mTexture->GetWidth() * mScale.x * scale.x, mTexture->GetHeight() * mScale.y * scale.y));
			graphics.DrawImage(mTexture->GetImage(), Gdiplus::Rect(std::round(pos.x - renderWidth), std::round(pos.y - renderHeight), renderWidth, renderHeight), 0, 0, mTexture->GetWidth(), mTexture->GetHeight(), Gdiplus::UnitPixel, nullptr /*&imgAtt*/);
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
