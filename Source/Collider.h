#pragma once
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

	virtual void OnCollisionEnter(Collider* other);
	virtual void OnCollisionStay(Collider* other);
	virtual void OnCollisionExit(Collider* other);

	DirectX::SimpleMath::Vector2 GetOffset() { return m_offset; }
	void SetOffset(DirectX::SimpleMath::Vector2 offset) {m_offset = offset;}
	DirectX::SimpleMath::Vector2 GetSize() { return m_size; }
	void SetSize(DirectX::SimpleMath::Vector2 size) { m_size = size; }
	UINT32 GetID() { return m_id; }

public:
	static UINT32 g_collisionID;
	UINT32 m_id;

private:
	DirectX::SimpleMath::Vector2 m_offset;
	DirectX::SimpleMath::Vector2 m_size;


};
