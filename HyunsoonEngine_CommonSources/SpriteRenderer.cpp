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
		// GameObject*		  owner = GetOwner();
		// Transform*		  transform = owner->GetComponent<Transform>(L"Transform");
		// Vector2			  pos = transform->GetPosition();
		// Gdiplus::Graphics graphics(hdc);
		// graphics.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));

		Gdiplus::Image*	  image = Gdiplus::Image::FromFile(L"C:/Users/Soon/Desktop/HyunsoonEngine/Resources/Southferry/SouthferryNotSprite/Map/SouthFerry.png");
		Gdiplus::Graphics g(hdc);

		// (x, y)에 width X height 크기의 이미지를 그립니다.
		g.DrawImage(image, 0, 0, 800, 800);

		// 데이터 메모리 해제
		delete image;
	}

	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{
		// mImage = Gdiplus::Image::FromFile(path.c_str());

		// mWidth = mImage->GetWidth();
		// mHeight = mImage->GetHeight();
	}
} // namespace hs
