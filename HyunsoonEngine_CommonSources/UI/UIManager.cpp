#include "UIManager.h"
#include "UIHUD.h"
#include "UIButton.h"

// debug
#include "../HyunsoonEngine_Window/Object/Player.h"
#include "Component\Rigidbody.h"

namespace hs
{
	std::unordered_map<eUIType, UIBase*> UIManager::mUIs = {};
	std::stack<UIBase*>					 UIManager::mUIBases = {};
	std::queue<eUIType>					 UIManager::mRequestUiQueue = {};
	UIBase*								 UIManager::mActiveUI = nullptr;

	void UIManager::Initialize()
	{
		UIHUD* hud = new UIHUD();
		mUIs.insert(std::make_pair(eUIType::BottomBar, hud));

		UIManager::Push(eUIType::BottomBar);

		// UIButton* button = new UIButton();
		// mUIs.insert(std::make_pair(eUIType::Button, button));
	}

	void UIManager::Update()
	{
		std::stack<UIBase*> uiBases = mUIBases;
		while (!uiBases.empty())
		{
			UIBase* uiBase = uiBases.top();
			if (uiBase)
			{
				uiBase->Update();
				uiBases.pop();
			}
		}

		if (mRequestUiQueue.size() > 0)
		{
			eUIType requestUI = mRequestUiQueue.front();
			mRequestUiQueue.pop();
			OnLoad(requestUI);
		}
	}

	void UIManager::LateUpdate()
	{
		std::stack<UIBase*> uiBases = mUIBases;
		while (!uiBases.empty())
		{
			UIBase* uiBase = uiBases.top();
			if (uiBase)
			{
				uiBase->LateUpdate();
				uiBases.pop();
			}
		}
	}

	void UIManager::Render(HDC& hdc)
	{
		// debug
		//{
		//	Player*	   player = Player::GetInstance();
		//	Rigidbody* rgb = player->GetComponent<Rigidbody>();
		//	Vector2	   v = rgb->GetVelocity();

		//	wchar_t str[50] = L"";
		//	swprintf_s(str, 50, L"Velocity : %d, %d", (int)v.x, (int)v.y);
		//	int len = wcsnlen_s(str, 50);

		//	TextOut(hdc, 0, 0, str, len);
		//}

		if (mUIBases.size() <= 0)
			return;

		// 해당 ui 한개만 스택에서 뺴줘야한다.
		std::vector<UIBase*> buff;

		UIBase* uibase = nullptr;
		while (mUIBases.size() > 0)
		{
			uibase = mUIBases.top();
			mUIBases.pop();

			buff.push_back(uibase);
		}
		std::reverse(buff.begin(), buff.end());

		for (UIBase* ui : buff)
		{
			ui->Render(hdc);
			mUIBases.push(ui);
		}
	}

	void UIManager::Release()
	{
		for (auto iter : mUIs)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}

	void UIManager::OnLoad(eUIType type)
	{
		std::unordered_map<eUIType, UIBase*>::iterator iter = mUIs.find(type);

		if (iter == mUIs.end())
		{
			OnFail();
			return;
		}

		OnComplete(iter->second);
	}

	void UIManager::OnComplete(UIBase* addUI)
	{
		if (addUI == nullptr)
			return;

		addUI->Initialize();
		addUI->Active();
		addUI->Update();

		// 만약에 현재 추가된 ui가 전체화면이라면
		// 전체화면인 ui 말고 나머지를 전부 비활성화
		if (addUI->IsFullScreen())
		{
			std::stack<UIBase*> uiBases = mUIBases;
			while (!uiBases.empty())
			{
				UIBase* uiBase = uiBases.top();
				uiBases.pop();
				if (uiBase)
				{
					uiBase->Inactive();
				}
			}
		}

		mUIBases.push(addUI);
		mActiveUI = nullptr;
	}

	void UIManager::OnFail()
	{
		mActiveUI = nullptr;
	}

	void UIManager::Push(eUIType type)
	{
		mRequestUiQueue.push(type);
	}

	void UIManager::Pop(eUIType type)
	{
		if (mUIBases.size() <= 0)
			return;

		// 해당 ui 한개만 스택에서 뺴줘야한다.
		std::stack<UIBase*> tempStack;

		UIBase* uibase = nullptr;
		while (mUIBases.size() > 0)
		{
			uibase = mUIBases.top();
			mUIBases.pop();

			if (uibase->GetType() != type)
			{
				tempStack.push(uibase);
				continue;
			}

			if (uibase->IsFullScreen())
			{
				std::stack<UIBase*> uiBases = mUIBases;
				while (!uiBases.empty())
				{
					UIBase* uiBase = uiBases.top();
					uiBases.pop();
					if (uiBase)
					{
						uiBase->Active();
						break;
					}
				}
			}

			uibase->UIClear();
		}

		while (tempStack.size() > 0)
		{
			uibase = tempStack.top();
			tempStack.pop();
			mUIBases.push(uibase);
		}
	}

} // namespace hs
