#pragma once
#include <directxtk/SimpleMath.h>

#include "Component.h"
#include "GameObject.h"
#include "Layer.h"
#include "Scene.h"
#include "SceneManager.h"
#include "Transform.h"


namespace Object
{
	template <typename T>
	static T* Instantiate(LayerType type)
	{
		T* object = new T();
		Scene* scene = SceneManager::GetActiveScene();
		Layer* layer = scene->GetLayer(type);
		layer->AddGameObject(object);
		return object;
	}

	template <typename T>
	static T* Instantiate(LayerType type,DirectX::SimpleMath::Vector2 pos)
	{
		T* object = new T();
		Scene* scene = SceneManager::GetActiveScene();
		Layer* layer = scene->GetLayer(type);
		layer->AddGameObject(object);

		Transform* tf = object->template GetComponent<Transform>();
		tf->SetPosition(pos);
		return object;
	}
}
