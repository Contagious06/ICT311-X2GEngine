#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include "DeviceExceptions.h"
#include "ResourceManager.h"
#include "DeviceFactory.h"
#include "IDevice.h"
#include "IRenderer.h"
#include "InitResourceLoaders.h"
#include "LUAExpose.h"
#include "ResourceManagerSingleton.h"
#include "IShaderManager.h"
#include "SpriteBatch.h"


/**
 * \namespace	EngineCore
 *
 * \brief	.
 */

namespace EngineCore
{
	/**
	 * \class	Engine
	 *
	 * \brief	Engine.
	 *
	 * \author	Matthew Vlietstra
	 * \date	21/03/2012
	 */

	class Engine
	{
	public:

		/**
		 * \fn	Engine::Engine();
		 *
		 * \brief	Default constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 */

		Engine();

		/**
		 * \fn	Engine::~Engine();
		 *
		 * \brief	Destructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	11/04/2012
		 */

		~Engine();

		/**
		 * \fn	virtual void Engine::Initialize();
		 *
		 * \brief	Initializes this object.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 */

		virtual void Initialize();

		/**
		 * \fn	void Engine::Run();
		 *
		 * \brief	Runs this object.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 */

		static Engine *GetEngine()
		{
			return m_currentEngine;
		}

		void Run();

		/**
		 * \fn	virtual void Engine::LoadResources() = 0;
		 *
		 * \brief	Loads the resources.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 */

		virtual void LoadResources() = 0;

		/**
		 * \fn	virtual void Engine::Update(float tpf);
		 *
		 * \brief	Updates the given tpf.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \param	tpf	The tpf.
		 */

		virtual void Update(float tpf);

		/**
		 * \fn	virtual void Engine::Draw(float tpf);
		 *
		 * \brief	Draws.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \param	tpf	The tpf.
		 */

		virtual void Draw(float tpf);

		/**
		 * \fn	virtual void Engine::UnloadResources() = 0;
		 *
		 * \brief	Unload resources.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 */

		virtual void UnloadResources() = 0;

		/**
		 * \fn	void Engine::Terminate();
		 *
		 * \brief	Terminates this object.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 */

		void Terminate();

		/**
		 * \fn	IDevice Engine::*GetDevice()
		 *
		 * \brief	Gets the device.
		 *
		 * \author	Matthew Vlietstra
		 * \date	8/04/2012
		 *
		 * \return	null if it fails, else the device.
		 */

		IDevice *GetDevice();

		/**
		 * \fn	Graphics::IRenderer Engine::*GetRenderer()
		 *
		 * \brief	Gets the renderer.
		 *
		 * \author	Matthew Vlietstra
		 * \date	8/04/2012
		 *
		 * \return	null if it fails, else the renderer.
		 */

		Graphics::IRenderer *GetRenderer();

		/**
		 * \fn	Content::ResourceManager Engine::*GetResourceManager()
		 *
		 * \brief	Gets the resource manager.
		 *
		 * \author	Matthew Vlietstra
		 * \date	8/04/2012
		 *
		 * \return	null if it fails, else the resource manager.
		 */

		Content::ResourceManager *GetResourceManager();
	protected:
		///< The resources
		Content::ResourceManager *m_resources;
		///< The window
		EngineCore::IDevice *m_window;
		Graphics::IRenderer *m_renderer;
		Graphics::IShaderManager *m_shaderManagement;

		Graphics::SpriteBatch *m_spriteBatch;

	private:
		///< true to run
		bool m_run;
		///< Time of the previous elapsed
		float m_previousElapsedTime;

		static Engine *m_currentEngine;
	};


}


#endif