#ifndef BITMAPCHARACTERSET_H
#define BITMAPCHARACTERSET_H

#include <iostream>
#include "BitmapCharacter.h"

/**
 * \namespace	Graphics
 *
 * \brief	.
 */

namespace Graphics
{
	/**
	 * \class	BitmapCharacterSet
	 *
	 * \brief	Bitmap character set.
	 *
	 * \author	Matthew Vlietstra
	 * \date	22/03/2012
	 * 			http://www.google.com/codesearch#Z8vJL-JqpQ0/trunk/src/com/jmex/angelfont/BitmapCharacterSet.java&type=cs
	 */

	class BitmapCharacterSet
	{
	public:

		/**
		 * \fn	BitmapCharacterSet::BitmapCharacterSet();
		 *
		 * \brief	Default constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 */

		BitmapCharacterSet();

		/**
		 * \fn	BitmapCharacterSet::~BitmapCharacterSet();
		 *
		 * \brief	Destructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 */

		~BitmapCharacterSet();

		/**
		 * \fn	BitmapCharacter BitmapCharacterSet::*GetCharacter(int index);
		 *
		 * \brief	Gets a character.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param	index	Zero-based index of the.
		 *
		 * \return	null if it fails, else the character.
		 */

		BitmapCharacter *GetCharacter(int index);

		/**
		 * \fn	void BitmapCharacterSet::SetCharacter(int index, BitmapCharacter *character);
		 *
		 * \brief	Sets a character.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param	index			 	Zero-based index of the.
		 * \param [in,out]	character	If non-null, the character.
		 */

		void SetCharacter(int index, BitmapCharacter *character);

		/**
		 * \fn	int BitmapCharacterSet::GetLineHeight() const
		 *
		 * \brief	Gets the line height.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	The line height.
		 */

		int GetLineHeight() const { return m_lineHeight; }

		/**
		 * \fn	void BitmapCharacterSet::SetLineHeight(int val)
		 *
		 * \brief	Sets a line height.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param	val	The value.
		 */

		void SetLineHeight(int val) { m_lineHeight = val; }

		/**
		 * \fn	int BitmapCharacterSet::GetBase() const
		 *
		 * \brief	Gets the base.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	The base.
		 */

		int GetBase() const { return m_base; }

		/**
		 * \fn	void BitmapCharacterSet::SetBase(int val)
		 *
		 * \brief	Sets a base.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param	val	The value.
		 */

		void SetBase(int val) { m_base = val; }

		/**
		 * \fn	int BitmapCharacterSet::GetRenderedSize() const
		 *
		 * \brief	Gets the rendered size.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	The rendered size.
		 */

		int GetRenderedSize() const { return m_renderedSize; }

		/**
		 * \fn	void BitmapCharacterSet::SetRenderedSize(int val)
		 *
		 * \brief	Sets a rendered size.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param	val	The value.
		 */

		void SetRenderedSize(int val) { m_renderedSize = val; }

		/**
		 * \fn	int BitmapCharacterSet::GetWidth() const
		 *
		 * \brief	Gets the width.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	The width.
		 */

		int GetWidth() const { return m_width; }

		/**
		 * \fn	void BitmapCharacterSet::SetWidth(int val)
		 *
		 * \brief	Sets a width.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param	val	The value.
		 */

		void SetWidth(int val) { m_width = val; }

		/**
		 * \fn	int BitmapCharacterSet::GetHeight() const
		 *
		 * \brief	Gets the height.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	The height.
		 */

		int GetHeight() const { return m_height; }

		/**
		 * \fn	void BitmapCharacterSet::SetHeight(int val)
		 *
		 * \brief	Sets a height.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param	val	The value.
		 */

		void SetHeight(int val) { m_height = val; }

		/**
		 * \fn	int BitmapCharacterSet::GetYOffset() const
		 *
		 * \brief	Get y coordinate offset.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	The y coordinate offset.
		 */

		int GetYOffset() const { return m_yOffset; }

		/**
		 * \fn	void BitmapCharacterSet::SetYOffset(int val)
		 *
		 * \brief	Sets a y coordinate offset.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param	val	The value.
		 */

		void SetYOffset(int val) { m_yOffset = val; }



	private:
		///< Contains an array of characters
		BitmapCharacter *m_characters[512];
	
		///< Height of the line
		int m_lineHeight;
		///< The base
		int m_base;
		///< Size of the rendered
		int m_renderedSize;
		///< The width
		int m_width;
		///< The height
		int m_height;
		///< The offset
		int m_yOffset;


	};

}

#endif