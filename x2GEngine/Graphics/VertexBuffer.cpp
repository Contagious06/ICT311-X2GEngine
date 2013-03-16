#include "VertexBuffer.h"
#include "RendererSingleton.h"

namespace Graphics
{


	VertexBuffer::VertexBuffer( const void *buffer, unsigned int vertexCount, int vertex, int colour, int texCoord, int normal, Graphics::streamTypes type )
	{
		m_vertex = vertex;
		m_colour = colour;
		m_texCoord = texCoord;
		m_normal = normal;
		m_streamType = type;
		m_vertexCount = vertexCount;

		m_stride = (m_vertex + m_colour + m_texCoord + m_normal);
		m_strideSize = m_stride * sizeof(float);

		m_vboID = gs_renderer->BindVertexBuffer(buffer, vertexCount, m_strideSize, type);
	}

	VertexBuffer::~VertexBuffer()
	{
		if (m_vboID != 0)
		{
			gs_renderer->DeleteBuffer(m_vboID);
		}
	}

	void VertexBuffer::RenderBuffer( IndexBuffer *iBuffer )
	{
		gs_renderer->RenderBuffer(iBuffer, this);
	}

	unsigned int VertexBuffer::GetVBO()
	{
		return m_vboID;
	}

	int VertexBuffer::GetVertex()
	{
		return m_vertex;
	}

	int VertexBuffer::GetColour()
	{
		return m_colour;
	}

	int VertexBuffer::GetTexCoord()
	{
		return m_texCoord;
	}

	int VertexBuffer::GetNormal()
	{
		return m_normal;
	}

	int VertexBuffer::GetStrideSize()
	{
		return m_strideSize;
	}

	int VertexBuffer::GetStride()
	{
		return m_stride;
	}

	void VertexBuffer::UpdateBuffer( int offset, const float *data, unsigned int vertexCount )
	{
		gs_renderer->UpdateVertexBuffer(this->GetVBO(), offset, data, vertexCount * GetVertex());
	}

	float *VertexBuffer::GetVertexBuffer(int offset, unsigned int length, bufferAccessTypes access)
	{
		return gs_renderer->MapVertexBufferRange(this->GetVBO(), offset, length * GetVertex(), access);
	}

	bool VertexBuffer::UnmapBuffer()
	{
		return gs_renderer->UnmapBuffer(this->GetVBO(), Graphics::X2_ARRAY_BUFFER);
	}

	VertexBuffer * VertexBuffer::Clone()
	{
		float *buff = this->GetVertexBuffer(0, this->GetVertexCount(), X2_MAP_READ_BIT);
		
		VertexBuffer *newBuffer = nullptr;
		
		if (buff != nullptr)
		{
			newBuffer = new VertexBuffer(buff, this->GetVertexCount(), this->GetVertex(), this->GetColour(), this->GetTexCoord(), this->GetNormal(), this->GetStreamType());
		}
		
		this->UnmapBuffer();
		return newBuffer;
	}

	int VertexBuffer::GetVertexCount()
	{
		return m_vertexCount;
	}

	Graphics::streamTypes VertexBuffer::GetStreamType()
	{
		return this->m_streamType;
	}



}