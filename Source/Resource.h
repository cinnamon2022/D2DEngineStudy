#pragma once
#include "Entity.h"

class Resource : public Entity
{
public:

	enum class eResourceType
	{
		Texture,
		Audio,
		Animation,
		End
	};

	Resource(eResourceType type);
	virtual ~Resource();
	virtual void Load(const std::wstring& path) = 0;

	const std::wstring& GetPath() { return m_path; }
	void SetPath(const std::wstring& path) { m_path = path; }

private:
	std::wstring m_path;
	const eResourceType m_Type;
};

