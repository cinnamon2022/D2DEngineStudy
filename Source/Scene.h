#pragma once
#include <vector>

#include "Entity.h"
#include "GameObject.h"

class Scene : public Entity
{
public:
	Scene();
	virtual ~Scene();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();

	void AddGameObject(GameObject* gameObject)
	{
		m_gameObjects.push_back(gameObject);
	}

private:
	std::vector<GameObject*> m_gameObjects;
};

