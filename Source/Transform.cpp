#include "Transform.h"
Transform::Transform()
	:Component(eComponentType::Transform),
	m_pos(0, 0),
	m_scale(1, 1),
	m_rotation(0)
{
}
Transform::~Transform()
{
}
void Transform::Initialize()
{
}
void Transform::Update()
{
}
void Transform::LateUpdate()
{
}
void Transform::Render()
{
}