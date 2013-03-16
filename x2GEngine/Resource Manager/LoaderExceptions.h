#ifndef LOADEREXCEPTIONS_H
#define LOADEREXCEPTIONS_H

#include <stdexcept>

/**
 * \namespace	Content
 *
 * \brief	.
 */

namespace Content
{
	/**
	 * \class	TextureNotPowerOfTwo
	 *
	 * \brief	Texture not power of two.
	 *
	 * \author	Matthew Vlietstra
	 * \date	21/03/2012
	 */

	class TextureNotPowerOfTwo : public std::runtime_error
	{
	public:

		/**
		 * \fn	:::TextureNotPowerOfTwo(const std::string &message) : std::runtime_error(message)
		 *
		 * \brief	Constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \param	message	The message.
		 */

		TextureNotPowerOfTwo(const std::string &message) : std::runtime_error(message) { }
	};

	/**
	 * \class	ImageNotFound
	 *
	 * \brief	Image not found.
	 *
	 * \author	Matthew Vlietstra
	 * \date	21/03/2012
	 */

	class ImageNotFound : public std::runtime_error
	{
	public:

		/**
		 * \fn	:::ImageNotFound(const std::string &message) : std::runtime_error(message)
		 *
		 * \brief	Constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \param	message	The message.
		 */

		ImageNotFound(const std::string &message) : std::runtime_error(message) { }
	};

	/**
	 * \class	ImageFormatNotSupported
	 *
	 * \brief	Image format not supported.
	 *
	 * \author	Matthew Vlietstra
	 * \date	10/04/2012
	 */

	class ImageFormatNotSupported : public std::runtime_error
	{
	public:

		/**
		 * \fn	:::ImageFormatNotSupported(const std::string &message) : std::runtime_error(message)
		 *
		 * \brief	Constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	10/04/2012
		 *
		 * \param	message	The message.
		 */

		ImageFormatNotSupported(const std::string &message) : std::runtime_error(message) { }
	};

	/**
	 * \brief	Content file not found.
	 *
	 * \author	Matthew Vlietstra
	 * \date	22/05/2012
	 */

	class ContentFileNotFound : public std::runtime_error
	{
	public:

		/**
		 * \fn	:::ImageFormatNotSupported(const std::string &message) : std::runtime_error(message)
		 *
		 * \brief	Constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	10/04/2012
		 *
		 * \param	message	The message.
		 */

		ContentFileNotFound(const std::string &message) : std::runtime_error(message) { }
	};

	/**
	 * \brief	Error loading mesh.
	 *
	 * \author	Matthew Vlietstra
	 * \date	22/05/2012
	 */

	class ErrorLoadingMesh : public std::runtime_error
	{
	public:

		/**
		 * \fn	:::ImageFormatNotSupported(const std::string &message) : std::runtime_error(message)
		 *
		 * \brief	Constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	10/04/2012
		 *
		 * \param	message	The message.
		 */

		ErrorLoadingMesh(const std::string &message) : std::runtime_error(message) { }
	};

}



#endif