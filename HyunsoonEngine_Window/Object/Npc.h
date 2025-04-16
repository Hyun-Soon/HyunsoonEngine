#pragma once

#include "GameObject/GameObject.h"

namespace hs
{
	class Npc : public GameObject
	{
	public:
		Npc();
		~Npc();

		virtual void Initialize() override;

		void SetTexture(std::wstring texName);
		void SetDialogues(std::vector<std::wstring>& dialogues) { mDialogues = dialogues; }
		void SetRenderName(std::wstring name) { mRenderName = name; }

	private:
		void showDialogue();

		std::vector<std::wstring> mDialogues;
		std::wstring			  mRenderName;
	};

} // namespace hs
