#include "SpriteRenderer.h"
#include "GameObject.h"
#include "MyD2D.h"
#include "Transform.h"

SpriteRenderer::SpriteRenderer() 
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
	Transform* tr = GetOwner()->GetComponent<Transform>();
	DirectX::SimpleMath::Vector2 pos = tr->GetPosition();
	D2D::GetInstance().GetRenderTarget()->DrawBitmap(D2D::GetInstance().GetBitmap());
}

void SpriteRenderer::ImageLoad(const std::wstring& path)
{
	D2D::GetInstance().LoadBitmapImg(path.c_str());
} 