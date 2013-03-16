#pragma once
#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H
#include <iostream>
#include "IndexBuffer.h"
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
	class IndexBuffer;
	enum bufferAccessTypes;
	enum bufferTypes;

//#define BUFFER_OFFSET(i) (reinterpret_cast<void*>(i))

	/**
	 * \class	VertexBuffer
	 *
	 * \brief	Buffer for vertex.
	 *
	 * \author	Matthew Vlietstra
	 * \date	22/03/2012
	 */

	class VertexBuffer : public ICloneable<VertexBuffer>
	{
	public:

		/**
		 * \fn	VertexBuffer::VertexBuffer(const void *buffer, unsigned int vertexCount, int vertex,
		 * 		int colour, int texCoord, int normal);
		 *
		 * \brief	Constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param	buffer	   	The buffer.
		 * \param	vertexCount	Number of vertices.
		 * \param	vertex	   	The vertex.
		 * \param	colour	   	The colour.
		 * \param	texCoord   	The tex coordinate.
		 * \param	normal	   	The normal.
		 */

		VertexBuffer(const void *buffer, unsigned int vertexCount, int vertex, int colour, int texCoord, int normal, Graphics::streamTypes type);

		/**
		 * \fn	VertexBuffer::~VertexBuffer();
		 *
		 * \brief	Destructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 */

		~VertexBuffer();

		/**
		 * \fn	unsigned int VertexBuffer::GetGLShape(shapeType shape);
		 *
		 * \brief	Gets a gl shape.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param	shape	The shape.
		 *
		 * \return	The gl shape.
		 */

		//unsigned int GetGLShape(IRenderer::shapeType shape);

		/**
		 * \fn	void VertexBuffer::RenderBuffer(IndexBuffer *iBuffer);
		 *
		 * \brief	Renders the buffer described by iBuffer.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param [in,out]	iBuffer	If non-null, zero-based index of the buffer.
		 */

		void RenderBuffer(IndexBuffer *iBuffer);

		/**
		 * \fn	unsigned int VertexBuffer::GetVBO();
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
		 * \fn	int VertexBuffer::GetVertex();
		 *
		 * \brief	Gets the vertex.
		 *
		 * \author	Matthew Vlietstra
		 * \date	6/04/2012
		 *
		 * \return	The vertex.
		 */

		int GetVertex();

		/**
		 * \fn	int VertexBuffer::GetColour();
		 *
		 * \brief	Gets the colour.
		 *
		 * \author	Matthew Vlietstra
		 * \date	6/04/2012
		 *
		 * \return	The colour.
		 */

		int GetColour();

		/**
		 * \fn	int VertexBuffer::GetTexCoord();
		 *
		 * \brief	Gets the tex coordinate.
		 *
		 * \author	Matthew Vlietstra
		 * \date	6/04/2012
		 *
		 * \return	The tex coordinate.
		 */

		int GetTexCoord();

		/**
		 * \fn	int VertexBuffer::GetNormal();
		 *
		 * \brief	Gets the normal.
		 *
		 * \author	Matthew Vlietstra
		 * \date	6/04/2012
		 *
		 * \return	The normal.
		 */

		int GetNormal();

		/**
		 * \fn	int VertexBuffer::GetStrideSize();
		 *
		 * \brief	Gets the stride size.
		 *
		 * \author	Matthew Vlietstra
		 * \date	6/04/2012
		 *
		 * \return	The stride size.
		 */

		int GetStrideSize();

		/**
		 * \fn	int VertexBuffer::GetStride();
		 *
		 * \brief	Gets the stride.
		 *
		 * \author	Matthew Vlietstra
		 * \date	6/04/2012
		 *
		 * \return	The stride.
		 */

		int GetStride();

		/**
		 * Updates the buffer.
		 *
		 * @author	Matthew Vlietstra
		 * @date	13/05/2012
		 *
		 * @param	offset	   	The offset.
		 * @param	data	   	The data.
		 * @param	vertexCount	Number of vertices.
		 */

		void UpdateBuffer(int offset, const float *data, unsigned int vertexCount );

		/**
		 * Gets a vertex buffer.
		 *
		 * @author	Matthew Vlietstra
		 * @date	13/05/2012
		 *
		 * @param	offset	The offset.
		 * @param	length	The length.
		 * @param	access	The access.
		 *
		 * @return	null if it fails, else the vertex buffer.
		 */

		float *GetVertexBuffer(int offset, unsigned int length, bufferAccessTypes access);

		/**
		 * Unmap buffer.
		 *
		 * @author	Matthew Vlietstra
		 * @date	13/05/2012
		 *
		 * @param	access	The access.
		 *
		 * @return	true if it succeeds, false if it fails.
		 */

		bool UnmapBuffer();

		/**
		 * Gets the vertex count.
		 *
		 * \author	Matthew Vlietstra
		 * \date	19/05/2012
		 *
		 * \return	The vertex count.
		 */

		int GetVertexCount();

		/**
		 * Gets the stream type.
		 *
		 * \author	Matthew Vlietstra
		 * \date	19/05/2012
		 *
		 * \return	The stream type.
		 */

		streamTypes GetStreamType();

		/**
		 * Makes a deep copy of this object.
		 *
		 * \author	Matthew Vlietstra
		 * \date	19/05/2012
		 *
		 * \return	null if it fails, else a copy of this object.
		 */

		VertexBuffer *Clone();

	private:
		///< Identifier for the vbo
		unsigned int m_vboID;

		///< The stride
		int m_stride;
		///< Size of the stride
		int m_strideSize;

		///< The vertex
		int m_vertex;
		///< The colour
		int m_colour;
		///< The tex coordinate
		int m_texCoord;
		///< The normal
		int m_normal;

		int m_vertexCount;

		Graphics::streamTypes m_streamType;

	};




}



#endif