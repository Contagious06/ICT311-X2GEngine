#include "BitmapCharacterSet.h"

namespace Graphics
{
	BitmapCharacterSet::BitmapCharacterSet()
	{
		for (int i = 0; i < 512; i++)
		{
			m_characters[i] = nullptr;
		}
	}

	BitmapCharacterSet::~BitmapCharacterSet()
	{
		for (int i = 0; i < 512; i++)
		{
			if (m_characters[i] != nullptr)
			{
				delete m_characters[i];
			}
		}
	}

	BitmapCharacter *BitmapCharacterSet::GetCharacter( int index )
	{
		return m_characters[index];
	}

	void BitmapCharacterSet::SetCharacter( int index, BitmapCharacter *character )
	{
		m_characters[index] = character;
	}
}