#include "Collider.h"

#include "Animator.h"
#include "Component.h"
#include "GameObject.h"
#include "MyD2D.h"
#include "Transform.h"

Collider::Collider()
    : Component(eComponentType::Collider)
{
   
}

Collider::~Collider()
{
}
void Collider::Initialize()
{
}
void Collider::Update()
{
}
void Collider::LateUpdate()
{
}
void Collider::Render()
{
    Transform* transform = GetOwner()->GetComponent<Transform>();
    DirectX::SimpleMath::Vector2 position = transform->GetPosition();

#ifdef _DEBUG
    ID2D1SolidColorBrush* pBrush;
    D2D::GetInstance().GetRenderTarget()->CreateSolidColorBrush(
        D2D1::ColorF(D2D1::ColorF::Red), &pBrush);
    D2D::GetInstance().GetRenderTarget()->DrawRectangle(
        { position.x, position.y, position.x + 100, position.y + 100
        }, pBrush, 1.0f);

    pBrush->Release();
#endif
}

