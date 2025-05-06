#include "Stage1.h"

#include <filesystem>
#include <iostream>

#include "Collider.h"
#include "InputSystem.h"
#include "Player.h"
#include "CollisionManager.h"
#include "Enemy.h"
#include "SceneManager.h"
#include "Texture.h"
#include "Transform.h"
#include "PlayerScript.h"

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
	CollisionManager::GetInstance().CollisionLayerCheck(eLayerType::PLAYER, eLayerType::OBJECT, true);

	Scene::Initialize();
	dino = new Player();
	Animator* dinoani = dino->AddComponent<Animator>();
	dinoani->CreateAnimation(L"PlayerIdle", ResourceManager::GetInstance().Find<Texture>(L"PlayerIdle"),
		DirectX::SimpleMath::Vector2(0, 0), DirectX::SimpleMath::Vector2(129.5, 108), 
		DirectX::SimpleMath::Vector2(0, 0), 4, 0.08f);
	dinoani->CreateAnimation(L"PlayerWalk", ResourceManager::GetInstance().Find<Texture>(L"PlayerIdle"),
		DirectX::SimpleMath::Vector2(0, 0), DirectX::SimpleMath::Vector2(129.5, 108),
		DirectX::SimpleMath::Vector2(0, 0), 4, 0.08f);
	dinoani->CreateAnimation(L"PlayerAttack", ResourceManager::GetInstance().Find<Texture>(L"PlayerIdle"),
		DirectX::SimpleMath::Vector2(0, 0), DirectX::SimpleMath::Vector2(129.5, 108),
		DirectX::SimpleMath::Vector2(0, 0), 4, 0.08f);

	dinoani->PlayAnimation(L"PlayerIdle");
	Transform* dinotf = dino->AddComponent<Transform>();
	dinotf->SetName(L"tf");
	dinotf->SetPosition(DirectX::SimpleMath::Vector2(800, 1000));
	dino->AddComponent<Collider>();

	dino->AddComponent<PlayerScript>();

	AddObjectToLayer(dino,PLAYER);

	robo = new Enemy();
	Animator* roboani = robo->AddComponent<Animator>();
	roboani->CreateAnimation(L"Enemy", ResourceManager::GetInstance().Find<Texture>(L"Enemy"),
		DirectX::SimpleMath::Vector2(0, 0), DirectX::SimpleMath::Vector2(108, 108),
		DirectX::SimpleMath::Vector2(0, 0), 4, 0.08f);

	roboani->PlayAnimation(L"Enemy");
	Transform* robotf = robo->AddComponent<Transform>();
	robotf->SetName(L"tf");
	robotf->SetPosition(DirectX::SimpleMath::Vector2(100, 1000));
	robo->AddComponent<Collider>();

	AddObjectToLayer(robo, OBJECT);



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
