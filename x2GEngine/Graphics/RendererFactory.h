#pragma once
#ifndef RENDERERFACTORY_H
#define RENDERERFACTORY_H

#include "IRenderer.h"
#include "OpenGLRenderer.h"
#include "IShaderManager.h"
#include "ShaderStorage.h"

/**
 * \namespace	EngineCore
 *
 * \brief	.
 */

namespace EngineCore
{
	/**
	 * \class	RendererFactory
	 *
	 * \brief	Renderer factory.
	 *
	 * \author	Matthew Vlietstra
	 * \date	24/03/2012
	 */

	class RendererFactory
	{
	public:

		/**
		 * \fn	IDevice RendererFactory::*CreateRenderer(const std::string &deviceName);
		 *
		 * \brief	Creates a renderer.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \param	deviceName	Name of the device.
		 *
		 * \return	null if it fails, else.
		 */

		Graphics::IRenderer *CreateRenderer(const std::string &deviceName);
		Graphics::IShaderManager *CreateShaderManagement(const std::string &shaders);

	};
}

#endif