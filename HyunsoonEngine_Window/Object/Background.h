#pragma once

#include "GameObject/GameObject.h"

namespace hs
{
	class Background : public GameObject
	{
	public:
		Background();
		~Background();

		virtual void Initialize() override;

		void SetTexture(const std::wstring& filename);

	private:
	};

} // namespace hs