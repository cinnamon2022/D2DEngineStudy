#pragma once
#include <vector>

#include "Entity.h"

class GameObject;

enum eLayerType { BG, MAP, OBJECT, PLAYER, UI, END };

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
	const std::vector<GameObject*> GetGameObjects(){return m_gameObjects;}

private:
	std::vector<GameObject*> m_gameObjects;
};

