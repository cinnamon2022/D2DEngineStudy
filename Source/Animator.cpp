#include "Animator.h"

Animator::Animator()
	:Component(eComponentType::Animator),
	m_bLoop(true),
	m_currentAnimation(nullptr)
{

}

Animator::~Animator()
{
}

void Animator::Initialize()
{
	Component::Initialize();
}

void Animator::Update()
{
	Component::Update();
	if (m_currentAnimation) // 현재의 애니메이션이 있으면 재생.
	{
		m_currentAnimation->Update();
		if (m_currentAnimation->IsComplete() && m_bLoop)
		{
			m_currentAnimation->Reset();
		}
	}
}


void Animator::LateUpdate()
{
	Component::LateUpdate();
}

void Animator::Render()
{
	Component::Render();
	if (m_currentAnimation)
	{
		m_currentAnimation->Render();
	}
}

void Animator::CreateAnimation
(
	const std::wstring& name,
	Texture* animationImage,
	DirectX::SimpleMath::Vector2 lefttop,
	DirectX::SimpleMath::Vector2 size, 
	DirectX::SimpleMath::Vector2 offset,
	UINT animationLength,
	float duration
)
{
	Animation* ani = nullptr;
	ani = FindAnimation(name);
	if (ani != nullptr)
		return;
	ani = new Animation();
	ani->CreateAnimation(name,  animationImage, lefttop, size, offset, animationLength, duration);
	ani->SetAnimator(this);
	m_animations.insert(std::make_pair(name, ani));
}

Animation* Animator::FindAnimation(const std::wstring& name)
{
	auto it = m_animations.find(name);
	if (it == m_animations.end())
		return nullptr;
	return it->second;
}

void Animator::PlayAnimation(const std::wstring& name, bool loop)
{
	Animation* ani = FindAnimation(name);
	if (ani == nullptr)
		return;
	m_currentAnimation = ani;
	m_currentAnimation->Reset();
	m_bLoop = loop;
}
