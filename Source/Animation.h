#pragma once
#include <string>
#include <vector>
#include <directxtk/SimpleMath.h>

#include "Texture.h"
#include "Resource.h"

class Animator;
class Animation : public Resource
{
public:

	struct Frame
	{
		DirectX::SimpleMath::Vector2 lefttop;
		DirectX::SimpleMath::Vector2 size;
		DirectX::SimpleMath::Vector2 offset;
		float duration;
		Frame()
			:lefttop(0, 0),
			size(0, 0),
			offset(0, 0),
			duration(0)
		{
		}
	};
	Animation();
	~Animation();

	void Load(const std::wstring& path);
	void Update();
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
	void Reset();

	bool IsComplete() { return m_bComplete; }
	void SetAnimator(Animator* animator) { m_animator = animator; }
private:
	Animator* m_animator;
	Texture* m_texture;

	std::vector<Frame> m_animationSheet;

	int m_frameIndex;
	float m_duration;
	bool m_bComplete;
};

