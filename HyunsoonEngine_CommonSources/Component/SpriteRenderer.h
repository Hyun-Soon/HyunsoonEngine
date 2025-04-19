#pragma once

#include "../GdiPlusInclude.h"
#include "Component.h"
#include "Resource/Texture.h"
#include "MathTypes.h"

namespace hs
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		virtual ~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC& hdc) override;

		void SetTexture(graphics::Texture* texture);
		void SetScale(Vector2 scale);
		void SetRatioRender(bool enable) { mbRatioRender = enable; }

	private:
		graphics::Texture* mTexture;
		Vector2			   mScale;
		bool			   mbRatioRender;
	};
} // namespace hs