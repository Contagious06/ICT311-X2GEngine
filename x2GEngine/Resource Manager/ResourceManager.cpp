#include "ResourceManager.h"


namespace Content
{




	ResourceManager::ResourceManager()
	{
		m_contentDir = "Assets";
	}

	void ResourceManager::AddLoader( ILoader *loader, const std::string &extension )
	{
		lIter it = m_loaders.find(extension);

		if (it == m_loaders.end())
		{
			m_loaders[extension] = loader; //Add the loader
		}
	}

	void ResourceManager::SetContentDirectory( const std::string &directory )
	{
		m_contentDir = directory;
	}

	const std::string & ResourceManager::GetContentDirectory()
	{
		return m_contentDir;
	}

}