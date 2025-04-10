#include "SpriteRenderer.h"
#include "GameObject.h"
#include "MyD2D.h"
#include "Transform.h"

SpriteRenderer::SpriteRenderer()
:Component(eComponentType::SpriteRenderer),
m_texture(nullptr)
{
}
SpriteRenderer::~SpriteRenderer()
{

}
void SpriteRenderer::Initialize()
{
}
void SpriteRenderer::Update()
{
}
void SpriteRenderer::LateUpdate()
{
}
void SpriteRenderer::Render()
{
	if (m_texture == nullptr)
		assert(false);
	Transform* tr = GetOwner()->GetComponent<Transform>();
	DirectX::SimpleMath::Vector2 pos = tr->GetPosition();
	//DirectX::SimpleMath::Vector2 size = tr->GetSize();
	DirectX::SimpleMath::Vector2 size = { m_texture->GetWidth(),m_texture->GetHeight() };
	D2D::GetInstance().GetRenderTarget()->DrawBitmap(m_texture->GeImage(), { pos.x,pos.y,pos.x + size.x,pos.y + size.y });
}
