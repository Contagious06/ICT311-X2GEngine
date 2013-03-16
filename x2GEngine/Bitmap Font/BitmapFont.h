#ifndef BITMAPFONT_H
#define BITMAPFONT_H



#include <vector>
#include "Texture.h"
#include "BitmapCharacterSet.h"
#include "IAsset.h"

/**
 * \namespace	Graphics
 *
 * \brief	.
 */

namespace Graphics
{
	class Texture2D;


	/**
	 * \class	BitmapFont
	 *
	 * \brief	Bitmap font.
	 *
	 * \author	Matthew Vlietstra
	 * \date	22/03/2012
	 * 			Loosely based off: http://www.google.com/codesearch#Z8vJL-JqpQ0/trunk/src/com/jmex/angelfont/BitmapFont.java&type=cs
	 */

	class BitmapFont : public Content::IAsset
	{
	public:

		/**
		 * \enum	Align
		 *
		 * \brief	Values that represent Align.
		 */

		enum Align
		{
			Left, Center, Right
		};

		/**
		 * \fn	:::BitmapFont();
		 *
		 * \brief	Default constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 */

		BitmapFont();

		/**
		 * \fn	:::~BitmapFont();
		 *
		 * \brief	Destructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 */

		~BitmapFont();

		/**
		 * \fn	void :::SetFontTexture(std::vector<Graphics::Texture2D*> &fontTextures);
		 *
		 * \brief	Sets a font texture.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param [in,out]	fontTextures	[in,out] If non-null, the font textures.
		 */

		void SetFontTexture(std::vector<Graphics::Texture2D*> &fontTextures);

		/**
		 * \fn	Graphics::Texture2D *BitmapFont::GetFontTexture(int page) const;
		 *
		 * \brief	Gets a font texture.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param	page	The page.
		 *
		 * \return	null if it fails, else the font texture.
		 */

		Graphics::Texture2D *BitmapFont::GetFontTexture(int page) const;

		/**
		 * \fn	void :::SetBitmapCharacterSet(BitmapCharacterSet *charSet);
		 *
		 * \brief	Sets a bitmap character set.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param [in,out]	charSet	If non-null, set the character belongs to.
		 */

		void SetBitmapCharacterSet(BitmapCharacterSet *charSet);

		/**
		 * \fn	BitmapCharacterSet :::*GetBitmapCharacterSet() const;
		 *
		 * \brief	Gets the bitmap character set.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	null if it fails, else the bitmap character set.
		 */

		BitmapCharacterSet *GetBitmapCharacterSet() const;

		/**
		 * \fn	void :::ClearCharSet();
		 *
		 * \brief	Clears the character set.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 */

		void ClearCharSet();

		/**
		 * \fn	float :::GetLineHeight(std::string line)
		 *
		 * \brief	Gets a line height.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param	line	The line.
		 *
		 * \return	The line height.
		 */

		float GetLineHeight(const std::string &line);

		/**
		 * \fn	float :::GetLineWidth(std::string line)
		 *
		 * \brief	Gets a line width.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param	line	The line.
		 *
		 * \return	The line width.
		 */

		float GetLineWidth(const std::string &line);

		/**
		 * \fn	void :::AddFontTexture(Graphics::Texture2D *fontTexture)
		 *
		 * \brief	Adds a font texture.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param [in,out]	fontTexture	If non-null, the font texture.
		 */

		void AddFontTexture(Graphics::Texture2D *fontTexture);
	private:
		///< The font textures
		std::vector<Graphics::Texture2D*> m_fontTextures;
		///< The font texture
		//Graphics::Texture2D *m_fontTexture;
		///< Set the character belongs to
		BitmapCharacterSet *m_charSet;

	};

}

#endif