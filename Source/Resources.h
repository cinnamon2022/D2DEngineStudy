#pragma once
#include "Entity.h"

class Resources: public Entity
{
public:
	Resources();
	~Resources();


private:
	std::wstring m_path;
};

