#include "Texture2D.h"
#include "RendererSingleton.h"

namespace Graphics
{
	



	Texture2D::Texture2D( int width, int height, imageTypes type, unsigned char *texture ) : Texture(width, height, 1, type, texture)
	{

	}

	Texture2D::~Texture2D()
	{

	}

	Graphics::textureType Texture2D::GetTextureType()
	{
		return X2_TEXTURE2D;
	}

	void Texture2D::Bind()
	{
		Bind(0);
	}
	
	void Texture2D::Bind(int activeTexture)
	{
		if(m_textureID == 0)
		{
			gs_renderer->BindTexture2D(m_textureID, activeTexture, m_imageType, m_width, m_height, m_texture); //Transfer texture to the GPU (if id is == 0), if not it just binds it.
			Clear();
		}
		gs_renderer->BindTexture2D(m_textureID,activeTexture, m_imageType, m_width, m_height, m_texture);
	}


}