#include "EndingScene.h"
#include "../Source/Scene.h"
#include "../Source/GameObject.h"


EndingScene::EndingScene()
{
}

EndingScene::~EndingScene()
{
}

void EndingScene::Initialize()
{
	GameObject* obj = new GameObject();
	AddGameObject(obj);
}

void EndingScene::Update()
{
	Scene::Update();
}

void EndingScene::LateUpdate()
{
	Scene::LateUpdate();
}

void EndingScene::Render()
{
	Scene::Render();
}

