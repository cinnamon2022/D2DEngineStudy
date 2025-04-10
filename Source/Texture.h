#pragma once
#include <d2d1.h>
#include "Resource.h"
// 2D �̹����� �ǹ��Ѵ�.

class Texture : public Resource
{
public:
	Texture();
	~Texture();

	virtual void Load(const std::wstring& path) override;
	float GetWidth() { return m_width; }
	float GetHeight() { return m_height; }
	ID2D1Bitmap* GeImage() { return m_bitmap; }
	
private:
	ID2D1Bitmap* m_bitmap;
	float m_width;
	float m_height;
};

