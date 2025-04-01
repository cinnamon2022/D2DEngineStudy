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

	//  D2D 개체 인터페이스 포인터 변수
	ID2D1Factory* g_pD2DFactory;
	ID2D1HwndRenderTarget* g_pRenderTarget;

	// D2D1비트맵 생성을 위한 이미지 처리 인터페이스
	IWICImagingFactory* g_pWICFactory;

	ID2D1Bitmap* g_pD2DBitmap = nullptr;



	std::vector<GameObject*> m_gameObject;
};

