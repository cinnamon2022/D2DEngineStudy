#include "Player.h"
#include "InputSystem.h"
#include "TimeSystem.h"
#include "Transform.h"

void Player::Initialize()
{
	GameObject::Initialize();
}

void Player::Update()
{
	GameObject::Update();
}

void Player::LateUpdate()
{
	GameObject::LateUpdate();

	Transform* transform = GetComponent<Transform>();
	DirectX::SimpleMath::Vector2 playerPos = transform->GetPosition();
	TimeSystem time = TimeSystem::GetInstance();

	float speed = 160.f;

	if (InputSystem::GetInstance().IsKeyPress(DIK_W))
	{
		playerPos.y -= speed * time.DeltaTime();
	}
	if (InputSystem::GetInstance().IsKeyPress(DIK_S))
	{
		playerPos.y +=  speed * time.DeltaTime();
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

void Player::Render()
{
	GameObject::Render();
}