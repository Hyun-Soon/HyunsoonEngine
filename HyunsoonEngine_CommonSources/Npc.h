#pragma once

#include <string>

#include "GameObject.h"

namespace hs
{
	class Npc : public GameObject
	{
	public:
		Npc(Vector2 pos);
		~Npc();

		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC& hdc);

	private:
		void showDialogue();

		std::string mDialogues[3];
	};

} // namespace hs
