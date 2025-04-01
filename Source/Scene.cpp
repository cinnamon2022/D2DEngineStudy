#include "Scene.h"

/*
 *���� ���� �ѳ���鼭 ���� ������ �Ѱܾ��Ѵ�
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
