#pragma once
#ifndef GLFWDEVICE_H
#define GLFWDEVICE_H

#include <string>
#include "Includes.h"
#include "InputManager.h"
#include "IDevice.h"
#include "DeviceExceptions.h"

/**
 * \namespace	EngineCore
 *
 * \brief	.
 */

namespace EngineCore
{
	/**
	 * \class	GLFWDevice
	 *
	 * \brief	Glfw device.
	 *
	 * \author	Matthew Vlietstra
	 * \date	21/03/2012
	 */

	class GLFWDevice : public IDevice
	{
	public:

		/**
		 * \fn	GLFWDevice::GLFWDevice();
		 *
		 * \brief	Default constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 */

		GLFWDevice();

		/**
		 * \fn	GLFWDevice::~GLFWDevice();
		 *
		 * \brief	Destructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 */

		~GLFWDevice();

		/**
		 * \fn	virtual void GLFWDevice::Inititalize(const std::string &windowName, int width, int height,
		 * 		int redbits, int greenbits, int bluebits, int alphabits, int depthbits, int stencilbits,
		 * 		bool windowed);
		 *
		 * \brief	Inititalizes.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \param	windowName 	Name of the window.
		 * \param	width	   	The width.
		 * \param	height	   	The height.
		 * \param	redbits	   	The redbits.
		 * \param	greenbits  	The greenbits.
		 * \param	bluebits   	The bluebits.
		 * \param	alphabits  	The alphabits.
		 * \param	depthbits  	The depthbits.
		 * \param	stencilbits	The stencilbits.
		 * \param	windowed   	true to windowed.
		 */

		virtual void Inititalize(const std::string &windowName, int width, int height, int redbits, int greenbits, int bluebits,
			int alphabits, int depthbits, int stencilbits, bool windowed);

		/**
		 * \fn	virtual void GLFWDevice::Terminate();
		 *
		 * \brief	Terminates this object.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 */

		virtual void Terminate();

		/**
		 * \fn	virtual void GLFWDevice::SetMultiSampling(int samples);
		 *
		 * \brief	Sets a multi sampling.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \param	samples	The samples.
		 */

		virtual void SetMultiSampling(int samples);

		/**
		 * \fn	virtual int GLFWDevice::GetSamples();
		 *
		 * \brief	Gets the samples.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \return	The samples.
		 */

		virtual int GetSamples();

		/**
		 * \fn	virtual void GLFWDevice::SetWindowSize(int width, int height);
		 *
		 * \brief	Sets a window size.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \param	width 	The width.
		 * \param	height	The height.
		 */

		virtual void SetWindowSize(int width, int height);

		/**
		 * \fn	virtual void GLFWDevice::SetWindowLocation(int x, int y);
		 *
		 * \brief	Sets a window location.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \param	x	The x coordinate.
		 * \param	y	The y coordinate.
		 */

		virtual void SetWindowLocation(int x, int y);

		/**
		 * \fn	virtual std::pair<int, int> GLFWDevice::GetWindowLocation();
		 *
		 * \brief	Gets the window location.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \return	The window location.
		 */

		virtual std::pair<int, int> GetWindowLocation();

		/**
		 * \fn	virtual std::pair<int, int> GLFWDevice::GetWindowSize();
		 *
		 * \brief	Gets the window size.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \return	The window size.
		 */

		virtual std::pair<int, int> GetWindowSize();

		/**
		 * \fn	virtual void GLFWDevice::SetWindowed(bool windowed);
		 *
		 * \brief	Sets a windowed.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \param	windowed	true to windowed.
		 */

		virtual void SetWindowed(bool windowed);

		/**
		 * \fn	virtual void GLFWDevice::SetCursorVisibility(bool cursorVisibility);
		 *
		 * \brief	Sets a cursor visibility.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \param	cursorVisibility	true to cursor visibility.
		 */

		virtual void SetCursorVisibility(bool cursorVisibility);

		/**
		 * \fn	virtual bool GLFWDevice::WindowClosed();
		 *
		 * \brief	Gets the window closed.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \return	true if it succeeds, false if it fails.
		 */

		virtual bool WindowClosed();

		/**
		 * \fn	virtual void GLFWDevice::SetWindowName(const std::string &windowName);
		 *
		 * \brief	Sets a window name.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \param	windowName	Name of the window.
		 */

		virtual void SetWindowName(const std::string &windowName);

		/**
		 * \fn	const virtual std::string GLFWDevice::&GetWindowName() const;
		 *
		 * \brief	Gets the window name.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \return	The window name.
		 */

		const virtual std::string &GetWindowName() const;

		/**
		 * \fn	virtual float GLFWDevice::GetElapsedTime();
		 *
		 * \brief	Gets the elapsed time.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \return	The elapsed time.
		 */

		virtual float GetElapsedTime();

		/**
		 * \fn	virtual std::pair<int, int> GLFWDevice::GetDesktopResolution()
		 *
		 * \brief	Gets the desktop resolution.
		 *
		 * \author	Matthew Vlietstra
		 * \date	4/04/2012
		 *
		 * \return	The desktop resolution.
		 */

		virtual std::pair<int, int> GetDesktopResolution();

		/**
		 * \fn	virtual void GLFWDevice::MouseCursorEnabled(bool enabled)
		 *
		 * \brief	Mouse cursor enabled.
		 *
		 * \author	Matthew Vlietstra
		 * \date	10/04/2012
		 *
		 * \param	enabled	true to enable, false to disable.
		 */

		virtual void MouseCursorEnabled(bool enabled)
		{
			if (enabled)
			{
				glfwEnable(GLFW_MOUSE_CURSOR);
			}
			else
			{
				glfwDisable(GLFW_MOUSE_CURSOR);
			}
		}
	private:
		///< The window location
		std::pair<int,int> m_windowLocation;
		///< Size of the window
		std::pair<int,int> m_windowSize;
		///< Name of the window
		std::string m_windowName;
		///< true to windowed
		bool m_windowed;
		///< The samples
		int m_samples;

		///< true to closed window
		static bool m_closedWindow; //siiiigh...

		/**
		 * \fn	static int GLFWCALL GLFWDevice::onCloseWindow();
		 *
		 * \brief	Executes the close window action.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \return	.
		 */

		static int GLFWCALL onCloseWindow();

		/**
		 * \fn	static void GLFWCALL GLFWDevice::KeyboardCallBack( int k, int action );
		 *
		 * \brief	Back, called when the keyboard.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \param	k	  	The k.
		 * \param	action	The action.
		 *
		 * \return	.
		 */

		static void GLFWCALL KeyboardCallBack( int k, int action );

		/**
		 * \fn	static void GLFWCALL GLFWDevice::MouseCallBack(int x, int y);
		 *
		 * \brief	Back, called when the mouse.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \param	x	The x coordinate.
		 * \param	y	The y coordinate.
		 *
		 * \return	.
		 */

		static void GLFWCALL MouseCallBack(int x, int y);

		/**
		 * \fn	static void GLFWCALL GLFWDevice::MouseButtonCallback(int button, int state);
		 *
		 * \brief	Callback, called when the mouse button.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \param	button	The button.
		 * \param	state 	The state.
		 *
		 * \return	.
		 */

		static void GLFWCALL MouseButtonCallback(int button, int state);

		/**
		 * \fn	static void GLFWCALL GLFWDevice::MouseWheelCallback(int pos);
		 *
		 * \brief	Callback, called when the mouse wheel.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \param	pos	The position.
		 *
		 * \return	.
		 */

		static void GLFWCALL MouseWheelCallback(int pos);
	};

}


#endif