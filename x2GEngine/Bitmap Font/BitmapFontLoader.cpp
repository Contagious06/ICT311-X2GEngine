#include "BitmapFontLoader.h"
#include "LoaderExceptions.h"


namespace Content
{
	IAsset *BitmapFontLoader::Load( std::string filename, Content::ResourceManager *const resourceManager )
	{
		Graphics::BitmapFont *font = new Graphics::BitmapFont;
		Graphics::BitmapCharacterSet *charSet = new Graphics::BitmapCharacterSet;
		std::ifstream read(filename);

		if (!read)
		{
			return nullptr;
		}

		std::string pathToFont = "";

		for (int i = filename.length() - 1; i >= 0; i--)
		{
			//std::cout << filename.c_str()[i] << "==" << '\\' << std::endl;
			if (filename.c_str()[i] == '\\')
			{
				pathToFont = filename.substr(resourceManager->GetContentDirectory().length()+1, i - resourceManager->GetContentDirectory().length());
				break;
			}
		}



		typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
		boost::char_separator<char> sep("[\\=]+ ,");

		std::string line;

		while(getline(read, line))
		{
			stringstream lineStream(line);
			string tmp;
			lineStream >> tmp; //Put the first word into tmp

			tokenizer::iterator tmpTok;

			if(line.length() != 0)
			{

				tokenizer tokens(line, sep);		
				//cout << *tokens.begin() << endl;

				if (*(tokens.begin()) == "info") //info face=null size=70 bold=0 italic=0 charset=ASCII unicode=0 stretchH=100 smooth=1 aa=1 padding=0,0,0,0 spacing=1,1 
				{
					for (tokenizer::iterator tok_iter = tokens.begin(); tok_iter != tokens.end(); ++tok_iter)
					{
						tmpTok = tok_iter;
						if (*tok_iter == "size")
						{
							tmpTok++;
							charSet->SetRenderedSize(Conversion::ParseInt(tmpTok->c_str()));
						}
					}
				}
				else if (*(tokens.begin()) == "common") //common lineHeight=71 base=26 scaleW=1024 scaleH=1024 pages=1 packed=0 
				{
					for (tokenizer::iterator tok_iter = tokens.begin(); tok_iter != tokens.end(); ++tok_iter)
					{
						tmpTok = tok_iter;
						if (*tok_iter == "lineHeight")
						{
							tmpTok++;
							charSet->SetLineHeight(Conversion::ParseInt(tmpTok->c_str()));
						}
						else if (*tok_iter == "base")
						{
							tmpTok++;
							charSet->SetBase(Conversion::ParseInt(tmpTok->c_str()));
						}
						else if (*tok_iter == "scaleW")
						{
							tmpTok++;
							charSet->SetWidth(Conversion::ParseInt(tmpTok->c_str()));
						}
						else if (*tok_iter == "scaleH")
						{
							tmpTok++;
							charSet->SetHeight(Conversion::ParseInt(tmpTok->c_str()));
						}
						else if (*tok_iter == "yoffset")
						{
							tmpTok++;
							charSet->SetYOffset(Conversion::ParseInt(tmpTok->c_str()));
						}

					}
				}
				else if (*(tokens.begin()) == "page") //page id=0 file="AmericanCaptain.png"
				{
					for (tokenizer::iterator tok_iter = tokens.begin(); tok_iter != tokens.end(); ++tok_iter)
					{
						tmpTok = tok_iter;
						if (*tok_iter == "file")
						{
							tmpTok++;
							//std::cout << tmpTok->c_str() << std::endl;
							string tmpStr = tmpTok->c_str();
							string textureFileName = "";
							for (unsigned int i = 0; i < tmpStr.length(); i++)
							{
								if (tmpStr.c_str()[i] != '\"')
								{
									textureFileName+= tmpStr.c_str()[i];
								}
							}
							Graphics::Texture2D *text = resourceManager->Load<Graphics::Texture2D>(pathToFont + textureFileName);

							if (text == nullptr)
							{
								throw new ImageNotFound("Error file: " + pathToFont + textureFileName + " wasn't found or there isn't a loader for it.");
							}

							font->AddFontTexture(text); //Assuming that the textures are in order... might need to change

						}
					}
					//cout << *tokens.begin() << endl;
				}
				else if (*(tokens.begin()) == "chars") //chars count=255
				{
					//cout << *tokens.begin() << endl;
				}
				else if (*(tokens.begin()) == "char") //char id=0    x=0    y=18    width=9    height=69    xoffset=0    yoffset=0    xadvance=8     page=0    chnl=0
				{
					Graphics::BitmapCharacter *ch = NULL;
					int id;
					for (tokenizer::iterator tok_iter = tokens.begin(); tok_iter != tokens.end(); ++tok_iter)
					{
						tmpTok = tok_iter;

						if (*tok_iter == "id")
						{
							if (!ch)
							{
								delete ch;
							}
							ch = new Graphics::BitmapCharacter;
							tmpTok++;
							id = Conversion::ParseInt(tmpTok->c_str());
						}
						else if (*tok_iter == "x")
						{
							//tok_iter.increment();
							//int value
							tmpTok++;
							ch->SetX(Conversion::ParseInt(tmpTok->c_str()));
						}
						else if (*tok_iter == "y")
						{
							tmpTok++;
							ch->SetY(Conversion::ParseInt(tmpTok->c_str()));
						}
						else if (*tok_iter == "width")
						{
							tmpTok++;
							ch->SetWidth(Conversion::ParseInt(tmpTok->c_str()));
						}
						else if (*tok_iter == "height")
						{
							tmpTok++;
							ch->SetHeight(Conversion::ParseInt(tmpTok->c_str()));
						}
						else if (*tok_iter == "xoffset")
						{
							tmpTok++;
							ch->SetXOffset(Conversion::ParseInt(tmpTok->c_str()));
						}
						else if (*tok_iter == "yoffset")
						{
							tmpTok++;
							ch->SetYOffset(Conversion::ParseInt(tmpTok->c_str()));
						}
						else if (*tok_iter == "xadvance")
						{
							tmpTok++;
							ch->SetXAdvance(Conversion::ParseInt(tmpTok->c_str()));
						}
						else if (*tok_iter == "page")
						{
							tmpTok++;
							ch->SetPage(Conversion::ParseInt(tmpTok->c_str()));
						}
						else if (*tok_iter == "chnl")
						{
							tmpTok++;
							ch->SetCHNL(Conversion::ParseInt(tmpTok->c_str()));
						}
					}
					charSet->SetCharacter(id, ch);
				}
			}
		}

		font->SetBitmapCharacterSet(charSet);
		//font->SetFontTexture(fontTexture);

		return font;
	}


}