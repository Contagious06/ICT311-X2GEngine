#ifndef TEXTURE3DLOADER_H
#define TEXTURE3DLOADER_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include "ILoader.h"
#include "Texture2D.h"
#include "Texture3D.h"
#include "TextureCube.h"
#include "ResourceManager.h"
#include "Helpers.h"

/**
 * \namespace	Content
 *
 * \brief	.
 */

namespace Content
{
	/**
	 * \class	Texture3DLoader
	 *
	 * \brief	Texture 3 d loader.
	 *
	 * \author	Matthew Vlietstra
	 * \date	15/04/2012
	 */

	class Texture3DLoader : public ILoader
	{
	public:

		//This and textureCube should use the same loader....

		/**
		 * \fn	virtual IAsset Texture3DLoader::*Load(std::string filename,
		 * 		Content::ResourceManager *const resourceManager);
		 *
		 * \brief	Loads the given file.
		 *
		 * \author	Matthew Vlietstra
		 * \date	15/04/2012
		 *
		 * \param	filename			   	Filename of the file.
		 * \param [in,out]	resourceManager	If non-null, manager for resource.
		 *
		 * \return	null if it fails, else.
		 */

		virtual IAsset *Load(std::string filename, Content::ResourceManager *const resourceManager);

	private:

		/**
		 * \fn	std::string Texture3DLoader::GetPathToFile(const std::string &filename,
		 * 		Content::ResourceManager *const resourceManager);
		 *
		 * \brief	Gets a path to file.
		 *
		 * \author	Matthew Vlietstra
		 * \date	15/04/2012
		 *
		 * \param	filename			   	Filename of the file.
		 * \param [in,out]	resourceManager	If non-null, manager for resource.
		 *
		 * \return	The path to file.
		 */

		std::string GetPathToFile(const std::string &filename, Content::ResourceManager *const resourceManager);
	};


}


#endif