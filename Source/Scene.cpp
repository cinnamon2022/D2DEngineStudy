#include "Scene.h"

/*
 *씬과 씬을 넘나들면서 씬은 정보를 넘겨야한다
 *
 *
 *
 * 
 */
Scene::Scene():m_gameObjects{}
{

}

Scene::~Scene()
{

}

void Scene::Initialize()
{
	for (GameObject* gameObject : m_gameObjects)
	{
		gameObject->Initialize();
	}
}

void Scene::Update()
{
	for (GameObject* gameObject : m_gameObjects)
	{
		gameObject->Update();
	}

}

void Scene::LateUpdate()
{
	for (GameObject* gameObject : m_gameObjects)
	{
		gameObject->LateUpdate();
	}
}

void Scene::Render()
{
	for (GameObject* gameObject : m_gameObjects)
	{
		gameObject->Render();
	}
}
