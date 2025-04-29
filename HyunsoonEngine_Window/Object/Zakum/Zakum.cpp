#include "Zakum.h"
#include "Component/Transform.h"
#include "Component/BoxCollider2D.h"
#include "Component/Rigidbody.h"
#include "Component/Animator.h"
#include "Resource/ResourceManager.h"
//#include "../../Component/ZakumScript.h"

namespace hs
{
	Zakum::Zakum()
		: mArmNum(8)
		//, mArms(8)
	{
	}

	Zakum::~Zakum()
	{
	}

	void Zakum::Initialize()
	{
		SetName(L"Zakum");
		SetLayerType(enums::eLayerType::BossMonster);

		for (uint8_t idx = 0; idx < mArmNum; ++idx)
		{
			ZakumArm* arm = new ZakumArm();
			arm->SetParent(this);
			arm->SetIndex(idx);
			//arm->Initialize();
			AddChild(arm);

			//mArms[idx] = new ZakumArm();
			//mArms[idx]->SetParent(this);
			//mArms[idx]->SetIndex(idx);
			//mArms[idx]->Initialize();
		}

		Animator* anim = AddComponent<Animator>();
		graphics::Texture* tex = ResourceManager::Find<graphics::Texture>(L"ZakumPhase1Idle");
		anim->CreateAnimation(L"ZakumPhase1Idle", tex, Vector2::Zero, { 385, 388 }, Vector2::Zero, 8, 0.2f);
		anim->PlayAnimation(L"ZakumPhase1Idle");

		BoxCollider2D* boxCol = AddComponent<BoxCollider2D>();

		/*ZakumScript* lms_Zakum = AddComponent<ZakumScript>();
		lms_Zakum->SetDeathAnimDuration(0.9f);
		lms_Zakum->SetMinTimeToTrans(2.0f);
		lms_Zakum->SetHp(10);*/
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