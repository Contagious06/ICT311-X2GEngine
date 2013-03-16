#pragma once
#ifndef MESH_H
#define MESH_H

#include <iostream>
#include <vector>
#include "MeshPart.h"
#include "Material.h"
#include "IAsset.h"
#include "ICloneable.h"
//#include "IRenderer.h"

/**
 * \namespace	Graphics
 *
 * \brief	.
 */

namespace Graphics
{
	class IRenderer;
	class Texture2D;
	/**
	 * \struct	_VTN
	 *
	 * \brief	Vtn.
	 *
	 * \author	Matthew Vlietstra
	 * \date	22/03/2012
	 */

	typedef struct _VTN
	{
		float vx, vy, vz;
		float tx, ty;
		float nx, ny, nz;
	} VTN;

	/**
	 * \class	Mesh
	 *
	 * \brief	Mesh.
	 *
	 * \author	Matthew Vlietstra
	 * \date	22/03/2012
	 */

	class Mesh : public Content::IAsset, public ICloneable<Mesh>
	{
		public:
		/**
		 * \typedef	std::vector<MeshPart*> mp
		 *
		 * \brief	Defines an alias representing the mp.
		 */

		typedef std::vector<MeshPart*> mp;

		/**
		 * \typedef	std::vector<Material*> m
		 *
		 * \brief	Defines an alias representing the m.
		 */

		typedef std::vector<Material*> m;

		/**
		 * \typedef	mp::iterator mpIt
		 *
		 * \brief	Defines an alias representing the mp iterator.
		 */

		typedef mp::iterator mpIt;

		/**
		 * \typedef	m::iterator mIt
		 *
		 * \brief	Defines an alias representing the iterator.
		 */

		typedef m::iterator mIt;
	

		/**
		 * \fn	:::Mesh();
		 *
		 * \brief	Default constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 */

		Mesh();

		/**
		 * Destructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/05/2012
		 */

		~Mesh();
		/**
		 * \fn	:::Mesh(mp *meshParts, m *materials);
		 *
		 * \brief	Constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param [in,out]	meshParts	If non-null, the mesh parts.
		 * \param [in,out]	materials	If non-null, the materials.
		 */

		Mesh(mp *meshParts, m *materials);

		/**
		 * \fn	void :::AddMeshPart(MeshPart *meshPart);
		 *
		 * \brief	Adds a mesh part.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param [in,out]	meshPart	If non-null, the mesh part.
		 */

		void AddMeshPart(MeshPart *meshPart);

		/**
		 * \fn	void :::AddMaterial(Material *material);
		 *
		 * \brief	Adds a material.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param [in,out]	material	If non-null, the material.
		 */

		void AddMaterial(Material *material);

		/**
		 * \fn	void :::AddMaterials(m *materials);
		 *
		 * \brief	Adds a materials.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param [in,out]	materials	If non-null, the materials.
		 */

		void AddMaterials(m *materials);

		/**
		 * \fn	void :::SetVertexBuffer(VertexBuffer *vBuffer);
		 *
		 * \brief	Sets a vertex buffer.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param [in,out]	vBuffer	If non-null, the buffer.
		 */

		void SetVertexBuffer(VertexBuffer *vBuffer);

		/**
		 * \fn	mp :::*GetMeshParts();
		 *
		 * \brief	Gets the mesh parts.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	null if it fails, else the mesh parts.
		 */

		mp *GetMeshParts();

		/**
		 * \fn	void :::Draw();
		 *
		 * \brief	Draws this object.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 */

		void Draw();

		/**
		 * \fn	void :::SetRawVerticies(VTN * verticies, int count);
		 *
		 * \brief	Sets a raw verticies.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param [in,out]	verticies	If non-null, the verticies.
		 * \param	count			 	Number of.
		 */

		void SetRawVerticies(VTN * verticies, int count);

		/**
		 * \fn	VTN :::*GetRawVerticies();
		 *
		 * \brief	Gets the raw verticies.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	null if it fails, else the raw verticies.
		 */

		VTN *GetRawVerticies();

		/**
		 * \fn	int :::GetRawVerticiesCount();
		 *
		 * \brief	Gets the raw verticies count.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	The raw verticies count.
		 */

		int GetRawVerticiesCount();

		/**
		 * \fn	void :::SetIndicies(unsigned int *indicies, int count);
		 *
		 * \brief	Sets the indicies.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param [in,out]	indicies	If non-null, the indicies.
		 * \param	count				Number of.
		 */

		void SetIndicies(unsigned int *indicies, int count);

		/**
		 * \fn	unsigned int :::*GetIndicies();
		 *
		 * \brief	Gets the indicies.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	null if it fails, else the indicies.
		 */

		unsigned int *GetIndicies();

		/**
		 * \fn	int :::GetIndicieCount();
		 *
		 * \brief	Gets the indicie count.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	The indicie count.
		 */

		int GetIndicieCount();

		/**
		 * \fn	m :::*GetMaterial()
		 *
		 * \brief	Gets the material.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \return	null if it fails, else the material.
		 */

		m *GetMaterial();

		/**
		 * \fn	VertexBuffer :::*GetVertexBuffer();
		 *
		 * \brief	Gets the vertex buffer.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \return	null if it fails, else the vertex buffer.
		 */

		VertexBuffer *GetVertexBuffer();

		/**
		 * \fn	void :::SetMeshName(const std::string &name);
		 *
		 * \brief	Sets a mesh name.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 *
		 * \param	name	The name.
		 */

		void SetMeshName(const std::string &name);

		/**
		 * \fn	std::string :::GetMeshName();
		 *
		 * \brief	Gets the mesh name.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 *
		 * \return	The mesh name.
		 */

		std::string GetMeshName();

		/**
		 * Makes a deep copy of this object.
		 *
		 * \author	Matthew Vlietstra
		 * \date	19/05/2012
		 *
		 * \return	null if it fails, else a copy of this object.
		 */

		Mesh *Clone();
	private:

		///< Name of the mesh
		std::string m_meshName;
		///< The indicies
		unsigned int *m_indicies;
		///< Number of indecies
		int m_indecieCount;

		///< Number of verticals
		int m_vertCount;
		///< The raw verticies
		VTN *m_rawVerticies;
		///< Buffer for vertex data
		VertexBuffer *m_vertexBuffer;
		///< The mesh parts
		mp *m_meshParts;
		///< The materials
		m *m_materials;
	};

}

#endif