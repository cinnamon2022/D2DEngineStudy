#pragma once
#include <intsafe.h>
#include <vector>

#include "Entity.h"
#include "Layer.h"

class GameObject;

class Scene : public Entity
{
public:
	Scene();
	virtual ~Scene();

	virtual void Enter();
	virtual void Exit();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();

	void AddObjectToLayer(GameObject* gameObject, const eLayerType type)
	{
		m_layers[(UINT)type]->AddGameObject(gameObject);
	}
	Layer* GetLayer(eLayerType type) { return m_layers[(UINT)type]; }
private:
	std::vector<Layer*> m_layers;
};

