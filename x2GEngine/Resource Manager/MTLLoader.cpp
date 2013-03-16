#include "MTLLoader.h"
#include <fstream>
#include "LoaderExceptions.h"

namespace Content
{

	MTLLoader::MTLLoader()
	{

	}

	IAsset *MTLLoader::Load( std::string filename, Content::ResourceManager *const resourceManager )
	{
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

		//std::map<std::string, Graphics::Material*> material;
		std::vector<Graphics::Material*> *materials = new std::vector<Graphics::Material*>;

		std::ifstream read(filename);

		if(!read)
		{
			return nullptr;
		}

		int count = -1;
		std::string line;
		std::string bin;
		std::string tmpMTLName;

		Graphics::Material *currentMaterial = nullptr;

		while(getline(read, line))
		{
			//cout << "Count: " << count << endl;
			std::stringstream lineStream(line);
			//cout << "Line: " << line << endl;
			std::string tmp;
			//cout << materials[tmpMTLName].render.tr << endl;


			lineStream >> tmp;
			//cout << tmp << endl;
			if(line.length() == 0) //Empty space, no need to compare all the other options.
			{
				//Empty Space
			}
			else if(tmp == "#")
			{
				//Comment!
			}
			else if(tmp == "newmtl") //If this isn't found and tmp is equal to a value such as "kd" (the first loop), theres going to be problems :/ - I'm assuming the file hasn't been tampered with..
			{
				count++;
				lineStream >> tmpMTLName;
				currentMaterial = new Graphics::Material; //Quicker access.
				//materials[tmpMTLName] = currentMaterial;
				//(*materials)[tmpMTLName] = currentMaterial;
				currentMaterial->name = tmpMTLName;
				materials->push_back(currentMaterial);
			}
			else if (currentMaterial == nullptr) //Can't read anything if the material is null...
			{
			}
			else if(tmp == "Kd")
			{
				readVect3f(lineStream, currentMaterial->diffuse);
			}
			else if(tmp == "Ka")
			{
				readVect3f(lineStream, currentMaterial->ambient);
			}
			else if(tmp == "Ks")
			{
				readVect3f(lineStream, currentMaterial->specular);
			}
			else if(tmp == "Tf")
			{
				readVect3f(lineStream, currentMaterial->transmissionFilter);
			}
			else if(tmp == "Ns")
			{
				lineStream >> currentMaterial->specularWeight;
			}
			else if(tmp == "d") //Blender uses this, but switches it around  - used to be if(tmp == "d" || tmp == "Tr") 
			{
				float dTemp;
				lineStream >> dTemp;

				currentMaterial->transparency = 1.0f-dTemp;
			}
			else if(tmp == "Tr")
			{
				lineStream >> currentMaterial->transparency;
			}

			else if(tmp == "illum")
			{
				lineStream >> currentMaterial->illumination;
			}
			else if(tmp == "Ni")
			{
				lineStream >> currentMaterial->opticalDensity;

			}
			else if(tmp == "map_Ka")
			{
				std::string file;
				lineStream >> file;
				currentMaterial->mapAmbient = resourceManager->Load<Graphics::Texture>(pathToFont + file);

				if (currentMaterial->mapAmbient == nullptr)
				{
					throw new ImageNotFound("Error file: " + pathToFont + file + " wasn't found or there isn't a loader for it.");
				}
			}
			else if(tmp == "map_Ks")
			{
				std::string file;
				lineStream >> file;
				currentMaterial->mapSpecular = resourceManager->Load<Graphics::Texture>(pathToFont + file);

				if (currentMaterial->mapSpecular == nullptr)
				{
					throw new ImageNotFound("Error file: " + pathToFont + file + " wasn't found or there isn't a loader for it.");
				}
			}
			else if(tmp == "map_Kd")
			{
				std::string file;
				lineStream >> file;
				currentMaterial->mapDiffuse = resourceManager->Load<Graphics::Texture>(pathToFont + file);

				if (currentMaterial->mapDiffuse == nullptr)
				{
					throw new ImageNotFound("Error file: " + pathToFont + file + " wasn't found or there isn't a loader for it.");
				}
			}
			else if(tmp == "map_refl")
			{
				std::string file;
				lineStream >> file;
				currentMaterial->mapReflect = resourceManager->Load<Graphics::Texture>(pathToFont + file);

				if (currentMaterial->mapReflect == nullptr)
				{
					throw new ImageNotFound("Error file: " + pathToFont + file + " wasn't found or there isn't a loader for it.");
				}
			}
			else if(tmp == "map_d")
			{
				std::string file;
				lineStream >> file;
				currentMaterial->mapAlpha = resourceManager->Load<Graphics::Texture>(pathToFont + file);

				if (currentMaterial->mapAlpha == nullptr)
				{
					throw new ImageNotFound("Error file: " + pathToFont + file + " wasn't found or there isn't a loader for it.");
				}
			}
			else if(tmp == "effect")
			{
				std::string file;
				lineStream >> currentMaterial->effect;

				//currentMaterial->mapAlpha = resourceManager->Load<Graphics::Texture>(pathToFont + file);

				//if (currentMaterial->mapAlpha == nullptr)
				//{
				//	throw new ImageNotFound("Error file: " + pathToFont + file + " wasn't found or there isn't a loader for it.");
				//}
			}
			else if(tmp == "cullFace")
			{
				std::string file;
				lineStream >> file;

				if (file == "false")
				{
					currentMaterial->cullFace = false;
				}
				else
				{
					currentMaterial->cullFace = true;
				}

			}
			else if(tmp == "map_bump" || tmp == "bump")
			{
				std::string file;
				lineStream >> file;

				if (file == "-bm") //check if it has a bump amount
				{
//					lineStream >> file;
					lineStream >> currentMaterial->m_bumpAmount;

					lineStream.ignore(1,' ');
					getline(lineStream, file);

				}

				currentMaterial->bumpMap = resourceManager->Load<Graphics::Texture>(pathToFont + file);

				if (currentMaterial->bumpMap == nullptr)
				{
					throw new ImageNotFound("Error file: \"" + pathToFont + file + "\" wasn't found or there isn't a loader for it.");
				}
			}
		}
		read.close();

		Graphics::MaterialVector *mat = new Graphics::MaterialVector(); //temp struct, just to store the pointer to the material map...
		mat->materials = materials;
		return mat;
	}


	bool MTLLoader::readVect3f(std::stringstream &line, float vect3f[3])
	{
		for(int i = 0; i < 3; i++)
		{
			line >> vect3f[i];
		}

		return true;
	}

}