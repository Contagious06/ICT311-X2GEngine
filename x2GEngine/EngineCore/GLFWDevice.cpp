#include "GLFWDevice.h"

namespace EngineCore
{
	GLFWDevice::GLFWDevice()
	{
		m_windowSize.first = 800;
		m_windowSize.second = 480;
		m_windowLocation.first = 0;
		m_windowLocation.second = 0;
		m_windowed = false;
		m_samples = 0;
		m_windowName = "My Game";
		m_closedWindow = false;
	}

	GLFWDevice::~GLFWDevice()
	{
		Terminate();
	}

	void GLFWDevice::Inititalize(const std::string &windowName, int width, int height, int redbits, int greenbits, int bluebits,
		int alphabits, int depthbits, int stencilbits, bool windowed)
	{
		
		if (GL_FALSE == glfwInit())
		{
			throw new DeviceInititalizeFailor("Error GLFW Failed to Inititalize!");
		}

		int mode;
		if (m_windowed)
		{
			mode = GLFW_WINDOW;
		}
		else
		{
			mode = GLFW_FULLSCREEN;
		}

		//glfwSetWindowSizeCallback(windowReshape);
		glfwOpenWindowHint( GLFW_WINDOW_NO_RESIZE, GL_TRUE );

		int max_samples = m_samples;
		glGetIntegerv(GL_MAX_SAMPLES, &max_samples);

		if (max_samples != m_samples)
		{
			std::cout << "WARNING: Requested "  << max_samples << " samples, using maximum available " << max_samples  << std::endl;
		}
		
		glfwOpenWindowHint(GLFW_FSAA_SAMPLES, max_samples);
		if( !glfwOpenWindow( width, height, redbits, greenbits, bluebits, alphabits, depthbits, stencilbits, mode ) )
		{
			glfwTerminate();
			throw new WindowOpenFailor("GLFW window failed to open!");
		}
		glfwSetWindowCloseCallback(onCloseWindow); 
		glfwSetKeyCallback(KeyboardCallBack);
		glfwSetMousePosCallback(MouseCallBack);
		glfwSetMouseButtonCallback(MouseButtonCallback);
		glfwSetMouseWheelCallback(MouseWheelCallback);

		glfwSetWindowTitle(windowName.c_str());




		GLenum err = glewInit();
		if (GLEW_OK != err)
		{
			throw new DeviceInititalizeFailor("Error Glew Failed to Inititalize! Error: " + std::string((char *)glewGetErrorString(err)));
		}
	}

	void GLFWDevice::Terminate()
	{
		glfwTerminate();
	}

	void GLFWDevice::SetMultiSampling(int samples)
	{
		if (samples <= 0)
		{
			glDisable(GL_MULTISAMPLE);
		}
		else
		{
			glEnable(GL_MULTISAMPLE);
		}
		m_samples = samples;
		glfwOpenWindowHint(GLFW_FSAA_SAMPLES, samples);
	}

	int GLFWDevice::GetSamples()
	{
		return m_samples;
	}

	void GLFWDevice::SetWindowSize(int width, int height)
	{
		m_windowSize.first = width;
		m_windowSize.second = height;
		glfwSetWindowSize(width, height);
	}

	void GLFWDevice::SetWindowLocation(int x, int y)
	{
		m_windowLocation.first = x;
		m_windowLocation.second = y;
		glfwSetWindowPos( x, y);
	}

	std::pair<int, int> GLFWDevice::GetWindowLocation()
	{
		return m_windowLocation;
	}

	std::pair<int, int> GLFWDevice::GetWindowSize()
	{
		return m_windowSize;
	}

	void GLFWDevice::SetWindowed(bool windowed)
	{
		m_windowed = windowed;
	}

	void GLFWDevice::SetCursorVisibility(bool cursorVisibility)
	{
		if (cursorVisibility)
		{
			glfwEnable(GLFW_MOUSE_CURSOR);
		}
		else
		{
			glfwDisable(GLFW_MOUSE_CURSOR);
		}
	}

	bool GLFWDevice::WindowClosed()
	{
		return m_closedWindow;
	}

	void GLFWDevice::SetWindowName(const std::string &windowName)
	{
		glfwSetWindowTitle(windowName.c_str());
		m_windowName = windowName;
	}

	const std::string &GLFWDevice::GetWindowName() const
	{
		return m_windowName;
	}

	float GLFWDevice::GetElapsedTime()
	{
		return (float)glfwGetTime();
	}


	bool GLFWDevice::m_closedWindow = false;
	int GLFWCALL GLFWDevice::onCloseWindow()
	{
		m_closedWindow = true;
		return 1;
	}

	void GLFWCALL GLFWDevice::KeyboardCallBack( int k, int action )
	{

		Input::InputManager* input = Input::InputManager::Instance();
		input->KeyboardCallback(k, action);
		//std::cout << (char)k << "Code: " << k << std::endl; 
	}

	void GLFWCALL GLFWDevice::MouseCallBack(int x, int y)
	{
		Input::InputManager* input = Input::InputManager::Instance();
		input->MousePosCallback(x, y);
		//std::cout << "Mouse X: " << x << " Y: " << y << std::endl; 
	}

	void GLFWCALL GLFWDevice::MouseButtonCallback(int button, int state)
	{
		Input::InputManager* input = Input::InputManager::Instance();
		input->MouseButtonCallback(button, state);
		//std::cout << "Mouse Button: " << button << " State: " << state << std::endl; 
	}

	void GLFWCALL GLFWDevice::MouseWheelCallback(int pos)
	{
		Input::InputManager* input = Input::InputManager::Instance();
		input->MouseWheelCallback(pos);
		//std::cout << "Mouse Wheel Pos: " << pos << std::endl; 
	}

	std::pair<int, int> GLFWDevice::GetDesktopResolution()
	{
		GLFWvidmode mode;

		glfwGetDesktopMode(&mode);

		std::pair<int, int> md = std::pair<int, int>(0, 0);

		md.first = mode.Width;
		md.second = mode.Height;



		return md;
	}

}
