#pragma once

#include <vector>

#include "Resource/Texture.h"
#include "MathTypes.h"

namespace hs
{
	class Animation : public Resource
	{
	public:
		struct Sprite
		{
			Vector2 leftTop;
			Vector2 size;
			Vector2 offset;
			float	duration;

			Sprite()
				: leftTop(Vector2::Zero)
				, size(Vector2::Zero)
				, offset(Vector2::Zero)
				, duration(0.0f)
			{
			}
		};

		Animation();
		~Animation();

		HRESULT Load(const std::wstring& path) override;

		void Update();
		void Render(HDC& hdc);

		void CreateAnimation(const std::wstring& name, graphics::Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLegth, float duration);

		void Reset();

		bool		  IsComplete() { return mbComplete; }
		void		  SetAnimator(class Animator* animator) { mAnimator = animator; }
		const Vector2 GetAnimationSize() const { return mAnimationSheet[mIndex].size; }
		const Vector2 GetCenterOffset() const;

	private:
		class Animator*	   mAnimator;
		graphics::Texture* mTexture;

		std::vector<Sprite> mAnimationSheet;
		int					mIndex;
		float				mTime;
		bool				mbComplete;
	};

} // namespace hs
