#pragma once

#include <unordered_map>
#include <stack>
#include <queue>

#include "UIBase.h"

namespace hs
{
	using namespace enums;

	class UIManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC& hdc);

		static void Release();

		static void OnLoad(eUIType type);
		static void OnComplete(UIBase* addUI);
		static void OnFail();

		static void Push(eUIType type);
		static void Pop(eUIType type);

	private:
		static std::unordered_map<eUIType, UIBase*> mUIs;
		static std::stack<UIBase*>					mUIBases;
		static std::queue<eUIType>					mRequestUiQueue;
		static UIBase*								mActiveUI;
	};
} // namespace hs
