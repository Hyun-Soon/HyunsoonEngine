#pragma once

#include "GameObject/GameObject.h"

namespace hs
{
	class Portal : public GameObject
	{
	public:
		Portal();
		~Portal();

		virtual void Initialize();
		// virtual void Update();
		// virtual void LateUpdate();
		// virtual void Render(HDC& hdc);

	private:
	};

} // namespace hs