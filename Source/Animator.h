#pragma once
#include <map>
#include <unordered_map>
#include <directxtk/SimpleMath.h>

#include "Component.h"
#include "Animation.h"

class Animator :public Component
{
public:
	Animator();
	~Animator();

	void Initialize();
	void Update();
	void LateUpdate();
	void Render();

	void CreateAnimation
	(
		const std::wstring& name,
		Texture* animationImage,
		DirectX::SimpleMath::Vector2 lefttop,
		DirectX::SimpleMath::Vector2 size,
		DirectX::SimpleMath::Vector2 offset,
		UINT animationLength,
		float duration
	);

	Animation* FindAnimation(const std::wstring& name);
	void PlayAnimation(const std::wstring& name, bool loop = true );
private:
	std::unordered_map<std::wstring, Animation*> m_animations;
	bool m_bLoop;
	Animation* m_currentAnimation;
};

