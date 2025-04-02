#include "Stage1.h"

#include <filesystem>
#include <iostream>

#include "InputSystem.h"
#include "Player.h"
#include "SceneManager.h"
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

void Stage1::Enter()
{
	Scene::Enter();

}

void Stage1::Exit()
{
	Scene::Exit();
	Transform* tf = dino->GetComponent<Transform>();
	tf->SetPosition(DirectX::SimpleMath::Vector2(500, 800));
}

void Stage1::Initialize()
{
	Scene::Initialize();
	dino = new Player();

	SpriteRenderer* sr = dino->AddComponent<SpriteRenderer>();
	sr->SetName(L"sr");
	sr->ImageLoad(L"..\\Resources\\Idle_1.png");

	Transform* tf = dino->AddComponent<Transform>();
	tf->SetName(L"tf");
	tf->SetPosition(DirectX::SimpleMath::Vector2(500, 800));
	tf->SetSize(DirectX::SimpleMath::Vector2(50, 50));

	AddObjectToLayer(dino,PLAYER);
}

void Stage1::Update()
{
	Scene::Update();
}

void Stage1::LateUpdate()
{
	Scene::LateUpdate();
	if (InputSystem::GetInstance().IsKeyDown(Input::DIM_LB))
	{
		SceneManager::SetActiveScene(L"StartScene");
	}
}

void Stage1::Render()
{

	Scene::Render();

}
