#include "Background.h"
#include "Component/Transform.h"
#include "Component/SpriteRenderer.h"
#include "Resource/ResourceManager.h"

namespace hs
{
	Background::Background()
	{
	}

	Background::~Background()
	{
	}

	void Background::Initialize()
	{
		SetLayerType(enums::eLayerType::Background);
		SpriteRenderer* sr = AddComponent<SpriteRenderer>();
	}

	void Background::SetTexture(const std::wstring& filename)
	{
		Transform*		tr = GetComponent<Transform>();
		SpriteRenderer* sr = GetComponent<SpriteRenderer>();

		graphics::Texture* texture = ResourceManager::Find<graphics::Texture>(filename);
		sr->SetTexture(texture);
		tr->SetPosition(texture->GetResolution());
	}
	void Background::SetRatioRender(bool enable)
	{
		SpriteRenderer* spr = GetComponent<SpriteRenderer>();
		spr->SetRatioRender(enable);
	}

	void Background::SetPosition(const Vector2& pos)
	{
		Transform* tr = GetComponent<Transform>();
		tr->SetPosition(pos);
	}
} // namespace hs
