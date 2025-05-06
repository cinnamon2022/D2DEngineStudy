#pragma once
#include "../Source/SceneManager.h"
#include "EndingScene.h"
#include "Stage1.h"
#include "Stage2.h"
#include "StartScene.h"
#include "WinScene.h"

void LoadScenes()
{
	SceneManager::CreateScene<StartScene>(L"StartScene");
	SceneManager::CreateScene<Stage1>(L"Stage1");
	SceneManager::CreateScene<Stage2>(L"Stage2");
	SceneManager::CreateScene<EndingScene>(L"EndingScene");
	SceneManager::CreateScene<WinScene>(L"WinScene");

	SceneManager::SetActiveScene(L"StartScene");
}
