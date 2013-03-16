#pragma once

#ifndef ICLONEABLE_H
#define ICLONEABLE_H



/**
 * \brief	Cloneable.
 *
 * \author	Matthew Vlietstra
 * \date	22/05/2012
 */

template <class T>
class ICloneable
{
public:

	/**
	 * \brief	Makes a deep copy of this object.
	 *
	 * \author	Matthew Vlietstra
	 * \date	22/05/2012
	 *
	 * \return	null if it fails, else a copy of this object.
	 */

	virtual T *Clone() = 0;
};



#endif