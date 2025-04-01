#pragma once
#include "Component.h"
#include <d2d1.h>
class SpriteRenderer : public Component
{
public:
	SpriteRenderer();
	~SpriteRenderer();

	void Initialize() override;
	void Update()  override;
	void LateUpdate()  override;
	void Render()  override;
	void ImageLoad(const std::wstring& path);

private:
	ID2D1Bitmap* m_bitmap;
};

