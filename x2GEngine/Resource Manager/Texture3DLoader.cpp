#include "Texture3DLoader.h"


namespace Content
{



	IAsset * Texture3DLoader::Load( std::string filename, Content::ResourceManager *const resourceManager )
	{
		std::ifstream read(filename);

		if (!read)
		{
			return nullptr;
		}

		std::string line;
		//int predictedLineCount = 4;
		//std::string filesToLoad[4];

		std::vector<std::string> texture2DFileNames;

		int i = 0;
		while(std::getline(read, line)) 
		{
			//if (i > predictedLineCount)
			//{
			//	return nullptr;
			//}
			if(line == "" || line == "#")
			{

			}
			else
			{
				texture2DFileNames.push_back(line);
				//filesToLoad[i] = line;
				i++;
			}
		}

		int textureToLoad = texture2DFileNames.size();

		if (!Helpers::IsPowerOfTwo(textureToLoad))
		{
			return nullptr;
		}


		//Graphics::Texture2D *textures[6];
		//Graphics::Texture2D **textures = new (Graphics::Texture2D*)[1];
		Graphics::Texture2D **textures = (Graphics::Texture2D**)malloc(textureToLoad * sizeof(Graphics::Texture2D*));

		//all other textures have to match the first loaded texture.
		int height = 0;
		int width = 0;
		Graphics::imageTypes imageType = Graphics::X2_RGB;


		std::string pathToFile = GetPathToFile(filename, resourceManager);

		for (int i = 0; i < textureToLoad; i++)
		{


			textures[i] = resourceManager->Load<Graphics::Texture2D>(pathToFile + texture2DFileNames[i]);

			if (textures[i] == nullptr)
			{
				delete textures;
				return nullptr;
			}
			else if (i == 0)
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

		unsigned char *textureCube = new unsigned char[height * width * iType * textureToLoad];
		if (textureCube == nullptr)
		{
			return nullptr;
		}

		int currentTexture2D = 0;
		int currentTextureLoc = 0;

		for (int i = 0; i < height * width * iType * textureToLoad; i++)
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
		//new Graphics::Texture3D()

		//return new Graphics::TextureCube(width, height, imageType, textureCube);
		return new Graphics::Texture3D(width, height, textureToLoad , imageType, textureCube);
	}

	std::string Texture3DLoader::GetPathToFile( const std::string &filename, Content::ResourceManager *const resourceManager )
	{
		std::string path = "";
		for (int i = filename.length() - 1; i >= 0; i--)
		{
			if (filename.c_str()[i] == '\\')
			{
				path = filename.substr(resourceManager->GetContentDirectory().length()+1, i - resourceManager->GetContentDirectory().length());
				break;
			}
		}
		return path;
	}

}