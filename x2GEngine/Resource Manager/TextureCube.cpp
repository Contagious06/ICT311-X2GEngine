#include "TextureCube.h"

Graphics::TextureCube::TextureCube( int width, int height, imageTypes type, unsigned char *texture ) : Texture(width, height, 6, type, texture)
{

}

Graphics::TextureCube::TextureCube()
{

}

Graphics::TextureCube::~TextureCube()
{

}

Graphics::textureType Graphics::TextureCube::GetTextureType()
{
	return X2_TEXTURECUBE;
}

void Graphics::TextureCube::Bind()
{
	Bind(0);
}

void Graphics::TextureCube::Bind( int activeTexture )
{
	if (m_textureID == 0)
	{
		gs_renderer->BindTextureCube(m_textureID, activeTexture, m_imageType, m_width, m_height, m_texture); //Transfer texture to the GPU (if id is == 0), if not it binds it.
		Clear();
	}
	gs_renderer->BindTextureCube(m_textureID, activeTexture, m_imageType, m_width, m_height, m_texture); //if the id's not 0 it binds the image
}
