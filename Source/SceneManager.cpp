#include "SceneManager.h"

std::map<const std::wstring, Scene*> SceneManager::m_scenes = {};
Scene* SceneManager::m_activeScene = nullptr;

void SceneManager::Initialize()
{
}

void SceneManager::Update()
{
	m_activeScene->Update();
}

void SceneManager::LateUpdate()
{
	m_activeScene->LateUpdate();
}

void SceneManager::Render()
{
	m_activeScene->Render();
}