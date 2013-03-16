#include "BitmapFont.h"


namespace Graphics
{

	BitmapFont::BitmapFont()
	{
		//m_fontTexture = NULL;
		m_charSet = NULL;
	}

	BitmapFont::~BitmapFont()
	{
		//ClearFontTexture();
		ClearCharSet();
	}

	void BitmapFont::SetFontTexture(std::vector<Graphics::Texture2D*> &fontTextures )
	{
		m_fontTextures = fontTextures;
		//m_fontTexture = fontTexture;
	}

	Graphics::Texture2D *BitmapFont::GetFontTexture(int page) const
	{
		return m_fontTextures[page];
	}

	//void BitmapFont::ClearFontTexture()
	//{
	//	if (!m_fontTexture)
	//	{
	//		delete m_fontTexture;
	//	}
	//}

	void BitmapFont::SetBitmapCharacterSet( BitmapCharacterSet *charSet )
	{
		m_charSet = charSet;
	}

	BitmapCharacterSet *BitmapFont::GetBitmapCharacterSet() const
	{
		return m_charSet;
	}

	void BitmapFont::ClearCharSet()
	{
		if (!m_charSet)
		{
			delete m_charSet;
		}
	}

	float BitmapFont::GetLineHeight(const std::string &line)
	{
		if (line.length() >= 1)
		{
			return (float)(m_charSet->GetCharacter(line.c_str()[0])->GetHeight());
		}
		return 0.0;
	}

	float BitmapFont::GetLineWidth( const std::string &line )
	{
		float width = 0.0f;
		for (unsigned int i = 0; i < line.length(); i++)
		{
			width+= m_charSet->GetCharacter(line.c_str()[i])->GetWidth();
		}

		return width;
	}

	void BitmapFont::AddFontTexture( Graphics::Texture2D *fontTexture )
	{
		m_fontTextures.push_back(fontTexture);
	}



}