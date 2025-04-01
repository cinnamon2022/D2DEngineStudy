#pragma once
#include <vector>
#include <directxtk/SimpleMath.h>

#include "Component.h"

struct Pos
{
	int m_x;
	int m_y;
};

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
	DirectX::SimpleMath::Vector2 GetPosition() { return  m_pos; }
	int GetX() { return  m_pos.x; }
	int GetY() { return m_pos.y; }

private:
	DirectX::SimpleMath::Vector2 m_pos;
};
