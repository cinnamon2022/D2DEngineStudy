#include "Stage1.h"

#include <filesystem>
#include <iostream>

#include "InputSystem.h"
#include "Player.h"
#include "SceneManager.h"
#include "SpriteRenderer.h"
#include "Texture.h"
#include "Transform.h"
#include "../Source/Scene.h"
#include "../Source/GameObject.h"
#include "../Source/ResourceManager.h"
#include "../Source/Animator.h"


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
	Animator* animator = dino->AddComponent<Animator>();
	animator->CreateAnimation(L"PlayerIdle", ResourceManager::GetInstance().Find<Texture>(L"PlayerIdle"),
		DirectX::SimpleMath::Vector2(0, 0), DirectX::SimpleMath::Vector2(129.5, 108), 
		DirectX::SimpleMath::Vector2(0, 0), 4, 0.08f);
	animator->PlayAnimation(L"PlayerIdle", true);

	Transform* tf = dino->AddComponent<Transform>();
	tf->SetName(L"tf");
	tf->SetPosition(DirectX::SimpleMath::Vector2(0, 0));

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
