#include "Animation.h"

#include "Animator.h"
#include "GameObject.h"
#include "MyD2D.h"
#include "TimeSystem.h"
#include "Transform.h"

Animation::Animation(): Resource(Resource::eResourceType::Animation)
{
	m_frameIndex = -1;
	m_duration = 0.0f;
	m_bComplete = false;
	m_animator = nullptr;
	m_texture = nullptr;
}

Animation::~Animation()
{
}

void Animation::Load(const std::wstring& path)
{
}

void Animation::Update()
{
	if (m_bComplete)
		return;
	m_duration += TimeSystem::GetInstance().DeltaTime();
	if (m_duration > m_animationSheet[m_frameIndex].duration)
	{
		if (m_frameIndex < m_animationSheet.size() - 1)
		{
			m_frameIndex++;
			m_duration = 0.0f;
		}
		else
			m_bComplete = true;
	}
}

void Animation::Render()
{
	if (m_texture == nullptr)
		return;

	GameObject* owner = m_animator->GetOwner();
	Transform* tr = owner->GetComponent<Transform>();
	DirectX::SimpleMath::Vector2 pos = tr->GetPosition();

	Frame sprite = m_animationSheet[m_frameIndex];
	D2D::GetInstance().GetRenderTarget()->DrawBitmap(m_texture->GeImage(),
		{ pos.x,pos.y,pos.x + sprite.size.x,pos.y + sprite.size.y },
		1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		{ sprite.lefttop.x,sprite.lefttop.y, sprite.lefttop.x + sprite.size.x,sprite.lefttop.y + sprite.size.y }
	);

}

void Animation::CreateAnimation(const std::wstring& name, Texture* animationImage,
                                DirectX::SimpleMath::Vector2 lefttop, DirectX::SimpleMath::Vector2 size, DirectX::SimpleMath::Vector2 offset,
                                UINT animationLength, float duration)
{
	m_texture = animationImage;
	for (int i = 0; i < animationLength; i++)
	{
		Frame sprite;
		sprite.lefttop.x = lefttop.x + size.x * i;
		sprite.lefttop.y = lefttop.y;
		sprite.size = size;
		sprite.offset = offset;
		sprite.duration = duration;

		m_animationSheet.push_back(sprite);
	}
}

void Animation::Reset()
{
	m_duration = 0.0f;
	m_frameIndex = 0;
	m_bComplete = false;
}
