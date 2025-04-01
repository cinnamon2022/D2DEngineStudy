#include "Stage1.h"

#include <filesystem>
#include <iostream>

#include "Player.h"
#include "SpriteRenderer.h"
#include "Transform.h"
#include "../Source/Scene.h"
#include "../Source/GameObject.h"


Stage1::Stage1()
{
}

Stage1::~Stage1()
{
}

void Stage1::Initialize()
{
	Player* bg = new Player();
	Transform* tr
		= bg->AddComponent<Transform>();
	tr->SetPosition(DirectX::SimpleMath::Vector2(0, 0));

	tr->SetName(L"TR");

	SpriteRenderer* sr
		= bg->AddComponent<SpriteRenderer>();
	sr->SetName(L"SR");

	sr->ImageLoad(L"..\\Resources\\CloudOcean.png");

	AddGameObject(bg);
}

void Stage1::Update()
{
	Scene::Update();
}

void Stage1::LateUpdate()
{
	Scene::LateUpdate();
}

void Stage1::Render()
{

	Scene::Render();

}
