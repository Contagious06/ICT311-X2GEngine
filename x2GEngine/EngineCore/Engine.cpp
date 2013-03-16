#include "Engine.h"
#include "RendererFactory.h"
#include "RendererSingleton.h"
#include "ShaderManagerSingleton.h"
#include "SpriteBatch.h"

namespace EngineCore
{

	Engine::Engine()
	{
		m_currentEngine = this;
		m_run = true;


		DeviceFactory dFact;
		m_window = dFact.CreateDevice("GLFWDevice");

		RendererFactory rFact;
		m_renderer = rFact.CreateRenderer("OpenGLRenderer");
		gs_currentRenderer->SetCurrentRenderer(m_renderer);
		m_shaderManagement = rFact.CreateShaderManagement("OpenGLRenderer");
		gs_currentShaderManager->SetCurrentShaderManager(m_shaderManagement);

		m_spriteBatch = new Graphics::SpriteBatch();

	//	m_shaderManagement = new Graphics::ShaderStorage();
	//	gs_shaderManager = new ShaderStorage();

		m_previousElapsedTime = 0.0f;


		m_resources = gs_resourceManager;
		//*m_renderer = &OpenGLRenderer;

	}


	Engine::~Engine()
	{
		m_currentEngine = nullptr;
		if (m_window != nullptr)
		{
			delete m_window;
		}

		if (m_renderer != nullptr)
		{
			delete m_renderer;
		}
		
		if (m_spriteBatch != nullptr)
		{
			delete m_spriteBatch;
		}

		m_resources->ClearAllResources();
		

	}

	void Engine::Initialize()
	{
		//std::cout << "Initialize from Engine.h" << std::endl;
		if (m_window == nullptr)
		{
			throw new DeviceIsNull("Error, the specified device is NULL!");
		}

		int width = m_window->GetWindowSize().first;
		int height = m_window->GetWindowSize().second;
		//m_window->SetMultiSampling(4);
		m_window->Inititalize(m_window->GetWindowName(), width, height, 8, 8, 8, 8, 32, 0, true);

		//m_resources = new Content::ResourceManager();
		
		initResourceLoaders(m_resources);
		m_renderer->SetupFrameBuffer();

		
	}

	void Engine::Run()
	{
		//std::cout << "Run from Engine.h" << std::endl;
		Initialize();
		LoadResources();



		while (m_run)
		{

			float tpf = m_window->GetElapsedTime() - m_previousElapsedTime;
			m_previousElapsedTime = m_window->GetElapsedTime();

			//std::cout << "TPF: " << tpf*10 << endl;
			Update(tpf*10);
			Draw(tpf*10);
			if (m_window->WindowClosed())
			{
				m_run = false;
			}
			//std::cout << "ATPF: " << m_window->GetElapsedTime() << endl;

		}


		UnloadResources();
	}

	void Engine::Update( float tpf )
	{
		//std::cout << "Update from Engine.h" << std::endl;
	}

	void Engine::Draw( float tpf )
	{
		//std::cout << "Draw from Engine.h" << std::endl;
	}

	void Engine::Terminate()
	{
		m_run = false;
	}

	IDevice * Engine::GetDevice()
	{
		return this->m_window;
	}

	Graphics::IRenderer * Engine::GetRenderer()
	{
		return m_renderer;
	}

	Content::ResourceManager * Engine::GetResourceManager()
	{
		return m_resources;
	}

	Engine * Engine::m_currentEngine = nullptr;






}