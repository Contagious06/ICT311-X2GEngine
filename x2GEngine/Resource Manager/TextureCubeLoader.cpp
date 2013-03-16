#include "TextureCubeLoader.h"

namespace Content
{
	

	IAsset * TextureCubeLoader::Load( std::string filename, Content::ResourceManager *const resourceManager )
	{
		std::ifstream read(filename);

		if (!read)
		{
			return nullptr;
		}

		std::string line;
		int predictedLineCount = 6;
		std::string filesToLoad[6];

		int i = 0;
		while(std::getline(read, line)) 
		{
			if (i > predictedLineCount)
			{
				return nullptr;
			}
			else if(line == "" || line == "#")
			{

			}
			else
			{
				filesToLoad[i] = line;
				i++;
			}
		}

		if (i != predictedLineCount)
		{
			return nullptr;
		}

		Graphics::Texture2D *textures[6];

		//all other textures have to match the first loaded texture.
		int height = 0;
		int width = 0;
		Graphics::imageTypes imageType = Graphics::X2_RGB;


		for (int i = 0; i < predictedLineCount; i++)
		{
			textures[i] = resourceManager->Load<Graphics::Texture2D>(filesToLoad[i]);

			if (i == 0)
			{
				height = textures[i]->GetHeight();
				width = textures[i]->GetWidth();
				imageType = textures[i]->GetImageType();
			}
			else if (height != textures[i]->GetHeight() || width != textures[i]->GetWidth() || imageType != textures[i]->GetImageType())
			{
				return nullptr; //An image didn't match.
			}
		}

		int iType = 0;
		if (imageType == Graphics::X2_RGB)
		{
			iType = 3;
		}
		else if (imageType == Graphics::X2_RGBA)
		{
			iType = 4;
		}
		else
		{
			return nullptr;
		}

		unsigned char *textureCube = new unsigned char[height * width * iType * 6];
		if (textureCube == nullptr)
		{
			return nullptr;
		}

		int currentTexture2D = 0;
		int currentTextureLoc = 0;

		for (int i = 0; i < height * width * iType * 6; i++)
		{

			unsigned char c = textures[currentTexture2D]->GetTexture()[currentTextureLoc];
			textureCube[i] = c;

			if (currentTextureLoc == height * width * iType -1)
			{
				currentTextureLoc = 0;
				currentTexture2D++;
			}
			else
			{
				currentTextureLoc++;
			}
		}

		return new Graphics::TextureCube(width, height, imageType, textureCube);
	}

}