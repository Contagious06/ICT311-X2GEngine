#include "MeshPart.h"

namespace Graphics
{



	MeshPart::MeshPart()
	{
		m_name = "NoName";
		m_materialID = -1;
		m_indexBuffer = nullptr;
		m_transformation = glm::mat4(1.0f);
	}

	MeshPart::MeshPart( const std::string &name, int materialID, IndexBuffer *indexBuff )
	{
		m_name = name;
		m_materialID = materialID;

		//m_vertexBuffer = vertexBuff;
		m_indexBuffer = indexBuff;
	}

	MeshPart::~MeshPart()
	{
		if (m_indexBuffer != nullptr)
		{
			delete m_indexBuffer;
		}
	}

	const std::string & MeshPart::GetName() const
	{
		return m_name;
	}

	int MeshPart::GetMaterialID() const
	{
		return m_materialID;
	}

	IndexBuffer * MeshPart::GetIndexBuffer() const
	{
		return m_indexBuffer;
	}

	void MeshPart::SetMaterialID( int ID )
	{
		m_materialID = ID;
	}

	void MeshPart::SetMaterialName( const std::string &name )
	{
		m_name = name;
	}

	IndexBuffer * MeshPart::SetIndexBuffer( IndexBuffer *indexBuffer )
	{
		IndexBuffer *oldIndexBuffer = m_indexBuffer;
		m_indexBuffer = indexBuffer;

		return oldIndexBuffer; // return the old index buffer, this should be removed..
	}

	void MeshPart::SetBoxHalf( glm::vec3 boxHalf )
	{
		m_boxHalf = boxHalf;
	}

	glm::vec3 MeshPart::GetBoxHalf()
	{
		return m_boxHalf;
	}

	const glm::mat4 & MeshPart::GetTransformation()
	{
		return m_transformation;
	}

	void MeshPart::SetTransformation( const glm::mat4 &transformation )
	{
		m_transformation = transformation;
	}

	MeshPart *MeshPart::Clone()
	{
		MeshPart *newMP = new MeshPart();

		newMP->m_name = this->m_name;
		newMP->m_materialID = this->m_materialID;
		newMP->m_boxHalf = this->m_boxHalf;
		newMP->m_indexBuffer = this->m_indexBuffer->Clone();
		newMP->m_transformation = this->m_transformation;

		return newMP;
	}



}