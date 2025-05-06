#include "WinScene.h"
#include "../Source/SpriteRenderer.h"
#include "../Source/Transform.h"
#include "../Source/InputSystem.h"

#include "../Source/Scene.h"
#include "../Source/GameObject.h"
#include "../Source/ResourceManager.h"
WinScene::WinScene()
{
}

WinScene::~WinScene()
{
}

void WinScene::Initialize()
{
	Scene::Initialize();
	GameObject* logo = new GameObject();

	SpriteRenderer* sr = logo->AddComponent<SpriteRenderer>();
	sr->SetTexture(ResourceManager::GetInstance().Find<Texture>(L"WinLogo"));

	Transform* tf = logo->AddComponent<Transform>();
	tf->SetName(L"tf");
	tf->SetPosition(DirectX::SimpleMath::Vector2(300, 50));

	AddObjectToLayer(logo, OBJECT);
}

void WinScene::Update()
{
	Scene::Update();
}

void WinScene::LateUpdate()
{
	Scene::LateUpdate();
}

void WinScene::Render()
{
	Scene::Render();
}
