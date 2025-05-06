#include "Collider.h"

#include "Animator.h"
#include "Component.h"
#include "GameObject.h"
#include "MyD2D.h"
#include "Script.h"
#include "Transform.h"

UINT32 Collider::g_collisionID = 1;

Collider::Collider()
    : Component(eComponentType::Collider)
{
    m_id = g_collisionID++;
    m_size = DirectX::SimpleMath::Vector2(1, 1);
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

void Collider::OnCollisionEnter(Collider* other)
{
    Script* script = GetOwner()->GetComponent<Script>();
    script->OnCollisionEnter(other);
}

void Collider::OnCollisionStay(Collider* other)
{
    Script* script = GetOwner()->GetComponent<Script>();
    script->OnCollisionStay(other);
}

void Collider::OnCollisionExit(Collider* other)
{
    Script* script = GetOwner()->GetComponent<Script>();
    script->OnCollisionExit(other);
}

