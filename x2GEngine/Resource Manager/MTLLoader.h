#ifndef MTLLOADER_H
#define MTLLOADER_H

#include <iostream>
#include <sstream>
#include <stdio.h>
#include "ILoader.h"
#include "Texture2D.h"
#include "Material.h"
#include "ResourceManager.h"

/**
 * \namespace	Content
 *
 * \brief	.
 */

namespace Content
{
	/**
	 * \class	MTLLoader
	 *
	 * \brief	Mtl loader.
	 *
	 * \author	Matthew Vlietstra
	 * \date	21/03/2012
	 */

	class MTLLoader : public ILoader
	{
	public:

		/**
		 * \fn	MTLLoader::MTLLoader();
		 *
		 * \brief	Default constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 */

		MTLLoader();

		//this could be made a fair bit faster, too many map calls....

		/**
		 * \fn	virtual IAsset MTLLoader::*Load(std::string filename,
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

	private:

		/**
		 * \fn	bool MTLLoader::readVect3f(std::stringstream &line, float vect3f[3]);
		 *
		 * \brief	Reads a vect 3f.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \param [in,out]	line	The line.
		 * \param	vect3f			The vect 3f.
		 *
		 * \return	true if it succeeds, false if it fails.
		 */

		bool readVect3f(std::stringstream &line, float vect3f[3]);
	};


}


#endif