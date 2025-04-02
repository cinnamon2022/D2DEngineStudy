#pragma once
#include "Scene.h"
#include <map>

class SceneManager
{
public:

	template<typename T>
	static Scene* CreateScene(const std::wstring& name)
	{
		T* scene = new T();
		scene->SetName(name);
		scene->Initialize();

		m_scenes.insert(std::make_pair(name, scene));
		return scene;
	}

	static Scene* SetActiveScene(const std::wstring& name)
	{
		if (m_activeScene)
			m_activeScene->Exit();

		std::map<const std::wstring, Scene*>::iterator it = m_scenes.find(name);

		if (it == m_scenes.end())
		{
			return nullptr;
		}
		m_activeScene = it->second;
		m_activeScene->Enter();

		return m_activeScene;
	}
	static void Initialize();
	static void Update();
	static void LateUpdate();
	static void Render();
private:
	static std::map<const std::wstring, Scene*> m_scenes;
	static Scene* m_activeScene;
};

