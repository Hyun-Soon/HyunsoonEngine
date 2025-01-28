#include "BeginnersTown1.h"
#include "GameObject\GameObject.h"

namespace hs
{
	BeginnersTown1::BeginnersTown1()
		: Scene(eSceneType::Hunting)
	{
	}

	BeginnersTown1::~BeginnersTown1()
	{
	}

	void BeginnersTown1::Initialize()
	{
		GameObject* background = new GameObject(enums::eLayerType::Background);
	}
} // namespace hs