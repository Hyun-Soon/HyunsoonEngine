#include "Component/SpriteRenderer.h"
#include "Component/Transform.h"
#include "GameObject/GameObject.h"

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
		delete mImage;
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
		GameObject*		  owner = GetOwner();
		Transform*		  transform = owner->GetComponent<Transform>();
		Vector2			  pos = transform->GetPosition();
		Gdiplus::Graphics graphics(hdc);
		graphics.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, 300, 200));
		//  graphics.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));
	}

	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{

		mImage = Gdiplus::Image::FromFile(path.c_str());

		mWidth = mImage->GetWidth();
		mHeight = mImage->GetHeight();
	}
} // namespace hs
