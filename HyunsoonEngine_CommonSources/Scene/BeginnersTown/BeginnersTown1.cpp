#include "BeginnersTown1.h"
#include "GameObject\GameObject.h"

namespace hs
{
	BeginnersTown1::BeginnersTown1()
	{
	}

	BeginnersTown1::~BeginnersTown1()
	{
	}

	void BeginnersTown1::Initialize()
	{
		GameObject* background = new GameObject(eLayerType::Background);
	}
} // namespace hs