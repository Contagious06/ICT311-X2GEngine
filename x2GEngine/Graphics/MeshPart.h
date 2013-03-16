#pragma once
#ifndef MESHPART_H
#define MESHPART_H

#include <vector>
#include <string>
#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "glm/glm.hpp"
#include "ICloneable.h"

/**
 * \namespace	Graphics
 *
 * \brief	.
 */

namespace Graphics
{
	class IRenderer;
	class Texture2D;
	class IndexBuffer;
	class VertexBuffer;

	/**
	 * \class	MeshPart
	 *
	 * \brief	Mesh part.
	 *
	 * \author	Matthew Vlietstra
	 * \date	24/03/2012
	 */

	class MeshPart : public ICloneable<MeshPart>
	{
	public:

		/**
		 * \fn	MeshPart::MeshPart();
		 *
		 * \brief	Default constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 */

		MeshPart();

		/**
		 * \fn	MeshPart::MeshPart(const std::string &name, int materialID, IndexBuffer *indexBuff);
		 *
		 * \brief	Constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \param	name			 	The name.
		 * \param	materialID		 	Identifier for the material.
		 * \param [in,out]	indexBuff	If non-null, buffer for index data.
		 */

		MeshPart(const std::string &name, int materialID, IndexBuffer *indexBuff);

		/**
		 * Destructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/05/2012
		 */

		~MeshPart();

		/**
		 * \fn	const std::string MeshPart::&GetName() const;
		 *
		 * \brief	Gets the name.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \return	The name.
		 */

		const std::string &GetName() const;

		/**
		 * \fn	int MeshPart::GetMaterialID() const;
		 *
		 * \brief	Gets the material identifier.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \return	The material identifier.
		 */

		int GetMaterialID() const;

		/**
		 * \fn	IndexBuffer MeshPart::*GetIndexBuffer() const;
		 *
		 * \brief	Gets the index buffer.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \return	null if it fails, else the index buffer.
		 */

		IndexBuffer *GetIndexBuffer() const;

		/**
		 * \fn	void MeshPart::SetMaterialID(int ID);
		 *
		 * \brief	Sets a material identifier.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \param	ID	The identifier.
		 */

		void SetMaterialID(int ID);

		/**
		 * \fn	void MeshPart::SetMaterialName(const std::string &name);
		 *
		 * \brief	Sets a material name.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \param	name	The name.
		 */

		void SetMaterialName(const std::string &name);

		/**
		 * \fn	IndexBuffer MeshPart::*SetIndexBuffer(IndexBuffer *indexBuffer);
		 *
		 * \brief	Sets an index buffer.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \param [in,out]	indexBuffer	If non-null, buffer for index data.
		 *
		 * \return	null if it fails, else.
		 */

		IndexBuffer *SetIndexBuffer(IndexBuffer *indexBuffer);

		/**
		 * \fn	void MeshPart::SetBoxHalf(glm::vec3 boxHalf);
		 *
		 * \brief	Sets a box half.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \param	boxHalf	The box half.
		 */

		void SetBoxHalf(glm::vec3 boxHalf);

		/**
		 * \fn	glm::vec3 MeshPart::GetBoxHalf();
		 *
		 * \brief	Gets the box half.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \return	The box half.
		 */

		glm::vec3 GetBoxHalf();

		/**
		 * \fn	const glm::mat4 MeshPart::&GetTransformation();
		 *
		 * \brief	Gets the transformation.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \return	The transformation.
		 */

		const glm::mat4 &GetTransformation();

		/**
		 * \fn	void MeshPart::SetTransformation(const glm::mat4 &transformation);
		 *
		 * \brief	Sets a transformation.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \param	transformation	The transformation.
		 */

		void SetTransformation(const glm::mat4 &transformation);

		/**
		 * Makes a deep copy of this object.
		 *
		 * \author	Matthew Vlietstra
		 * \date	19/05/2012
		 *
		 * \return	null if it fails, else a copy of this object.
		 */

		MeshPart *Clone();
	private:
		///< The name
		std::string m_name;
		///< Identifier for the material
		int m_materialID;
		///< The box half
		glm::vec3 m_boxHalf;
		//VertexBuffer *m_vertexBuffer;
		///< Buffer for index data
		IndexBuffer *m_indexBuffer;
		///< The transformation
		glm::mat4 m_transformation;
	};

}

#endif