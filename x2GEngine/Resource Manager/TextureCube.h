#pragma once
#ifndef TEXTURECUBE_H
#define TEXTURECUBE_H

#include "IAsset.h"
#include "Texture.h"

/**
 * \namespace	Graphics
 *
 * \brief	.
 */

namespace Graphics
{
	class Texture;
	class IRenderer;
	enum imageTypes;
	enum textureType;

	/**
	 * \class	TextureCube
	 *
	 * \brief	Texture cube.
	 *
	 * \author	Matthew Vlietstra
	 * \date	24/03/2012
	 */

	class TextureCube : public Texture
	{
	public:

		/**
		 * \fn	TextureCube::TextureCube(int width, int height, imageTypes type, unsigned char *texture);
		 *
		 * \brief	Constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \param	width		   	The width.
		 * \param	height		   	The height.
		 * \param	type		   	The type.
		 * \param [in,out]	texture	If non-null, the texture.
		 */

		TextureCube(int width, int height, imageTypes type, unsigned char *texture);

		/**
		 * \fn	TextureCube::~TextureCube();
		 *
		 * \brief	Destructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 */

		~TextureCube();

		/**
		 * \fn	virtual textureType TextureCube::GetTextureType();
		 *
		 * \brief	Gets the texture type.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \return	The texture type.
		 */

		virtual textureType GetTextureType();

		/**
		 * \fn	virtual void TextureCube::Bind();
		 *
		 * \brief	Binds this object.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 */

		virtual void Bind();

		/**
		 * \brief	Binds a texture
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/05/2012
		 *
		 * \param	activeTexture	The active texture.
		 */

		virtual void Bind(int activeTexture);

	private:

		/**
		 * \fn	TextureCube::TextureCube();
		 *
		 * \brief	Default constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 */

		TextureCube();
	};
}


#endif