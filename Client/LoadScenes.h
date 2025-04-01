#pragma once
#include "../Source/SceneManager.h"
#include "Stage1.h"
#include "StartScene.h"

void LoadScenes()
{
	SceneManager::CreateScene<StartScene>(L"StartScene");
	SceneManager::CreateScene<Stage1>(L"Stage1");

	SceneManager::SetActiveScene(L"StartScene");
	//SceneManager::SetActiveScene(L"Stage1"); 
}
