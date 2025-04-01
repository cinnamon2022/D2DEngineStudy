#include "StartScene.h"
#include "../Source/Scene.h"
#include "../Source/GameObject.h"


StartScene::StartScene()
{
}

StartScene::~StartScene()
{
}

void StartScene::Initialize()
{
	GameObject* obj = new GameObject();
	AddGameObject(obj);
}

void StartScene::Update()
{
	Scene::Update();
}

void StartScene::LateUpdate()
{
	Scene::LateUpdate();
}

void StartScene::Render()
{
	Scene::Render();
}

