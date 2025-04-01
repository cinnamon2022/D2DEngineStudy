#pragma once
#include <d2d1.h>
#include <d2d1_1.h>
#include <windows.h>
class D2D
{
public:
	static D2D& GetInstance();

	BOOL InitDirect2D(HWND hwnd);
	void UninitDirect2D();

	HRESULT CreateD2DBitmapFromFile(const WCHAR* szFilePath, ID2D1Bitmap** ppID2D1Bitmap);

	ID2D1Factory* GetFactory() { return m_factory; }
	ID2D1HwndRenderTarget* GetRenderTarget() { return m_renderTarget; }
	IWICImagingFactory* GetImgFactory() { return m_imgFactory; }

private:
	D2D() {}  // private 생성자
	~D2D(); // private 소멸자

	// 복사 및 대입 연산자 삭제 (싱글톤 유지)
	D2D(const D2D&) = delete;
	D2D& operator=(const D2D&) = delete;

	ID2D1Factory* m_factory;
	ID2D1HwndRenderTarget* m_renderTarget;

	IWICImagingFactory* m_imgFactory;

	HWND m_hwnd;
};

