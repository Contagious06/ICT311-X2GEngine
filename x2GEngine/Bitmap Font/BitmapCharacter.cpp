#include "BitmapCharacter.h"

namespace Graphics
{

	BitmapCharacter::BitmapCharacter()
	{

	}

	BitmapCharacter::~BitmapCharacter()
	{

	}

	int BitmapCharacter::GetX()
	{
		return m_x;
	}

	void BitmapCharacter::SetX( int x )
	{
		m_x = x;
	}

	int BitmapCharacter::GetY()
	{
		return m_y;
	}

	void BitmapCharacter::SetY( int y )
	{
		m_y = y;
	}

	int BitmapCharacter::GetWidth()
	{
		return m_width;
	}

	void BitmapCharacter::SetWidth( int width )
	{
		m_width = width;
	}

	int BitmapCharacter::GetHeight()
	{
		return m_height;
	}

	void BitmapCharacter::SetHeight( int height )
	{
		m_height = height;
	}

	int BitmapCharacter::GetXOffset()
	{
		return m_xOffset;
	}

	void BitmapCharacter::SetXOffset( int xOffset )
	{
		m_xOffset = xOffset;
	}

	int BitmapCharacter::GetYOffset()
	{
		return m_yOffset;
	}

	void BitmapCharacter::SetYOffset( int yOffset )
	{
		m_yOffset = yOffset;
	}

	int BitmapCharacter::GetXAdvance()
	{
		return m_xAdvance;
	}

	void BitmapCharacter::SetXAdvance( int xAdvance )
	{
		m_xAdvance = xAdvance;
	}


}