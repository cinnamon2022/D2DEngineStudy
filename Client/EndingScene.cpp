#include "EndingScene.h"

#include "../Source/ResourceManager.h"
#include "../Source/SpriteRenderer.h"
#include "../Source/Transform.h"
#include "../Source/Layer.h"
#include "../Source/GameObject.h"


EndingScene::EndingScene()
{
}

EndingScene::~EndingScene()
{
}

void EndingScene::Initialize()
{
	Scene::Initialize();
	GameObject* logo = new GameObject();

	SpriteRenderer* sr = logo->AddComponent<SpriteRenderer>();
	sr->SetTexture(ResourceManager::GetInstance().Find<Texture>(L"EndLogo"));

	Transform* tf = logo->AddComponent<Transform>();
	tf->SetName(L"tf");
	tf->SetPosition(DirectX::SimpleMath::Vector2(300, 50));


	AddObjectToLayer(logo, OBJECT);
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

