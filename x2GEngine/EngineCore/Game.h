#pragma once
#ifndef GAME2_H
#define GAME2_H

#include "Engine.h"
#include "ShaderManagerSingleton.h"
#include "LUAManagerSingleton.h"
#include "SettingsLoader.h"
#include "ResourceManagerSingleton.h"
#include "GameObjectManagerSingleton.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "CameraControls.h"
#include "NPCGameObject.h"
#include "PhysicsWorldSingleton.h"
#include "GameAssetFactory.h"
#include "Sound.h"

/**
 * \class	Game
 *
 * \brief	Game.
 *
 * \author	Matthew Vlietstra
 * \date	6/04/2012
 */

class Game: public EngineCore::Engine
{

public:

	/**
	 * \fn	:::Game();
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Matthew Vlietstra
	 * \date	6/04/2012
	 */

	Game();

	/**
	 * \fn	:::~Game();
	 *
	 * \brief	Destructor.
	 *
	 * \author	Matthew Vlietstra
	 * \date	6/04/2012
	 */

	~Game();

	//CameraControls *camera;

	/**
	 * \fn	virtual void :::Initialize();
	 *
	 * \brief	Initializes this object.
	 *
	 * \author	Matthew Vlietstra
	 * \date	6/04/2012
	 */

	virtual void Initialize();

	/**
	 * \fn	virtual void :::LoadResources();
	 *
	 * \brief	Loads the resources.
	 *
	 * \author	Matthew Vlietstra
	 * \date	6/04/2012
	 */

	virtual void LoadResources();

	/**
	 * \fn	virtual void :::Update(float tpf);
	 *
	 * \brief	Updates the given tpf.
	 *
	 * \author	Matthew Vlietstra
	 * \date	6/04/2012
	 *
	 * \param	tpf	The tpf.
	 */

	virtual void Update(float tpf);

	/**
	 * \fn	virtual void :::Draw(float tpf);
	 *
	 * \brief	Draws.
	 *
	 * \author	Matthew Vlietstra
	 * \date	6/04/2012
	 *
	 * \param	tpf	The tpf.
	 */

	virtual void Draw(float tpf);

	/**
	 * \fn	virtual void :::UnloadResources();
	 *
	 * \brief	Unload resources.
	 *
	 * \author	Matthew Vlietstra
	 * \date	6/04/2012
	 */

	virtual void UnloadResources();

	/**
	 * Sets a defualt scene.
	 *
	 * \author	Matthew Vlietstra
	 * \date	24/05/2012
	 *
	 * \param	scene	The scene.
	 */

	void SetDefualtScene(std::string scene);
protected:

private:
	///< Manager for scene
	SceneManager *m_sceneManager;
	///< The game asset factory
	GameAssetFactory *m_gameAssetFactory;

	FMOD::Event* m_event;
	FMOD::EventGroup* m_eventgroup;
	FMOD::EventGroup* m_parent;
	NPCGameObject* m_test;

	std::string m_defaultScene;
};

#endif