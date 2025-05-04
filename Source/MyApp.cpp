#include "MyApp.h"
#include <Windows.h>
#include <d2d1.h>
#include <d2d1_1helper.h>

#include "MyD2D.h"
#include "InputSystem.h"
#include "TimeSystem.h"
#include "SceneManager.h"
#include "CollisionManager.h"

#pragma comment(lib,"d2d1.lib")
#pragma comment(lib,"windowscodecs.lib")

void MyApp::Initialize(HINSTANCE hInstance, HWND hwnd)
{
	m_hwnd = hwnd;
	D2D::GetInstance().InitDirect2D(hwnd);
	CollisionManager::GetInstance().Initialize();
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
	TimeSystem::GetInstance().Tick();
	CollisionManager::GetInstance().Update();
	SceneManager::Update();
	InputSystem::GetInstance().Update();
}

void MyApp::LateUpdate()
{
	CollisionManager::GetInstance().LateUpdate();
	SceneManager::LateUpdate();
}

void MyApp::Render()
{
	D2D::GetInstance().GetRenderTarget()->BeginDraw();
	D2D::GetInstance().GetRenderTarget()->Clear(D2D1::ColorF(D2D1::ColorF::Black));
	D2D::GetInstance().GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());
	CollisionManager::GetInstance().Render();
	SceneManager::Render();
	D2D::GetInstance().GetRenderTarget()->EndDraw();
}
