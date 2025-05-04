#include "Texture.h"

#include <directxtk/SimpleMath.h>

#include "MyD2D.h"
#include "Transform.h"

Texture::Texture() : Resource (eResourceType::Texture)
{
	m_bitmap = nullptr;
	m_width = 0.f;
	m_height = 0.f;
}
Texture::~Texture()
{
}

void Texture::Load(const std::wstring& path)
{
	D2D::GetInstance().CreateD2DBitmapFromFile(path.c_str(), &m_bitmap);
	m_width = m_bitmap->GetSize().width;
	m_height = m_bitmap->GetSize().height;
}
