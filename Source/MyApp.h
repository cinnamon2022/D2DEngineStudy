#pragma once
#include <Windows.h>
#include <d2d1.h>
#include <d2d1_1helper.h>
#include <vector>

class MyApp
{
public:
	void Initialize(HINSTANCE hInstance, HWND hwnd);
	void Run();

	void Update();
	void LateUpdate();
	void Render();

private:
	HWND m_hwnd;
};

