#include "Layer.h"
#include "GameObject.h"

Layer::Layer()
{

}

Layer::~Layer()
{

}

void Layer::Initialize()
{
	for (GameObject* gameObject : m_gameObjects)
	{
		gameObject->Initialize();
	}
}

void Layer::Update()
{
	for (GameObject* gameObject : m_gameObjects)
	{
		gameObject->Update();
	}

}

void Layer::LateUpdate()
{
	for (GameObject* gameObject : m_gameObjects)
	{
		gameObject->LateUpdate();
	}
}

void Layer::Render()
{
	for (GameObject* gameObject : m_gameObjects)
	{
		gameObject->Render();
	}
}