#include "Texture3D.h"

Graphics::Texture3D::Texture3D( int width, int height, int depth, imageTypes type, unsigned char *texture ) : Texture(width, height, depth, type, texture)
{

}

Graphics::Texture3D::Texture3D()
{

}

Graphics::Texture3D::~Texture3D()
{

}

Graphics::textureType Graphics::Texture3D::GetTextureType()
{
	return X2_TEXTURE3D;
}

void Graphics::Texture3D::Bind()
{
	Bind(0);
}

void Graphics::Texture3D::Bind( int activeTexture )
{
	if (m_textureID == 0)
	{
		gs_renderer->BindTexture3D(m_textureID, activeTexture, m_imageType, m_width, m_height, m_depth, m_texture);
		Clear();
	}
	gs_renderer->BindTexture3D(m_textureID, activeTexture, m_imageType, m_width, m_height, m_depth, m_texture);
}
