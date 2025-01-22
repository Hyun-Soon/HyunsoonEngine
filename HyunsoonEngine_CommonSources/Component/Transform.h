#pragma once

#include "Component.h"
#include "MathTypes.h"

namespace hs
{
	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void		   SetPosition(Vector2& pos);
		const Vector2& GetPosition() const;

	private:
		Vector2 mPosition;
	};
} // namespace hs