#pragma once
#include "Component.h"
#include <d2d1.h>

#include "Texture.h"

class SpriteRenderer : public Component
{
public:
	SpriteRenderer();
	~SpriteRenderer();

	void Initialize() override;
	void Update()  override;
	void LateUpdate()  override;
	void Render()  override;

	void SetTexture(Texture* texture) { m_texture = texture; }
private:
	Texture* m_texture;
};

