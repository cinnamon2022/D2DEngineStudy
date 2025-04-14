#include "PlayerScript.h"

#include "GameObject.h"
#include "InputSystem.h"
#include "TimeSystem.h"
#include "Transform.h"

PlayerScript::PlayerScript()
{
}

PlayerScript::~PlayerScript()
{
}

void PlayerScript::Initialize()
{
	Script::Initialize();
}

void PlayerScript::Update()
{
	Script::Update();
	Transform* transform = GetOwner()->GetComponent<Transform>();
	DirectX::SimpleMath::Vector2 playerPos = transform->GetPosition();
	TimeSystem time = TimeSystem::GetInstance();

	float speed = 160.f;

	if (InputSystem::GetInstance().IsKeyPress(DIK_W))
	{
		playerPos.y -= speed * time.DeltaTime();
	}
	if (InputSystem::GetInstance().IsKeyPress(DIK_S))
	{
		playerPos.y += speed * time.DeltaTime();
	}
	if (InputSystem::GetInstance().IsKeyPress(DIK_A))
	{
		playerPos.x -= speed * time.DeltaTime();
	}
	if (InputSystem::GetInstance().IsKeyPress(DIK_D))
	{
		playerPos.x += speed * time.DeltaTime();
	}
	transform->SetPosition(playerPos);
}

void PlayerScript::LateUpdate()
{
	Script::LateUpdate();
}

void PlayerScript::Render()
{
	Script::Render();
}
