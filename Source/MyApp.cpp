#include "MyApp.h"
#include <Windows.h>
#include <d2d1.h>
#include <d2d1_1helper.h>

#include "MyD2D.h"
#include "InputSystem.h"
#include "SceneManager.h"

#pragma comment(lib,"d2d1.lib")
#pragma comment(lib,"windowscodecs.lib")

void MyApp::Initialize(HINSTANCE hInstance, HWND hwnd)
{
	m_hwnd = hwnd;
	D2D::GetInstance().InitDirect2D(hwnd);
	SceneManager::Initialize();
	InputSystem::GetInstance().Initialize(hInstance, hwnd);
}

void MyApp::Run()
{
	Update();
	LateUpdate();
	Render();
}

void MyApp::Update()
{
	SceneManager::Update();
	InputSystem::GetInstance().Update();
}

void MyApp::LateUpdate()
{
	SceneManager::LateUpdate();
}

void MyApp::Render()
{
	D2D::GetInstance().GetRenderTarget()->BeginDraw();
	D2D::GetInstance().GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());
	SceneManager::Render();
	D2D::GetInstance().GetRenderTarget()->EndDraw();
}
