#pragma once

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "dinput8.lib")

#include <directxtk/SimpleMath.h>

namespace Input
{
	enum MouseState { DIM_LB, DIM_RB, DIM_WM, DIM_END, DIM_WHUP = 120, DIM_WHDN = -120 };
	enum MouseMove { DIM_X, DIM_Y };
}

class InputSystem
{
	struct ButtonQueue
	{
		ButtonQueue(unsigned short old, unsigned short curr)
			: old(old), curr(curr), elapsed(0.f) {
		}
		unsigned short old;
		unsigned short curr;
		float elapsed;
	};
public:

	static InputSystem& GetInstance();

private:
	explicit InputSystem() = default;
	virtual ~InputSystem() = default;

public:
	void Update();
	bool Initialize(HINSTANCE hInstance, HWND hWnd);

public:
	bool IsKeyDown(BYTE key) const;
	bool IsKeyDown(Input::MouseState mouseState) const;

	bool IsKeyUp(BYTE key) const;
	bool IsKeyUp(Input::MouseState mouseState) const;

	bool IsKeyPress(BYTE key) const;
	bool IsKeyPress(Input::MouseState mouseState) const;

	bool IsMouseWheel(Input::MouseState mouseState) const;
	float GetMouseMove(Input::MouseMove mouseMove) const;
	const DirectX::SimpleMath::Vector3& GetMousePosition() const { return _mousePosition; }

private:
	float ClampStickValue(short& value);
	float ClampTriggerValue(byte& value);

	BYTE						_oldKeyState[256]{};
	BYTE						_keyState[256]{};
	DIMOUSESTATE				_oldMouseState{};
	DIMOUSESTATE				_mouseState{};

	DirectX::SimpleMath::Vector3 _mousePosition;
	LPDIRECTINPUT8				_pInputSDK = nullptr;
	LPDIRECTINPUTDEVICE8		_pKeyBoard = nullptr;
	LPDIRECTINPUTDEVICE8		_pMouse = nullptr;

	HWND m_hwnd;
};
