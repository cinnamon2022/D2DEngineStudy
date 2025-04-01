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
}

void Scene::Render()
{
}
