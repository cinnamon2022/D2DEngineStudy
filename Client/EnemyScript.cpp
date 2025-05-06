#include "EnemyScript.h"

#include "../Source/Animator.h"
#include "../Source/GameObject.h"
#include "../Source/InputSystem.h"
#include "../Source/TimeSystem.h"
#include "../Source/Transform.h"

#include "../Source/SceneManager.h"

EnemyScript::EnemyScript()
{
}

EnemyScript::~EnemyScript()
{
}

void EnemyScript::Initialize()
{
	Script::Initialize();
}

void EnemyScript::Update()
{
	Script::Update();
	Transform* transform = GetOwner()->GetComponent<Transform>();
	DirectX::SimpleMath::Vector2 playerPos = transform->GetPosition();
	TimeSystem time = TimeSystem::GetInstance();

	timer += time.DeltaTime();

	if (timer < 2 && timer > 0)
	{
		playerPos.y -= speed * time.DeltaTime();
	}
	if (timer < 6 && timer > 2)
	{
		playerPos.x += speed * time.DeltaTime();
	}
	if (timer < 9 && timer > 5)
	{
		playerPos.y += speed * time.DeltaTime();
	}
	if (timer < 12 && timer > 8)
	{
		playerPos.x -= speed * time.DeltaTime();
	}
	if (timer > 13)
	{
		timer = 0;
		speed += 80;
	}
	
	transform->SetPosition(playerPos);
}

void EnemyScript::LateUpdate()
{
	Script::LateUpdate();
	Transform* transform = GetOwner()->GetComponent<Transform>();
	DirectX::SimpleMath::Vector2 playerPos = transform->GetPosition();

	if (playerPos.x < 0 || playerPos.x > 2000|| playerPos.y < 0 || playerPos.y > 1200)
	{
		SceneManager::SetActiveScene(L"WinScene");
	}
}

void EnemyScript::Render()
{
	Script::Render();
}

void EnemyScript::OnCollisionEnter(class Collider* other)
{
	Script::OnCollisionEnter(other);
}

void EnemyScript::OnCollisionStay(class Collider* other)
{
	Script::OnCollisionStay(other);
}

void EnemyScript::OnCollisionExit(class Collider* other)
{
	Script::OnCollisionExit(other);
}
