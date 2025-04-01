#include "Stage1.h"

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
	Player* pl = new Player();
	Transform* tr
		= pl->AddComponent<Transform>();
	tr->SetPos(800, 450);

	tr->SetName(L"TR");

	SpriteRenderer* sr
		= pl->AddComponent<SpriteRenderer>();
	sr->SetName(L"SR");

	AddGameObject(pl);
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
