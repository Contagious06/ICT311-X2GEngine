#ifndef ILOADER_H
#define ILOADER_H
#include <string>
#include "IAsset.h"

/**
 * \namespace	Content
 *
 * \brief	.
 */

namespace Content
{
	/**
	 * \class	ILoader
	 *
	 * \brief	Loader.
	 *
	 * \author	Matthew Vlietstra
	 * \date	21/03/2012
	 */

	class ResourceManager;

	class ILoader
	{
	public:

		/**
		 * \fn	virtual IAsset ILoader::*Load(std::string filename,
		 * 		Content::ResourceManager *const resourceManager) = 0;
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

		virtual IAsset *Load(std::string filename, Content::ResourceManager *const resourceManager) = 0;


	private:

	};
}

#endif