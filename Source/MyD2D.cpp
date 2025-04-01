#include "MyD2D.h"

#include <windows.h>
#include <wincodec.h>
#include <d2d1.h>
#include <d2d1_1.h>
#include <d2d1_1helper.h>

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib,"windowscodecs.lib")

D2D& D2D::GetInstance()
{
    static D2D instance;  // 정적 지역 변수 (프로그램 종료 시 자동 소멸)
    return instance;
}

BOOL D2D::InitDirect2D(HWND hwnd)
{
    m_hwnd = hwnd;
    HRESULT hr = S_OK;
    // COM 사용 시작
    hr = CoInitialize(NULL);
    if (FAILED(hr))
        return FALSE;

    hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_factory);
    if (FAILED(hr))
        return FALSE;

    RECT rc;
    GetClientRect(m_hwnd, &rc);

    D2D1_SIZE_U size = D2D1::SizeU(
        rc.right - rc.left,
        rc.bottom - rc.top);

    // Create a Direct2D render target.
    hr = m_factory->CreateHwndRenderTarget(
        D2D1::RenderTargetProperties(),
        D2D1::HwndRenderTargetProperties(m_hwnd, size),
        &m_renderTarget);

    if (FAILED(hr))
        return FALSE;

    if (SUCCEEDED(hr))
    {
        // Create WIC factory
        hr = CoCreateInstance(
            CLSID_WICImagingFactory,
            NULL,
            CLSCTX_INPROC_SERVER,
            IID_PPV_ARGS(&m_imgFactory)
        );
    }
    return TRUE;
}

void D2D::UninitDirect2D()
{
    if (m_renderTarget) m_renderTarget->Release();
    if (m_factory) m_factory->Release();

    // COM 사용 끝
    CoUninitialize();
}

HRESULT D2D::CreateD2DBitmapFromFile(const WCHAR* szFilePath, ID2D1Bitmap** ppID2D1Bitmap)
{
    HRESULT hr;
    // Create a decoder
    IWICBitmapDecoder* pDecoder = NULL;
    IWICFormatConverter* pConverter = NULL;

    hr = m_imgFactory->CreateDecoderFromFilename(
        szFilePath,                      // Image to be decoded
        NULL,                            // Do not prefer a particular vendor
        GENERIC_READ,                    // Desired read access to the file
        WICDecodeMetadataCacheOnDemand,  // Cache metadata when needed
        &pDecoder                        // Pointer to the decoder
    );

    // Retrieve the first frame of the image from the decoder
    IWICBitmapFrameDecode* pFrame = NULL;
    if (SUCCEEDED(hr))
    {
        hr = pDecoder->GetFrame(0, &pFrame);
    }

    //Step 3: Format convert the frame to 32bppPBGRA
    if (SUCCEEDED(hr))
    {
        hr = m_imgFactory->CreateFormatConverter(&pConverter);
    }

    if (SUCCEEDED(hr))
    {
        hr = pConverter->Initialize(
            pFrame,                          // Input bitmap to convert
            GUID_WICPixelFormat32bppPBGRA,   // Destination pixel format
            WICBitmapDitherTypeNone,         // Specified dither pattern
            NULL,                            // Specify a particular palette 
            0.f,                             // Alpha threshold
            WICBitmapPaletteTypeCustom       // Palette translation type
        );
    }

    if (SUCCEEDED(hr))
    {
        hr = m_renderTarget->CreateBitmapFromWicBitmap(pConverter, NULL, ppID2D1Bitmap);
    }


    // 파일을 사용할때마다 다시 만든다.
    if (pConverter)
        pConverter->Release();

    if (pDecoder)
        pDecoder->Release();

    if (pFrame)
        pFrame->Release();

    return hr;
}

D2D::~D2D()
{
	UninitDirect2D();
}
