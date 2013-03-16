#ifndef BITMAPCHARACTER_H
#define BITMAPCHARACTER_H

/**
 * \namespace	Graphics
 *
 * \brief	.
 */

namespace Graphics
{
	/**
	 * \class	BitmapCharacter
	 *
	 * \brief	Bitmap character.
	 *
	 * \author	Matthew Vlietstra
	 * \date	1/04/2012
	 */

	class BitmapCharacter
	{
	public:

		/**
		 * \fn	BitmapCharacter::BitmapCharacter();
		 *
		 * \brief	Default constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 * 			Loosley based of: http://www.google.com/codesearch#Z8vJL-JqpQ0/trunk/src/com/jmex/angelfont/BitmapCharacter.java&type=cs
		 */

		BitmapCharacter();

		/**
		 * \fn	BitmapCharacter::~BitmapCharacter();
		 *
		 * \brief	Destructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 */

		~BitmapCharacter();

		/**
		 * \fn	int BitmapCharacter::GetX();
		 *
		 * \brief	Get x coordinate.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	The x coordinate.
		 */

		int GetX();

		/**
		 * \fn	void BitmapCharacter::SetX(int x);
		 *
		 * \brief	Sets an x coordinate.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param	x	The x coordinate.
		 */

		void SetX(int x);

		/**
		 * \fn	int BitmapCharacter::GetY();
		 *
		 * \brief	Get y coordinate.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	The y coordinate.
		 */

		int GetY();

		/**
		 * \fn	void BitmapCharacter::SetY(int y);
		 *
		 * \brief	Sets a y coordinate.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param	y	The y coordinate.
		 */

		void SetY(int y);

		/**
		 * \fn	int BitmapCharacter::GetWidth();
		 *
		 * \brief	Gets the width.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	The width.
		 */

		int GetWidth();

		/**
		 * \fn	void BitmapCharacter::SetWidth(int width);
		 *
		 * \brief	Sets a width.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param	width	The width.
		 */

		void SetWidth(int width);

		/**
		 * \fn	int BitmapCharacter::GetHeight();
		 *
		 * \brief	Gets the height.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	The height.
		 */

		int GetHeight();

		/**
		 * \fn	void BitmapCharacter::SetHeight(int height);
		 *
		 * \brief	Sets a height.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param	height	The height.
		 */

		void SetHeight(int height);

		/**
		 * \fn	int BitmapCharacter::GetXOffset();
		 *
		 * \brief	Get x coordinate offset.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	The x coordinate offset.
		 */

		int GetXOffset();

		/**
		 * \fn	void BitmapCharacter::SetXOffset(int xOffset);
		 *
		 * \brief	Sets an x coordinate offset.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param	xOffset	The offset.
		 */

		void SetXOffset(int xOffset);

		/**
		 * \fn	int BitmapCharacter::GetYOffset();
		 *
		 * \brief	Get y coordinate offset.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	The y coordinate offset.
		 */

		int GetYOffset();

		/**
		 * \fn	void BitmapCharacter::SetYOffset(int yOffset);
		 *
		 * \brief	Sets a y coordinate offset.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param	yOffset	The offset.
		 */

		void SetYOffset(int yOffset);

		/**
		 * \fn	int BitmapCharacter::GetXAdvance();
		 *
		 * \brief	Get x coordinate advance.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	The x coordinate advance.
		 */

		int GetXAdvance();

		/**
		 * \fn	void BitmapCharacter::SetXAdvance(int xAdvance);
		 *
		 * \brief	Sets an x coordinate advance.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param	xAdvance	The advance.
		 */

		void SetXAdvance(int xAdvance);

		/**
		 * \fn	void BitmapCharacter::SetPage(int page)
		 *
		 * \brief	Sets a page.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param	page	The page.
		 */

		void SetPage(int page)
		{
			m_page = page;
		}

		/**
		 * \fn	int BitmapCharacter::GetPage()
		 *
		 * \brief	Gets the page.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	The page.
		 */

		int GetPage()
		{
			return m_page;
		}

		/**
		 * \fn	void BitmapCharacter::SetCHNL(int chnl)
		 *
		 * \brief	Sets a channel.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param	chnl	The channel.
		 */

		void SetCHNL(int chnl)
		{
			m_chnl = chnl;
		}

		/**
		 * \fn	int BitmapCharacter::GetCHNL()
		 *
		 * \brief	Gets the channel.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	The channel.
		 */

		int GetCHNL()
		{
			return m_chnl;
		}

	private:
		///< The 
		int m_x;
		///< The 
		int m_y;
		///< The width
		int m_width;
		///< The height
		int m_height;
		///< The offset
		int m_xOffset;
		///< The offset
		int m_yOffset;
		///< The advance
		int m_xAdvance;

		///< The page
		int m_page;

		///< The channel
		int m_chnl;

	};

}


#endif