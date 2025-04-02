#pragma once
#include <vector>

#include "Entity.h"

class GameObject;

enum LayerType { BG, MAP, OBJECT, PLAYER, UI, END };

class Layer : public Entity
{
public:
	Layer();
	~Layer();

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

