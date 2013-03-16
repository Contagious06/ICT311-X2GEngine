#include "Mesh.h"
#include "RendererSingleton.h"

namespace Graphics
{
	Mesh::Mesh()
	{
		m_indicies = nullptr;
		m_rawVerticies = nullptr;
		m_vertexBuffer = nullptr;
		m_meshParts = nullptr;
		m_materials = nullptr;

		m_meshParts = new mp();
		m_materials = new m();
		//std::cout << m_meshParts->size();
	}

	Mesh::Mesh( mp *meshParts, m *materials )
	{
		m_indicies = nullptr;
		m_rawVerticies = nullptr;
		m_vertexBuffer = nullptr;
		m_meshParts = nullptr;
		m_materials = nullptr;

		m_meshParts = meshParts;
		m_materials = materials;
	}

	void Mesh::AddMeshPart( MeshPart *meshPart )
	{
		m_meshParts->push_back(meshPart);
	}

	void Mesh::AddMaterial( Material *material )
	{
		m_materials->push_back(material);
	}

	void Mesh::AddMaterials( m *materials )
	{
		if (m_materials != nullptr)
		{
			delete m_materials;
		}
		m_materials = materials;
	}

	void Mesh::SetVertexBuffer( VertexBuffer *vBuffer )
	{
		m_vertexBuffer = vBuffer;
	}

	Mesh::mp * Mesh::GetMeshParts()
	{
		return m_meshParts;
	}

	void Mesh::Draw()
	{
		gs_renderer->RenderMesh(this);
		//int i = 0;
		//for (mpIt it = m_meshParts->begin(); it != m_meshParts->end(); it++)
		//{

		//	unsigned int materialID = (*it)->GetMaterialID();
		//	if (materialID >= 0 && materialID < m_materials->size())
		//	{
		//		//glColor3f(1,1,1);
		//		Material *mat = (*m_materials)[materialID];
		//		//glEnable(GL_LIGHTING);
		//		//glEnable(GL_COLOR_MATERIAL);
		//		//glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat->ambient);
		//		//glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat->diffuse);
		//		//glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat->specular);

		//		if ((*m_materials)[materialID]->mapAmbient != nullptr)
		//		{
		//			glEnable(GL_TEXTURE_2D);
		//			(*m_materials)[materialID]->mapAmbient->Bind();
		//		}
		//	}

		//	m_vertexBuffer->RenderBuffer((*it)->GetIndexBuffer());
		//	glDisable(GL_TEXTURE_2D);

		//	i++;
		//}

	}

	void Mesh::SetRawVerticies( VTN * verticies, int count )
	{
		m_vertCount = count;
		m_rawVerticies = verticies;
	}

	VTN * Mesh::GetRawVerticies()
	{
		return m_rawVerticies;
	}

	int Mesh::GetRawVerticiesCount()
	{
		return m_vertCount;
	}

	void Mesh::SetIndicies( unsigned int *indicies, int count )
	{
		m_indicies = indicies;
		m_indecieCount = count;
	}

	unsigned int * Mesh::GetIndicies()
	{
		return m_indicies;
	}

	int Mesh::GetIndicieCount()
	{
		return m_indecieCount;
	}

	std::vector<Material*> *Mesh::GetMaterial()
	{
		return m_materials;
	}

	VertexBuffer * Mesh::GetVertexBuffer()
	{
		return m_vertexBuffer;
	}

	void Mesh::SetMeshName( const std::string &name )
	{
		m_meshName = name;
	}

	std::string Mesh::GetMeshName()
	{
		return m_meshName;
	}

	Mesh *Mesh::Clone()
	{
		Mesh *newMesh = new Mesh();
		newMesh->m_meshName = this->m_meshName;
		newMesh->m_indicies = nullptr; //Need to actually remove the indicies anyway.
		newMesh->m_indecieCount = 0;   // ^

		newMesh->m_rawVerticies = nullptr;

		newMesh->m_vertexBuffer = this->m_vertexBuffer->Clone();

		for (mpIt it = m_meshParts->begin(); it != m_meshParts->end(); it++)
		{
			newMesh->AddMeshPart((*it)->Clone());
		}


		for (mIt it = this->m_materials->begin(); it != m_materials->end(); it++)
		{
			newMesh->AddMaterial((*it)->Clone());
		}

		return newMesh;
	}

	Mesh::~Mesh()
	{
		if (m_indicies != nullptr)
		{
			delete m_indicies;
		}

		if (m_rawVerticies != nullptr)
		{
			delete m_rawVerticies;
		}

		if (m_vertexBuffer != nullptr)
		{
			delete m_vertexBuffer;
		}

		if (m_meshParts != nullptr)
		{
			for (mpIt it = m_meshParts->begin(); it != m_meshParts->end(); it++)
			{
				delete *it;
			}

			m_meshParts->clear();

			delete m_meshParts;
			m_meshParts = nullptr;
		}


		if (m_materials != nullptr)
		{
			for (mIt it = m_materials->begin(); it != m_materials->end(); it++)
			{
				delete *it;
			}

			m_materials->clear();

			delete m_materials;
			m_materials = nullptr;
		}


	}

}