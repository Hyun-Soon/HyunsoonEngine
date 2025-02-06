#pragma once

#include <unordered_map>

#include "Component.h"
#include "Resource/Animation.h"

namespace hs
{
	class Animator : public Component
	{
	public:
		Animator();
		~Animator();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC& hdc) override;

		void CreateAnimation(const std::wstring& name, graphics::Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLegth, float duration);

		Animation* FindAnimation(const std::wstring& name);
		void	   PlayAnimation(const std::wstring& name, bool loop = true);

		// PlayAnimation(L"move", false);

	private:
		std::unordered_map<std::wstring, Animation*> mAnimations;
		Animation*									 mActiveAnimation;
		bool										 mbLoop;
	};
} // namespace hs
