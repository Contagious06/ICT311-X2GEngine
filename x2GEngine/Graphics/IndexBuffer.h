#pragma once
#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H
#include <iostream>
//#include "Includes.h"
#include "IRenderer.h"
#include "ICloneable.h"

/**
 * \namespace	Graphics
 *
 * \brief	.
 */

namespace Graphics
{
	enum streamTypes;

	/**
	 * \class	IndexBuffer
	 *
	 * \brief	Buffer for index.
	 *
	 * \author	Matthew Vlietstra
	 * \date	22/03/2012
	 */

	class IRenderer;
	enum shapeType;
	enum bufferAccessTypes;

	class IndexBuffer : public ICloneable<IndexBuffer>
	{
	public:



		/**
		 * \fn	IndexBuffer::IndexBuffer(unsigned int *indiceBuffer, unsigned int indiceCount,
		 * 		shapeType shape);
		 *
		 * \brief	Constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param [in,out]	indiceBuffer	If non-null, buffer for indice data.
		 * \param	indiceCount				Number of indices.
		 * \param	shape					The shape.
		 */

		IndexBuffer(unsigned int *indiceBuffer, unsigned int indiceCount, shapeType shape, Graphics::streamTypes streamType);

		/**
		 * \fn	IndexBuffer::~IndexBuffer();
		 *
		 * \brief	Destructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 */

		~IndexBuffer();

		/**
		 * \fn	unsigned int IndexBuffer::GetIndiceCount();
		 *
		 * \brief	Gets the indice count.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	The indice count.
		 */

		unsigned int GetIndiceCount();

		/**
		 * \fn	shapeType IndexBuffer::GetShape();
		 *
		 * \brief	Gets the shape.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	The shape.
		 */

		shapeType GetShape();

		/**
		 * \fn	unsigned int IndexBuffer::GetVBO();
		 *
		 * \brief	Gets the vbo.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	The vbo.
		 */

		unsigned int GetVBO();

		/**
		 * Updates the buffer.
		 *
		 * @author	Matthew Vlietstra
		 * @date	13/05/2012
		 *
		 * @param	offset	  	The offset.
		 * @param	data	  	The data.
		 * @param	indexCount	Number of indexes.
		 */

		void UpdateBuffer(int offset, const unsigned int *data, unsigned int indexCount );

		/**
		 * Gets an index buffer.
		 *
		 * \author	Matthew Vlietstra
		 * \date	19/05/2012
		 *
		 * \param	offset	The offset.
		 * \param	length	The length.
		 * \param	access	The access.
		 *
		 * \return	null if it fails, else the index buffer.
		 */

		unsigned int *GetIndexBuffer(int offset, unsigned int length, bufferAccessTypes access);

		/**
		 * Gets the unmap buffer.
		 *
		 * @author	Matthew Vlietstra
		 * @date	13/05/2012
		 *
		 * @return	true if it succeeds, false if it fails.
		 */

		bool UnmapBuffer();

		/**
		 * Gets the stream type.
		 *
		 * \author	Matthew Vlietstra
		 * \date	19/05/2012
		 *
		 * \return	The stream type.
		 */

		Graphics::streamTypes GetStreamType();

		/**
		 * Makes a deep copy of this object.
		 *
		 * \author	Matthew Vlietstra
		 * \date	19/05/2012
		 *
		 * \return	null if it fails, else a copy of this object.
		 */

		IndexBuffer *Clone();

	private:
		///< Identifier for the vbo
		unsigned int m_vboID;

		///< The shape
		shapeType m_shape;
		///< Number of indices
		unsigned int m_indiceCount;

		///< Type of the stream
		Graphics::streamTypes m_streamType;
	};




}



#endif