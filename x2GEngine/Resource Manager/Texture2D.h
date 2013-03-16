
#pragma once
#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include "IAsset.h"
#include "Texture.h"
#include "IRenderer.h"

/**
 * \namespace	Graphics
 *
 * \brief	.
 */

namespace Graphics
{
	//enum imageTypes {X2_RGB, X2_RGBA};

	class IRenderer;
	class Texture;
	class Texture2D;
	enum imageTypes;
	enum textureType;

	/**
	 * \class	Texture2D
	 *
	 * \brief	Texture 2 d.
	 *
	 * \author	Matthew Vlietstra
	 * \date	25/03/2012
	 */

	class Texture2D : public Texture
	{
	public:

		/**
		 * \fn	Texture2D::Texture2D(int width, int height, imageTypes type, unsigned char *texture);
		 *
		 * \brief	Constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 *
		 * \param	width		   	The width.
		 * \param	height		   	The height.
		 * \param	type		   	The type.
		 * \param [in,out]	texture	If non-null, the texture.
		 */

		Texture2D(int width, int height, imageTypes type, unsigned char *texture);

		/**
		 * \fn	Texture2D::~Texture2D();
		 *
		 * \brief	Destructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 */

		~Texture2D();

		/**
		 * \fn	virtual textureType Texture2D::GetTextureType();
		 *
		 * \brief	Gets the texture type.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 *
		 * \return	The texture type.
		 */

		virtual textureType GetTextureType();

		/**
		 * \fn	virtual void Texture2D::Bind();
		 *
		 * \brief	Binds this object.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
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
		 * \fn	Texture2D::Texture2D();
		 *
		 * \brief	Default constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 */

		Texture2D();
	};

}


#endif