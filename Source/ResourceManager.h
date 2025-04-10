#pragma once
#include <map>
#include <unordered_map>

#include "Resource.h"

class ResourceManager
{
public:
	static ResourceManager& GetInstance();

	template <typename T>
	T* Find(const std::wstring& name)
	{
		auto it = m_resource.find(name);
		if (it == m_resource.end())
			return nullptr;
		return dynamic_cast<T*>(it->second);
	}

	template <typename T>
	T* Load(const std::wstring& name, const std::wstring& path)
	{
		T* resource = Find<T>(name);
		if (resource != nullptr)
			return resource;

		resource = new T();
		resource->Load(path);
		resource->SetName(name);
		resource->SetPath(path);

		m_resource.insert(std::make_pair(name, resource));
		return resource;
	}
private:
	std::unordered_map<std::wstring, Resource*> m_resource;
};

	