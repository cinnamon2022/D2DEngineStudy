#include "GameObject.h"

GameObject::GameObject()
{
	mComponents.resize((size_t)Component::eComponentType::End);

}

GameObject::~GameObject()
{
	for (Component* comp : mComponents)
	{
		delete comp;
		comp = nullptr;
	}
}
void GameObject::Initialize()
{
	for (Component* comp : mComponents)
	{
		if (comp == nullptr)
			continue;
		comp->Initialize();
	}
}
void GameObject::Update()
{
	for (Component* comp : mComponents)
	{
		if (comp == nullptr)
			continue;
		comp->Update();
	}
}

void GameObject::LateUpdate()
{
	for (Component* comp : mComponents)
	{
		if (comp == nullptr)
			continue;
		comp->LateUpdate();
	}
}

void GameObject::Render()
{
	for (Component* comp : mComponents)
	{
		if (comp == nullptr)
			continue;
		comp->Render();
	}
}
