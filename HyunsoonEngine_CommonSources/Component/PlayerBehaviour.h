#pragma once

#include "Component.h"

namespace hs
{
	class Transform;
	class PlayerBehaviour : public Component
	{
	public:
		PlayerBehaviour();
		~PlayerBehaviour();

		virtual void Initialize() override;
		virtual void Update() override;
		/*virtual void LateUpdate() override;
		virtual void Render(HDC& hdc) override;*/

	private:
		Transform* mTransform;
	};

} // namespace hs