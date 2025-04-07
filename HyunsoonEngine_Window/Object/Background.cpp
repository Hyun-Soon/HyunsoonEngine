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
	}

	void Background::SetTexture(const std::wstring& filename)
	{
		Transform*		tr = GetComponent<Transform>();
		SpriteRenderer* sr = AddComponent<SpriteRenderer>();

		graphics::Texture* texture = ResourceManager::Find<graphics::Texture>(filename);
		sr->SetTexture(texture);
		tr->SetPosition(texture->GetResolution());
	}
} // namespace hs
