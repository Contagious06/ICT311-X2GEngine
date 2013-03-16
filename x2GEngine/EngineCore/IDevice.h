#pragma once
#ifndef IDEVICE_H
#define IDEVICE_H
#include <utility>
#include <string>

/**
 * \namespace	EngineCore
 *
 * \brief	.
 */

namespace EngineCore
{
	/**
	 * \class	IDevice
	 *
	 * \brief	Device.
	 *
	 * \author	Matthew Vlietstra
	 * \date	21/03/2012
	 */

	class IDevice
	{
	public:

		/**
		 * \fn	virtual void IDevice::Inititalize(const std::string &windowName, int width, int height,
		 * 		int redbits, int greenbits, int bluebits, int alphabits, int depthbits, int stencilbits,
		 * 		bool windowed) = 0;
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
			int alphabits, int depthbits, int stencilbits, bool windowed) = 0;

		/**
		 * \fn	virtual void IDevice::Terminate() = 0;
		 *
		 * \brief	Terminates this object.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 */

		virtual void Terminate() = 0;

		/**
		 * \fn	virtual void IDevice::SetMultiSampling(int samples) = 0;
		 *
		 * \brief	Sets a multi sampling.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \param	samples	The samples.
		 */

		virtual void SetMultiSampling(int samples) = 0;

		/**
		 * \fn	virtual int IDevice::GetSamples() = 0;
		 *
		 * \brief	Gets the samples.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \return	The samples.
		 */

		virtual int GetSamples() = 0;

		/**
		 * \fn	virtual void IDevice::SetWindowSize(int width, int height) = 0;
		 *
		 * \brief	Sets a window size.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \param	width 	The width.
		 * \param	height	The height.
		 */

		virtual void SetWindowSize(int width, int height) = 0;

		/**
		 * \fn	virtual void IDevice::SetWindowLocation(int x, int y) = 0;
		 *
		 * \brief	Sets a window location.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \param	x	The x coordinate.
		 * \param	y	The y coordinate.
		 */

		virtual void SetWindowLocation(int x, int y) = 0;

		/**
		 * \fn	virtual std::pair<int, int> IDevice::GetWindowLocation() = 0;
		 *
		 * \brief	Gets the window location.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \return	The window location.
		 */

		virtual std::pair<int, int> GetWindowLocation() = 0;

		/**
		 * \fn	virtual std::pair<int, int> IDevice::GetWindowSize() = 0;
		 *
		 * \brief	Gets the window size.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \return	The window size.
		 */

		virtual std::pair<int, int> GetWindowSize() = 0;

		/**
		 * \fn	virtual void IDevice::SetWindowed(bool windowed) = 0;
		 *
		 * \brief	Sets a windowed.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \param	windowed	true to windowed.
		 */

		virtual void SetWindowed(bool windowed) = 0;

		/**
		 * \fn	virtual void IDevice::SetCursorVisibility(bool cursorVisibility) = 0;
		 *
		 * \brief	Sets a cursor visibility.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \param	cursorVisibility	true to cursor visibility.
		 */

		virtual void SetCursorVisibility(bool cursorVisibility) = 0;

		/**
		 * \fn	virtual bool IDevice::WindowClosed() = 0;
		 *
		 * \brief	Gets the window closed.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \return	true if it succeeds, false if it fails.
		 */

		virtual bool WindowClosed() = 0;

		/**
		 * \fn	virtual void IDevice::SetWindowName(const std::string &windowName) = 0;
		 *
		 * \brief	Sets a window name.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \param	windowName	Name of the window.
		 */

		virtual void SetWindowName(const std::string &windowName) = 0;

		/**
		 * \fn	const virtual std::string IDevice::&GetWindowName() const = 0;
		 *
		 * \brief	Gets the window name.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \return	The window name.
		 */

		const virtual std::string &GetWindowName() const = 0;

		/**
		 * \fn	virtual float IDevice::GetElapsedTime() = 0;
		 *
		 * \brief	Gets the elapsed time.
		 *
		 * \author	Matthew Vlietstra
		 * \date	21/03/2012
		 *
		 * \return	The elapsed time.
		 */

		virtual float GetElapsedTime() = 0;
		////virtual int GetWindowLocationY() = 0;
		//virtual int GetWindowLocationX() = 0;
		// 

		/**
		 * \fn	virtual std::pair<int, int> IDevice::GetDesktopResolution() = 0;
		 *
		 * \brief	Gets the desktop resolution.
		 *
		 * \author	Matthew Vlietstra
		 * \date	4/04/2012
		 *
		 * \return	The desktop resolution.
		 */

		virtual std::pair<int, int> GetDesktopResolution() = 0;

		/**
		 * \fn	virtual void IDevice::MouseCursorEnabled(bool enabled) = 0;
		 *
		 * \brief	Mouse cursor enabled.
		 *
		 * \author	Matthew Vlietstra
		 * \date	10/04/2012
		 *
		 * \param	enabled	true to enable, false to disable.
		 */

		virtual void MouseCursorEnabled(bool enabled) = 0;
	};
}


#endif