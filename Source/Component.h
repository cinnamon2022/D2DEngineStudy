#pragma once
#include "Entity.h"

class GameObject;
class Component : public Entity
{
public:
	enum class	eComponentType
	{
		Transform,
		Script,
		SpriteRenderer,
		Animator,
		End
	};
	Component(eComponentType m_type);
	~Component();  

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();

	void SetOwner(GameObject* owner) { mOwner = owner; };
	GameObject* GetOwner() { return mOwner; }
	eComponentType GetType() { return m_type; }

private:
	GameObject* mOwner;
	eComponentType m_type;
};
