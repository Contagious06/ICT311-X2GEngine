#include "IndexBuffer.h"
#include "RendererSingleton.h"

namespace Graphics
{

	IndexBuffer::IndexBuffer( unsigned int *indiceBuffer, unsigned int indiceCount, shapeType shape, Graphics::streamTypes streamType )
	{
		m_shape = shape;
		m_indiceCount = indiceCount;

		m_streamType = streamType;

		m_vboID = gs_renderer->BindIndexBuffer(indiceBuffer, indiceCount, shape, streamType);
	}

	IndexBuffer::~IndexBuffer()
	{
		if (m_vboID != 0)
		{
			gs_renderer->DeleteBuffer(m_vboID);
		}
	}

	unsigned int IndexBuffer::GetIndiceCount()
	{
		return m_indiceCount;
	}

	Graphics::shapeType IndexBuffer::GetShape()
	{
		return m_shape;
	}

	unsigned int IndexBuffer::GetVBO()
	{
		return m_vboID;
	}

	void IndexBuffer::UpdateBuffer( int offset, const unsigned int *data, unsigned int indexCount )
	{
		gs_renderer->UpdateIndexBuffer(this->GetVBO(), offset, data, indexCount);
	}

	bool IndexBuffer::UnmapBuffer()
	{
		return gs_renderer->UnmapBuffer(this->GetVBO(), Graphics::X2_ELEMENT_ARRAY_BUFFER);
	}

	unsigned int * IndexBuffer::GetIndexBuffer( int offset, unsigned int length, bufferAccessTypes access )
	{
		return gs_renderer->MapIndexBufferRange(this->GetVBO(), offset, length, access);;
	}

	IndexBuffer * IndexBuffer::Clone()
	{
		unsigned int *buff = this->GetIndexBuffer(0, this->GetIndiceCount(), X2_MAP_READ_BIT);

		IndexBuffer *newBuffer = nullptr;

		if (buff != nullptr)
		{
			newBuffer = new IndexBuffer(buff, this->GetIndiceCount(), this->GetShape(), this->GetStreamType());
		}

		this->UnmapBuffer();
		return newBuffer;
	}

	Graphics::streamTypes IndexBuffer::GetStreamType()
	{
		return m_streamType;
	}

}