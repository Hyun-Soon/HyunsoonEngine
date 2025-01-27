#include "SpriteRenderer.h"
#include "Component/Transform.h"
#include "GameObject.h"

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
		GameObject*		  owner = GetOwner();
		Transform*		  transform = owner->GetComponent<Transform>(L"Transform");
		Vector2			  pos = transform->GetPosition();
		Gdiplus::Graphics graphics(hdc);
		graphics.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));

		// Test
		//  Gdiplus::Image*	  image = Gdiplus::Image::FromFile(L"C:/Users/Soon/Desktop/HyunsoonEngine/Resources/Southferry/SouthferryNotSprite/Map/SouthFerry.png");
		// mImage = Gdiplus::Image::FromFile(L"C:/Users/Soon/Desktop/HyunsoonEngine/Resources/Southferry/SouthferryNotSprite/Map/SouthFerry.png");
		// Gdiplus::Graphics g(hdc);

		// g.DrawImage(mImage, 0, 0, 800, 800);

		// delete mImage;
	}

	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{

		mImage = Gdiplus::Image::FromFile(path.c_str());

		mWidth = mImage->GetWidth();
		mHeight = mImage->GetHeight();
	}
} // namespace hs
