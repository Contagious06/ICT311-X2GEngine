#include "Rectangle.h"


namespace Graphics
{



	Rectangle::Rectangle( const glm::ivec2 &location, const glm::ivec2 &dimensions )
	{
		m_location = location;
		m_dimensions = dimensions;
	}

	Rectangle::Rectangle( int x, int y, int width, int height )
	{
		m_location.x = x;
		m_location.y = y;

		m_dimensions.x = width;
		m_dimensions.y = height;
	}

	const glm::ivec2 & Rectangle::GetLocation()
	{
		return m_location;
	}

	const glm::ivec2 & Rectangle::GetDimensions()
	{
		return m_dimensions;
	}

	glm::ivec2 Rectangle::GetCenter()
	{
		return glm::ivec2 ((m_dimensions.x+m_location.x)/2, (m_dimensions.y+m_location.y)/2);
	}

	const glm::ivec2 &Rectangle::GetMin()
	{
		return m_location;
	}

	glm::ivec2 Rectangle::GetMax()
	{
		return glm::ivec2(m_dimensions.x + m_location.x, m_dimensions.y + m_location.y);
	}

	Rectangle & Rectangle::operator=( const Rectangle &rec )
	{
		this->m_dimensions = rec.m_dimensions;
		this->m_location = rec.m_location;
		return *this;
	}



}