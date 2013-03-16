
#ifndef BITMAPFONTLOADER_H
#define BITMAPFONTLOADER_H

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <boost/tokenizer.hpp>
#include "ILoader.h"
#include "Texture2D.h"
#include "ResourceManager.h"
#include "BitmapFont.h"
#include "Conversion.h"

/**
 * \namespace	Content
 *
 * \brief	.
 */

namespace Content
{
	/**
	 * \class	BitmapFontLoader
	 *
	 * \brief	Bitmap font loader.
	 *
	 * \author	Matthew Vlietstra
	 * \date	21/03/2012
	 */

	class BitmapFontLoader : public ILoader
	{
	public:

		/**
		 * \fn	virtual IAsset BitmapFontLoader::*Load(std::string filename,
		 * 		Content::ResourceManager *const resourceManager);
		 *
		 * \brief	Loads the given file.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \param	filename			   	Filename of the file.
		 * \param [in,out]	resourceManager	If non-null, manager for resource.
		 *
		 * \return	null if it fails, else.
		 */

		virtual IAsset *Load(std::string filename, Content::ResourceManager *const resourceManager);
	};
}



#endif