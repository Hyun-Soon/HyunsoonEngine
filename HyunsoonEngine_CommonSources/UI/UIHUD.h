#pragma once

#include "UIBase.h"
#include "Resource/Texture.h"

namespace hs
{
	class UIHUD : public UIBase
	{
	public:
		UIHUD();
		~UIHUD();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInactive() override;
		virtual void OnUpdate() override;
		virtual void OnLateUpdate() override;
		virtual void OnRender(HDC& hdc) override;
		virtual void OnClear() override;

	private:
		graphics::Texture* mTexture;
	};
} // namespace hs
