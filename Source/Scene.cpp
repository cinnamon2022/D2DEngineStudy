#include "Scene.h"

#include <algorithm>

#include "Layer.h"
/*
 *씬과 씬을 넘나들면서 씬은 정보를 넘겨야한다
 *
 *
 *
 * 
 */
Scene::Scene()
{
	m_layers.resize(END);
	for (Layer*& layer : m_layers)
	{
		layer = new Layer();
	}
}

Scene::~Scene()
{
	for (Layer*& layer : m_layers)
	{
		delete layer;
	}
}

void Scene::Enter()
{
}

void Scene::Exit()
{
}

void Scene::Initialize()
{
	for (Layer* layer : m_layers)
	{
		layer->Initialize();
	}
}

void Scene::Update()
{
	for (Layer* layer : m_layers)
	{
		layer->Update();
	}

}

void Scene::LateUpdate()
{
	for (Layer* layer : m_layers)
	{
		layer->LateUpdate();
	}
}

void Scene::Render()
{
	for (Layer* layer : m_layers)
	{
		layer->Render();
	}
}

