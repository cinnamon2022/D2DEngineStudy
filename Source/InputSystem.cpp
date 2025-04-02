#include <Windows.h>
#include "InputSystem.h"

#include <algorithm>
#include <directxtk/SimpleMath.h>
#include <cassert>

using namespace DirectX;
using namespace DirectX::SimpleMath;

InputSystem& InputSystem::GetInstance()
{
	static InputSystem instance;
	return instance;
}

void InputSystem::Update()
{
    memcpy(&_oldKeyState, &_keyState, sizeof(_keyState));
    memcpy(&_oldMouseState, &_mouseState, sizeof(_mouseState));

    _pKeyBoard->GetDeviceState(sizeof(_keyState), &_keyState);
    _pMouse->GetDeviceState(sizeof(_mouseState), &_mouseState);

    POINT mousePoint{};
    GetCursorPos(&mousePoint);
    ScreenToClient(m_hwnd, &mousePoint);

    _mousePosition = { (float)mousePoint.x, (float)mousePoint.y, 0.f };
}

bool InputSystem::Initialize(HINSTANCE hInstance, HWND hWnd)
{
	m_hwnd = hWnd;
    if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&_pInputSDK, NULL)))
        return false;

    if (FAILED(_pInputSDK->CreateDevice(GUID_SysKeyboard, &_pKeyBoard, nullptr)))
        return false;

    if (FAILED(_pKeyBoard->SetDataFormat(&c_dfDIKeyboard)))
        return false;

    if (FAILED(_pKeyBoard->SetCooperativeLevel(hWnd, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE)))
        return false;

    if (FAILED(_pKeyBoard->Acquire()))
        return false;

    if (FAILED(_pInputSDK->CreateDevice(GUID_SysMouse, &_pMouse, nullptr)))
        return false;

    if (FAILED(_pMouse->SetDataFormat(&c_dfDIMouse)))
        return false;

    if (FAILED(_pMouse->SetCooperativeLevel(hWnd, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE)))
        return false;

    if (FAILED(_pMouse->Acquire()))
        return false;

    return true;
}

bool InputSystem::IsKeyDown(byte key) const
{
    return !(_oldKeyState[key] & 0x80) && (_keyState[key] & 0x80);
}

bool InputSystem::IsKeyDown(Input::MouseState mouseState) const
{
    return !(_oldMouseState.rgbButtons[mouseState] & 0x80) && (_mouseState.rgbButtons[mouseState] & 0x80);
}

bool InputSystem::IsKeyUp(byte key) const
{
    return (_oldKeyState[key] & 0x80) && !(_keyState[key] & 0x80);
}

bool InputSystem::IsKeyUp(Input::MouseState mouseState) const
{
    return (_oldMouseState.rgbButtons[mouseState] & 0x80) && !(_mouseState.rgbButtons[mouseState] & 0x80);
}


bool InputSystem::IsKeyPress(byte key) const
{
    if (_keyState[key] & 0x80)
        return true;

    return false;
}

bool InputSystem::IsKeyPress(Input::MouseState mouseState) const
{
    if (_mouseState.rgbButtons[mouseState] & 0x80)
        return true;

    return false;
}

bool InputSystem::IsMouseWheel(Input::MouseState mouseState) const
{
    switch (mouseState)
    {
    case Input::DIM_WHDN:
        if (0 > _mouseState.lZ) return true;
        break;
    case Input::DIM_WHUP:
        if (0 < _mouseState.lZ) return true;
        break;
    }

    return false;
}

float InputSystem::GetMouseMove(Input::MouseMove mouseMove) const
{
    return (float)*(&_mouseState.lX + mouseMove);
}


float InputSystem::ClampStickValue(short& value)
{
    return std::clamp(static_cast<float>(value), -1.f, 1.f);
}

float InputSystem::ClampTriggerValue(byte& value)
{
    return std::clamp(static_cast<float>(value), 0.f, 1.f);
}
