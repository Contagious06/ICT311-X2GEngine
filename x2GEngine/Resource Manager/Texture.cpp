#include "Texture.h"



Graphics::Texture::Texture( int width, int height, int depth, imageTypes type, unsigned char *texture )
{
	m_width = width;
	m_height = height;
	m_imageType = type;
	m_depth = depth;
	m_texture = texture;
	m_textureID = 0;
}

Graphics::Texture::Texture()
{
	m_textureID = 0;
	m_width = 0;
	m_height = 0;
	m_imageType = X2_RGB;
	m_depth = 0;
	m_texture = nullptr;
}

Graphics::Texture::~Texture()
{
	if (m_texture != nullptr)
	{
		delete m_texture;
	}

	if (m_textureID != 0)
	{
		gs_renderer->ClearTexture(m_textureID); // remove the texture from the GPU.
	}
}

int Graphics::Texture::GetHeight()
{
	return m_height;
}

int Graphics::Texture::GetWidth()
{
	return m_width;
}

Graphics::imageTypes Graphics::Texture::GetImageType()
{
	return m_imageType;
}

unsigned int Graphics::Texture::GetTextureID()
{
	return m_textureID;
}

void Graphics::Texture::SetTextureID( unsigned int id )
{
	m_textureID = id;
}

unsigned char * Graphics::Texture::GetTexture()
{
	return m_texture;
}

void Graphics::Texture::Clear()
{
	if (m_texture != nullptr)
	{
		delete m_texture;
	}
	m_texture = nullptr;
}

void Graphics::Texture::Unbind()
{
	gs_renderer->UnbindTexture();
}
