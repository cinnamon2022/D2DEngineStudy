#pragma once
#include <Windows.h>
#include <d2d1.h>
#include <d2d1_1helper.h>
#include <vector>

#include "GameObject.h"

class MyApp
{
public:
	void Initialize(HWND hwnd);
	void Run();

	void Update();
	void LateUpdate();
	void Render();

private:
	HWND m_hwnd;

	std::vector<GameObject*> m_gameObject;
};

