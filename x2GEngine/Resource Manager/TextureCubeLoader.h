#ifndef TEXTURECUBELOADER_H
#define TEXTURECUBELOADER_H

#include <iostream>
#include <stdio.h>
#include <fstream>
#include "ILoader.h"
#include "Texture2D.h"
#include "TextureCube.h"
#include "ResourceManager.h"

/**
 * \namespace	Content
 *
 * \brief	.
 */

namespace Content
{
	/**
	 * \class	TextureCubeLoader
	 *
	 * \brief	Texture cube loader.
	 *
	 * \author	Matthew Vlietstra
	 * \date	28/03/2012
	 */

	class TextureCubeLoader : public ILoader
	{
	public:

		/**
		 * \fn	virtual IAsset TextureCubeLoader::*Load(std::string filename,
		 * 		Content::ResourceManager *const resourceManager)
		 *
		 * \brief	Loads the given file.
		 *
		 * \author	Matthew Vlietstra
		 * \date	28/03/2012
		 *
		 * \param	filename			   	Filename of the file.
		 * \param [in,out]	resourceManager	If non-null, manager for resource.
		 *
		 * \return	null if it fails, else.
		 */

		virtual IAsset *Load(std::string filename, Content::ResourceManager *const resourceManager);
		
	private:

	};


}


#endif