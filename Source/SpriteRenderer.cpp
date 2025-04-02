#include "SpriteRenderer.h"
#include "GameObject.h"
#include "MyD2D.h"
#include "Transform.h"

SpriteRenderer::SpriteRenderer() 
{
}
SpriteRenderer::~SpriteRenderer()
{
	delete m_bitmap;
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
	Transform* tr = GetOwner()->GetComponent<Transform>();
	DirectX::SimpleMath::Vector2 pos = tr->GetPosition();
	DirectX::SimpleMath::Vector2 size = tr->GetSize();
	D2D::GetInstance().GetRenderTarget()->DrawBitmap(m_bitmap, { pos.x,pos.y,pos.x + size.x,pos.y + size.y });
}

void SpriteRenderer::ImageLoad(const std::wstring& path)
{
	D2D::GetInstance().CreateD2DBitmapFromFile(path.c_str(), &m_bitmap);
} 