#pragma once
#include <vector>
#include <directxtk/SimpleMath.h>

#include "Component.h"

class Transform : public Component
{
public:
	Transform();
	~Transform();

	void Initialize() override;
	void Update()  override;
	void LateUpdate()  override;
	void Render()  override;

	void SetPosition(DirectX::SimpleMath::Vector2 pos) { m_pos.x = pos.x;  m_pos.y = pos.y; }
	void SetSize(DirectX::SimpleMath::Vector2 size) { m_scale.x = size.x;  m_scale.y = size.y; }

	DirectX::SimpleMath::Vector2 GetPosition() { return  m_pos; }
	DirectX::SimpleMath::Vector2 GetSize() { return  m_scale; }
	float GetRotation() { return  m_rotation; }

private:
	DirectX::SimpleMath::Vector2 m_pos;
	DirectX::SimpleMath::Vector2 m_scale;
	float m_rotation;
};
