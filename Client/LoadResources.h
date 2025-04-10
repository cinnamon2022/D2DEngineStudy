#pragma once

#include "../Source/ResourceManager.h"
#include "../Source/Texture.h"

void LoadResources()
{
	ResourceManager::GetInstance().Load<Texture>(L"Bubble", L"../Resources/Bubble.png");
	ResourceManager::GetInstance().Load<Texture>(L"PlayerDie", L"../Resources/Die.png");
	ResourceManager::GetInstance().Load<Texture>(L"Enemy", L"../Resources/Enemy.png");
	ResourceManager::GetInstance().Load<Texture>(L"EnemyInBubble", L"../Resources/EnemyInBubble.png");
	ResourceManager::GetInstance().Load<Texture>(L"EnemyKill", L"../Resources/EnemyKill.png");
	ResourceManager::GetInstance().Load<Texture>(L"PlayerIdle", L"../Resources/Idle_left.png");
	ResourceManager::GetInstance().Load<Texture>(L"TitleLogo", L"../Resources/TitleLogo.png");
	ResourceManager::GetInstance().Load<Texture>(L"PlayerWalk", L"../Resources/Walk_left.png");

}

