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
		float	   rotation = transform->GetRotation();

		// camera
		// pos = renderer::mainCamera->CalculatePosition(pos);

		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Png)
		{
			Gdiplus::Graphics graphics(hdc);
			// graphics.TranslateTransform(pos.x, pos.y);
			// graphics.RotateTransform(rotation);
			// graphics.TranslateTransform(-pos.x, -pos.y);
			graphics.DrawImage(mTexture->GetImage(), Gdiplus::Rect(pos.x, pos.y, mTexture->GetWidth() * mScale.x * scale.x, mTexture->GetHeight() * mScale.y * scale.y));
		}
		else if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Bmp)
		{
			TransparentBlt(hdc, pos.x, pos.y, mTexture->GetWidth() * mScale.x * scale.x, mTexture->GetHeight() * mScale.y * scale.y, mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight(), RGB(255, 0, 255));
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
