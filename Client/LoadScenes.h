#pragma once
#include "../Source/SceneManager.h"
#include "Stage1.h"

void LoadScenes()
{
	SceneManager::CreateScene<Stage1>(L"Stage1");


	SceneManager::SetActiveScene(L"Stage1"); 
}