#include "StartScene.h"

#include "SpriteRenderer.h"
#include "Transform.h"
#include "InputSystem.h"
#include "Player.h"
#include "SceneManager.h"
#include "../Source/Scene.h"
#include "../Source/GameObject.h"
#include "../Source/ResourceManager.h"

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
	sr->SetTexture(ResourceManager::GetInstance().Find<Texture>(L"TitleLogo"));

	Transform* tf = logo->AddComponent<Transform>();
	tf->SetName(L"tf");
	tf->SetPosition(DirectX::SimpleMath::Vector2(500, 200));

	AddObjectToLayer(logo, OBJECT);
}

void StartScene::Update()
{
	Scene::Update();
}

void StartScene::LateUpdate()
{
	Scene::LateUpdate();

	if (InputSystem::GetInstance().IsKeyDown(Input::DIM_LB))
	{
		SceneManager::SetActiveScene(L"Stage1");
	}
}

void StartScene::Render()
{
	Scene::Render();
}

