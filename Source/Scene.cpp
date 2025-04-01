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
