#include "Script.h"
#include "Collider.h"

Script::Script() : Component(eComponentType::Script)
{
}

Script::~Script()
{
}

void Script::Initialize()
{
	Component::Initialize();
}

void Script::Update()
{
	Component::Update();
}

void Script::LateUpdate()
{
	Component::LateUpdate();
}

void Script::Render()
{
	Component::Render();
}

void Script::OnCollisionEnter(Collider* other)
{
}

void Script::OnCollisionStay(Collider* other)
{
}

void Script::OnCollisionExit(Collider* other)
{
}