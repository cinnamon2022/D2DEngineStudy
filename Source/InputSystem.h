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

	enum Axis { Vertical, Horizontal };
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

	enum PadType { Thumb, Trigger };
	struct GamePadState
	{
		enum Thumb { LX, LY, RX, RY, Thumb_END };
		enum Trigger { LT, RT, Trigger_END };
		float thumb[Thumb_END];
		float trigger[Trigger_END];
		unsigned short button;
	};
private:
	explicit InputSystem() = default;
	virtual ~InputSystem() = default;

public:
	void Update();
	bool Initialize(HINSTANCE hInstance, HWND hWnd);

public:
	bool IsKeyDown(BYTE keycord) const;
	bool IsKeyDown(Input::MouseState mouseState) const;

	bool IsKeyUp(BYTE keycord) const;
	bool IsKeyUp(Input::MouseState mouseState) const;

	bool IsKeyPress(BYTE keycord) const;
	bool IsKeyPress(Input::MouseState mouseState) const;

	bool IsMouseWheel(Input::MouseState mouseState) const;
	float GetAxis(Input::Axis type);
	float GetMouseMove(Input::MouseMove mouseMove) const;
	const DirectX::SimpleMath::Vector3& GetMousePosition() const { return _mousePosition; }

private:
	float ClampStickValue(short& value);
	float ClampTriggerValue(byte& value);

	BYTE						_oldKeyState[256]{};
	BYTE						_keyState[256]{};
	DIMOUSESTATE				_oldMouseState{};
	DIMOUSESTATE				_mouseState{};
	GamePadState				_oldPadState{};
	GamePadState				_padState{};

	DirectX::SimpleMath::Vector3 _mousePosition;
	LPDIRECTINPUT8				_pInputSDK = nullptr;
	LPDIRECTINPUTDEVICE8		_pKeyBoard = nullptr;
	LPDIRECTINPUTDEVICE8		_pMouse = nullptr;

	HWND m_hwnd;
};
