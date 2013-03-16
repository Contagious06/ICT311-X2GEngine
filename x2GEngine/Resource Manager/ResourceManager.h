#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include "ILoader.h"
#include "IAsset.h"

/**
 * \namespace	Content
 *
 * \brief	.
 */

namespace Content
{
	/**
	 * \class	ResourceManager
	 *
	 * \brief	Manager for resources.
	 *
	 * \author	Matthew Vlietstra
	 * \date	22/03/2012
	 * 			TODO: The resource manager needs to use boost pointers
	 */

	class ResourceManager
	{
	public:

		/**
		 * \fn	ResourceManager::ResourceManager();
		 *
		 * \brief	Default constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 */

		ResourceManager();

		/**
		 * \fn	template <class T> T ResourceManager::*Load(const std::string &filename)
		 *
		 * \brief	Loads the given file.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param	filename	The const std::string &amp; to load.
		 *
		 * \return	null if it fails, else.
		 */

		template <class T>
		T *Load(const std::string &filename)
		{
			std::string extension = filename.substr( filename.find_last_of(".") ); //Get the extension

			//check if the file was previously cached.
			rIter rIt = m_resources.find(filename);

			if (rIt != m_resources.end())
			{
				return static_cast<T*>(rIt->second);
			}

			std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
			//If the file doesn't exits load it.
			lIter it = m_loaders.find(extension);

			if (it != m_loaders.end())
			{
				IAsset *asset = it->second->Load(m_contentDir + "\\" + filename, this);
				m_resources[filename] = asset; //Cache it.
				return static_cast<T*>(asset); //return it.
			}

			return nullptr; //loader doesn't exist :(
		}

		/**
		 * \fn	void ResourceManager::AddLoader(ILoader *loader, const std::string &extension);
		 *
		 * \brief	Adds a loader to 'extension'.
		 *
		 * \author	Matthew Vlietstra
		 * \date	3/04/2012
		 *
		 * \param [in,out]	loader	If non-null, the loader.
		 * \param	extension	  	The extension.
		 */

		void AddLoader(ILoader *loader, const std::string &extension);

		/**
		 * \fn	void ResourceManager::SetContentDirectory(const std::string &directory);
		 *
		 * \brief	Sets a content directory.
		 *
		 * \author	Matthew Vlietstra
		 * \date	3/04/2012
		 *
		 * \param	directory	Pathname of the directory.
		 */

		void SetContentDirectory(const std::string &directory);

		/**
		 * \fn	const std::string ResourceManager::&GetContentDirectory();
		 *
		 * \brief	Gets the content directory.
		 *
		 * \author	Matthew Vlietstra
		 * \date	3/04/2012
		 *
		 * \return	The content directory.
		 */

		const std::string &GetContentDirectory();

		/**
		 * \fn	void ResourceManager::ClearAllResources()
		 *
		 * \brief	Clears all resources.
		 *
		 * \author	Matthew Vlietstra
		 * \date	3/04/2012
		 */

		void ClearAllResources()
		{
		
		}

		/**
		 * \fn	void ResourceManager::RemoveResource(const std::string &filename)
		 *
		 * \brief	Removes the resource described by filename.
		 *
		 * \author	Matthew Vlietstra
		 * \date	3/04/2012
		 *
		 * \param	filename	Filename of the file.
		 */

		void RemoveResource(const std::string &filename)
		{
		
		}

		std::string GetPathToFile(const std::string &filename)
		{
			std::string path = "";
			for (int i = filename.length() - 1; i >= 0; i--)
			{
				if (filename.c_str()[i] == '\\')
				{
					path = filename.substr(this->GetContentDirectory().length()+1, i - this->GetContentDirectory().length());
					break;
				}
			}
			return path;
		}

	private:
		typedef std::map<std::string, ILoader*> loaders;
		typedef loaders::iterator lIter;

		typedef std::map<std::string, IAsset*> resources;
		typedef resources::iterator rIter;

		resources m_resources;
		loaders m_loaders;
		std::string m_contentDir;


	};
}

#endif