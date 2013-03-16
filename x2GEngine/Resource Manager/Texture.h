#pragma once

#ifndef TEXTURE_H
#define TEXTURE_H

#include "IAsset.h"
#include "IRenderer.h"
#include "RendererSingleton.h"

/**
 * \namespace	Graphics
 *
 * \brief	
 */

namespace Graphics
{
	class Texture;
	class Texture2D;
	class IRenderer;
	enum imageTypes;
	enum textureType;

	/**
	 * \class	Texture
	 *
	 * \brief	Texture.
	 *
	 * \author	Matthew Vlietstra
	 * \date	25/03/2012
	 */

	class Texture : public Content::IAsset
	{
	public:

		/**
		 * \fn	:::Texture(int width, int height, int depth, imageTypes type, unsigned char *texture);
		 *
		 * \brief	Constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 *
		 * \param	width		   	The width.
		 * \param	height		   	The height.
		 * \param	depth		   	The depth.
		 * \param	type		   	The type.
		 * \param [in,out]	texture	If non-null, the texture.
		 */

		Texture(int width, int height, int depth, imageTypes type, unsigned char *texture);

		/**
		 * \fn	virtual :::~Texture();
		 *
		 * \brief	Destructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 */

		virtual ~Texture();

		/**
		 * \fn	virtual textureType :::GetTextureType() = 0;
		 *
		 * \brief	Gets the texture type.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 *
		 * \return	The texture type.
		 */

		virtual textureType GetTextureType() = 0;

		/**
		 * \fn	virtual void :::Bind() = 0;
		 *
		 * \brief	Binds this object.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 */

		virtual void Bind() = 0;

		/**
		 *  \brief	Binds a texture
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/05/2012
		 *
		 * \param	activeTexture	The active texture.
		 */

		virtual void Bind(int activeTexture) = 0;

		/**
		 * \fn	int :::GetHeight();
		 *
		 * \brief	Gets the height.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 *
		 * \return	The height.
		 */

		void Unbind();

		/**
		 * \brief	Gets the height.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/05/2012
		 *
		 * \return	The height.
		 */

		int GetHeight();

		/**
		 * \fn	int :::GetWidth();
		 *
		 * \brief	Gets the width.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 *
		 * \return	The width.
		 */

		int GetWidth();

		/**
		 * \fn	imageTypes :::GetImageType();
		 *
		 * \brief	Gets the image type.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 *
		 * \return	The image type.
		 */

		imageTypes GetImageType();

		/**
		 * \fn	unsigned int :::GetTextureID();
		 *
		 * \brief	Gets the texture identifier.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 *
		 * \return	The texture identifier.
		 */

		unsigned int GetTextureID();

		/**
		 * \fn	void :::SetTextureID(unsigned int id);
		 *
		 * \brief	Sets a texture identifier.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 *
		 * \param	id	The identifier.
		 */

		void SetTextureID(unsigned int id);

		/**
		 * \fn	unsigned char :::*GetTexture();
		 *
		 * \brief	Gets the texture.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 *
		 * \return	null if it fails, else the texture.
		 */

		unsigned char *GetTexture();

		/**
		 * \fn	void :::Clear();
		 *
		 * \brief	Clears this object to its blank/initial state.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 */

		void Clear();

	private:


	protected:
		///< The texture
		unsigned char *m_texture;
		///< The width
		unsigned int m_width;
		///< The height
		unsigned int m_height;
		///< The depth
		unsigned int m_depth;

		///< Identifier for the texture
		unsigned int m_textureID;

		///< Type of the image
		imageTypes m_imageType;

		/**
		 * \fn	:::Texture();
		 *
		 * \brief	Default constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 */

		Texture();
	};
}


#endif