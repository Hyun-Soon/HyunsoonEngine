#pragma once

#include "GameObject/GameObject.h"

namespace hs
{
	class Portal : public GameObject, public Entity
	{
	public:
		Portal();
		~Portal();

		virtual void Initialize();

		const UINT GetDestPortalIdx() const { return mDestPortalIdx; }
		void	   SetDestPortalIdx(const UINT portalIdx) { mDestPortalIdx = portalIdx; }

	private:
		UINT mDestPortalIdx;
	};

} // namespace hs