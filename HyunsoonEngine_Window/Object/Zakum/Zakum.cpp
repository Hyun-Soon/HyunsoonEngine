#include "Zakum.h"
#include "Component/Transform.h"
#include "Component/BoxCollider2D.h"
#include "Component/Rigidbody.h"
#include "Component/Animator.h"
#include "Resource/ResourceManager.h"
#include "../../Component/ZakumScript.h"

namespace hs
{
	Zakum::Zakum()
		: mArmNum(8)
	{
	}

	Zakum::~Zakum()
	{
	}

	void Zakum::Initialize()
	{
		SetName(L"Zakum");
		SetLayerType(enums::eLayerType::BossMonster);

		/*for (uint8_t idx = 0; idx < mArmNum; ++idx)
		{
			ZakumArm* arm = new ZakumArm();
			arm->SetParent(this);
			arm->SetIndex(idx);
			arm->Initialize();
			AddChild(arm);
		}*/

		//debug
		for (uint8_t idx = 0; idx < 1; ++idx)
		{
			ZakumArm* arm = new ZakumArm();
			arm->SetParent(this);
			arm->SetIndex(idx);
			arm->Initialize();
			AddChild(arm);
		}

		Animator* anim = AddComponent<Animator>();
		graphics::Texture* tex = ResourceManager::Find<graphics::Texture>(L"ZakumPhase1Idle");
		anim->CreateAnimation(L"ZakumPhase1Idle", tex, Vector2::Zero, { 385, 388 }, Vector2::Zero, 8, 0.2f);
		anim->PlayAnimation(L"ZakumPhase1Idle");

		tex = ResourceManager::Find<graphics::Texture>(L"ZakumPhase1Death");
		anim->CreateAnimation(L"ZakumPhase1Death", tex, Vector2::Zero, { 385, 381 }, Vector2::Zero, 10, 0.2f);

		tex = ResourceManager::Find<graphics::Texture>(L"ZakumPhase2Idle");
		anim->CreateAnimation(L"ZakumPhase2Idle", tex, Vector2::Zero, { 385, 387 }, Vector2::Zero, 8, 0.2f);

		tex = ResourceManager::Find<graphics::Texture>(L"ZakumPhase2Death");
		anim->CreateAnimation(L"ZakumPhase2Death", tex, Vector2::Zero, { 405, 421}, Vector2::Zero, 10, 0.2f);

		tex = ResourceManager::Find<graphics::Texture>(L"ZakumPhase3Idle");
		anim->CreateAnimation(L"ZakumPhase3Idle", tex, Vector2::Zero, { 385, 417 }, Vector2::Zero, 8, 0.2f);

		tex = ResourceManager::Find<graphics::Texture>(L"ZakumPhase3Death");
		anim->CreateAnimation(L"ZakumPhase3Death", tex, Vector2::Zero, { 406, 423 }, Vector2::Zero, 10, 0.2f);


		ZakumScript* lms_Zakum = AddComponent<ZakumScript>();
	}

	//void Zakum::Update()
	//{
	//	for (uint8_t idx = 0; idx < mArmNum; ++idx)
	//	{
	//		mArms[idx]->Update();
	//	}
	//	GameObject::Update();
	//}

	//void Zakum::LateUpdate()
	//{
	//	for (uint8_t idx = 0; idx < mArmNum; ++idx)
	//	{
	//		mArms[idx]->LateUpdate();
	//	}
	//	GameObject::LateUpdate();
	//}

	//void Zakum::Render(HDC& hdc)
	//{
	//	for (uint8_t idx = 0; idx < mArmNum; ++idx)
	//	{
	//		mArms[idx]->Render(hdc);
	//	}
	//	GameObject::Render(hdc);
	//}
} // namespace hs