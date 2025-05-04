#pragma once
#include <bitset>
#include <directxtk/SimpleMath.h>

#include "Component.h"

class Collider : public Component
{
public:
	Collider();
	~Collider();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();

	DirectX::SimpleMath::Vector2 GetOffset() { return m_offset; }
	void SetOffset(DirectX::SimpleMath::Vector2 offset) {m_offset = offset;}

private:
	DirectX::SimpleMath::Vector2 m_offset;
	DirectX::SimpleMath::Vector2 m_size;
};
