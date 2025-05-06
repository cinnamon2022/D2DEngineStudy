#include "PlayerScript.h"

#include "../Source/Animator.h"
#include "../Source/GameObject.h"
#include "../Source/InputSystem.h"
#include "../Source/TimeSystem.h"
#include "../Source/Transform.h"
#include "../Source/SceneManager.h"

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

	if (InputSystem::GetInstance().IsKeyPress(DIK_Q))
	{
		playerPos.y -= speed * time.DeltaTime();
	}

}

void PlayerScript::LateUpdate()
{
	Script::LateUpdate();
}

void PlayerScript::Render()
{
	Script::Render();
}

void PlayerScript::OnCollisionEnter(Collider* other)
{
	Animator* ani = GetOwner()->GetComponent<Animator>();
	ani->PlayAnimation(L"PlayerDie");
	SceneManager::SetActiveScene(L"EndingScene");
}

void PlayerScript::OnCollisionStay(Collider* other)
{
	int a = 0;
}

void PlayerScript::OnCollisionExit(Collider* other)
{
	int a = 0;
}
