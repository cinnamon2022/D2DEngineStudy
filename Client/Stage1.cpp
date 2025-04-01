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
	Scene::Initialize();
	Player* dino = new Player();

	SpriteRenderer* sr = dino->AddComponent<SpriteRenderer>();
	sr->SetName(L"sr");
	sr->ImageLoad(L"..\\Resources\\Idle_1.png");

	Transform* tf = dino->AddComponent<Transform>();
	tf->SetName(L"tf");
	tf->SetPosition(DirectX::SimpleMath::Vector2(500, 300));
	tf->SetSize(DirectX::SimpleMath::Vector2(50, 50));

	AddGameObject(dino);
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
