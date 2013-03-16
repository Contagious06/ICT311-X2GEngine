
#pragma once
#ifndef TEXTURE3D_H
#define TEXTURE3D_H

#include "IAsset.h"
#include "Texture.h"

/**
 * \namespace	Graphics
 *
 * \brief	.
 */

namespace Graphics
{
	/**
	 * \class	Texture3D
	 *
	 * \brief	Texture 3 d.
	 *
	 * \author	Matthew Vlietstra
	 * \date	24/03/2012
	 */
	class Texture;
	class IRenderer;
	enum imageTypes;
	enum textureType;

	class Texture3D : public Texture
	{
	public:

		/**
		 * \fn	Texture3D::Texture3D(int width, int height, int depth, imageTypes type,
		 * 		unsigned char *texture);
		 *
		 * \brief	Constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \param	width		   	The width.
		 * \param	height		   	The height.
		 * \param	depth		   	The depth.
		 * \param	type		   	The type.
		 * \param [in,out]	texture	If non-null, the texture.
		 */

		Texture3D(int width, int height, int depth, imageTypes type, unsigned char *texture);

		/**
		 * \fn	Texture3D::~Texture3D();
		 *
		 * \brief	Destructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 */

		~Texture3D();

		/**
		 * \fn	virtual textureType Texture3D::GetTextureType();
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
		 * \fn	virtual void Texture3D::Bind();
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
		 * \fn	Texture3D::Texture3D();
		 *
		 * \brief	Default constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 */

		Texture3D();
	};
}


#endif