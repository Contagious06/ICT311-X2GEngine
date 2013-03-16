#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "glm.h"
#include "glm/glm.hpp"

/**
 * \namespace	Graphics
 *
 * \brief	.
 */

namespace Graphics
{
	/**
	 * \brief	Rectangle.
	 *
	 * \author	Matthew Vlietstra
	 * \date	25/03/2012
	 */

	class Rectangle
	{
	public:
		Rectangle()
		{
		
		}
		/**
		 * \fn	Rectangle::Rectangle(const glm::vec2 &location, const glm::vect2 &dimensions);
		 *
		 * \brief	Constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 *
		 * \param	location  	The location.
		 * \param	dimensions	The dimensions.
		 */

		Rectangle(const glm::ivec2 &location, const glm::ivec2 &dimensions);

		/**
		 * \fn	Rectangle::Rectangle(int x, int y, int width, int height);
		 *
		 * \brief	Constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 *
		 * \param	x	  	The x coordinate.
		 * \param	y	  	The y coordinate.
		 * \param	width 	The width.
		 * \param	height	The height.
		 */

		Rectangle( int x, int y, int width, int height);

		/**
		 * \fn	const glm::vect2 Rectangle::&GetLocation();
		 *
		 * \brief	Gets the location.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 *
		 * \return	The location.
		 */

		const glm::ivec2 &GetLocation();

		/**
		 * \fn	const glm::vec2 Rectangle::&GetDimensions();
		 *
		 * \brief	Gets the dimensions.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 *
		 * \return	The dimensions.
		 */

		const glm::ivec2 &GetDimensions();

		/**
		 * \fn	const glm::vec2 Rectangle::&GetCenter();
		 *
		 * \brief	Gets the center.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 *
		 * \return	The center.
		 */

		glm::ivec2 GetCenter();

		/**
		 * \fn	const glm::vec2 Rectangle::&GetMin();
		 *
		 * \brief	Gets the minimum.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 *
		 * \return	The calculated minimum.
		 */

		const glm::ivec2 &GetMin();

		/**
		 * \fn	glm::vec2 Rectangle::GetMax();
		 *
		 * \brief	Gets the maximum.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 *
		 * \return	The calculated maximum.
		 */

		glm::ivec2 GetMax();

		/**
		 * \fn	Rectangle & Rectangle::operator=(const Rectangle &rec)
		 *
		 * \brief	Assignment operator.
		 *
		 * \author	Matthew Vlietstra
		 * \date	11/04/2012
		 *
		 * \param	rec	The record.
		 *
		 * \return	A shallow copy of this object.
		 */

		Rectangle & operator=(const Rectangle &rec);
	private:
		///< The location
		glm::ivec2 m_location;
		///< The dimensions
		glm::ivec2 m_dimensions;
	};


///< .
}

#endif