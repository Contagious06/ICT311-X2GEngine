#include "Game.h"
#include "CameraManagerSingleton.h"
#include "ConstraintFactorySingleton.h"
#include <OpenGL/GLDebugDrawer.h>
#include "AwesomiumPanel.h"
#include "AIStateMachine.h"

Game::Game() : Engine()
{
	m_defaultScene = "LUA\\NewIntro.lua";
	Settings::LoadSettings(this, "LUA\\Settings.lua");
	
	m_sceneManager = new SceneManager(m_defaultScene);
	m_gameAssetFactory = new GameAssetFactory();
}



Game::~Game()
{
	if (m_sceneManager != nullptr)
	{
		delete m_sceneManager;
		delete m_gameAssetFactory;
	}

	AwesomiumPanel::ShutdownWebCore();
}

GLDebugDrawer *debugDrawer;


void Game::Initialize()
{
	gs_physicsWorld->InitSimulation(-9.8f);
	luabind::globals(gs_luaManager->GetState())["gs_resourceManager"] = gs_resourceManager;
	luabind::globals(gs_luaManager->GetState())["gs_gameObjectManager"] = gs_gameObjectManager;
	luabind::globals(gs_luaManager->GetState())["gs_sceneManager"] = m_sceneManager;
	luabind::globals(gs_luaManager->GetState())["gs_inputManager"] = Input::InputManager::Instance();
	luabind::globals(gs_luaManager->GetState())["gs_gameAssetFactory"] = m_gameAssetFactory;
	luabind::globals(gs_luaManager->GetState())["gs_renderer"] = m_renderer;
	luabind::globals(gs_luaManager->GetState())["gs_window"] = m_window;
	luabind::globals(gs_luaManager->GetState())["gs_physicsWorld"] = gs_physicsWorld;
	luabind::globals(gs_luaManager->GetState())["gs_cameraManager"] = gs_cameraManager;
	luabind::globals(gs_luaManager->GetState())["gs_constraintFactory"] = gs_constraintFactory;
	luabind::globals(gs_luaManager->GetState())["gs_soundManager"] = gs_soundManager;
 	/*SoundSingleton * ins = SoundSingleton::Instance(); 
 	
 	ins->Initialize("Audio\\", "Sounds.fev");

	ins->LoadSFX("Audio\\FootStep.wav",0, false);*/
	//ins->LoadEventGroup(1, true, ins->eventgroup);
	
	EngineCore::Engine *eng = this;

	luabind::globals(gs_luaManager->GetState())["gs_engine"] = eng;

	debugDrawer = new GLDebugDrawer;
	debugDrawer->setDebugMode(btIDebugDraw::DBG_DrawWireframe);
	gs_physicsWorld->GetWorld()->setDebugDrawer(debugDrawer);

	m_sceneManager->Initialize();
	

	Engine::Initialize();
}

void Game::LoadResources()
{
	m_sceneManager->LoadResources();
}

void Game::Update( float tpf )
{
	gs_physicsWorld->StepSimulation(tpf);
	m_sceneManager->Update(tpf);

	Engine::Update(tpf);
}

void Game::Draw( float tpf )
{
	gs_renderer->ClearScreen();
	gs_renderer->ClearColour(101.0f/256, 148.0f/256, 237.0f/256, 1);
	gs_renderer->LoadIdentity();
	gs_renderer->EnableCullFace(false);
	gs_renderer->EnableColourMaterial(true);
	gs_renderer->EnableDepthTest(true);
 
	Input::InputManager* input = Input::InputManager::Instance();
	if(input->IsKeyDown(Input::Q))
	{
		gs_physicsWorld->DebugDraw();
	}

	m_sceneManager->Draw(tpf);

	gs_renderer->SwapBuffers();
	Engine::Draw(tpf);
}

void Game::UnloadResources()
{
	m_sceneManager->UnloadResources();
}

void Game::SetDefualtScene( std::string scene )
{
	m_defaultScene = scene;
}
