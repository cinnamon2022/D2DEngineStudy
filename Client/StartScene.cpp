#include "StartScene.h"

#include "SpriteRenderer.h"
#include "Transform.h"
#include "InputSystem.h"
#include "SceneManager.h"
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
	Scene::Initialize();
	GameObject* logo = new GameObject();

	SpriteRenderer* sr = logo->AddComponent<SpriteRenderer>();
	sr->SetName(L"sr");
	sr->ImageLoad(L"../Resources/TitleLogo.png");

	Transform* tf = logo->AddComponent<Transform>();
	tf->SetName(L"tf");
	tf->SetPosition(DirectX::SimpleMath::Vector2(500, 200));
	tf->SetSize(DirectX::SimpleMath::Vector2(500, 400));

	AddGameObject(logo);
}

void StartScene::Update()
{
	Scene::Update();
}

void StartScene::LateUpdate()
{
	Scene::LateUpdate();
	if (InputSystem::GetInstance().IsKeyPress(Input::DIM_LB))
	{
		SceneManager::SetActiveScene(L"Stage1");
	}
}

void StartScene::Render()
{
	Scene::Render();
}

