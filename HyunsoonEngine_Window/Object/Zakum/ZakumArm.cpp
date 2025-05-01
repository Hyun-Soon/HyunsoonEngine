#include "ZakumArm.h"
#include "Component/Transform.h"
#include "Component/BoxCollider2D.h"
#include "Component/Rigidbody.h"
#include "Component/Animator.h"
#include "../HyunsoonEngine_Window/Component/ZakumArmScript.h"
#include "Resource/ResourceManager.h"

namespace hs
{
	ZakumArm::ZakumArm()
		: mIdx(-1)
		, mParent(nullptr)
	{
	}

	ZakumArm::~ZakumArm()
	{
	}

	void ZakumArm::Initialize()
	{
		std::wstring name = L"ZakumArm" + std::to_wstring(mIdx);
		SetName(name);
		SetLayerType(enums::eLayerType::BossMonster);

		Animator* anim = AddComponent<Animator>();
		graphics::Texture* tex = ResourceManager::Find<graphics::Texture>(name);
		anim->CreateAnimation(name, tex, Vector2::Zero, zakumArms::animSizes[mIdx], Vector2::Zero, 8, 0.2f);

		graphics::Texture* texDeath = ResourceManager::Find<graphics::Texture>(name + L"Death");
		anim->CreateAnimation(name + L"Death", texDeath, Vector2::Zero, zakumArms::deathAnimSizes[mIdx], Vector2::Zero, 10, 0.15f);

		anim->PlayAnimation(name);

		BoxCollider2D* boxCol = AddComponent<BoxCollider2D>();

		ZakumArmScript* armScript = AddComponent<ZakumArmScript>();
	}
	void ZakumArm::Update()
	{
		Transform* tr = GetComponent<Transform>();
		Transform* parentTr = mParent->GetComponent<Transform>();
		tr->SetPosition(parentTr->GetPosition() + zakumArms::offsets[mIdx]);

		GameObject::Update();
	}

} // namespace hs