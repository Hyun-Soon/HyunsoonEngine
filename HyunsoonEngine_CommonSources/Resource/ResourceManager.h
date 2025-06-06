#pragma once

#include <unordered_map>

#include "Resource.h"

namespace hs
{
	class ResourceManager
	{
	public:
		template <typename T>
		static T* Find(const std::wstring& key)
		{
			std::unordered_map<std::wstring, Resource*>::iterator iter = mResources.find(key);
			if (iter == mResources.end())
				return nullptr;

			return dynamic_cast<T*>(iter->second);
		}

		template <typename T>
		static T* Load(const std::wstring& key, const std::wstring& path)
		{
			T* resource = ResourceManager::Find<T>(key);
			if (resource != nullptr)
				return resource;

			resource = new T();
			resource->Load(path);
			resource->SetName(key);
			resource->SetPath(path);
			mResources[key] = resource;

			return resource;
		}

		static void Insert(const std::wstring& key, Resource* resource)
		{
			if (key == L"")
				return;
			if (resource == nullptr)
				return;

			mResources[key] = resource;
		}

		static void Release();

	private:
		static std::unordered_map<std::wstring, Resource*> mResources;
	};
} // namespace hs
