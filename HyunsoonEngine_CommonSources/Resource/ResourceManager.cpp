#include "ResourceManager.h"

namespace hs
{
	std::unordered_map<std::wstring, Resource*> ResourceManager::mResources;

	void ResourceManager::Release()
	{
		for (std::unordered_map<std::wstring, Resource*>::iterator iter = mResources.begin(); iter != mResources.end(); iter++)
		{
			delete iter->second;
			iter->second = nullptr;
		}
	}

} // namespace hs
