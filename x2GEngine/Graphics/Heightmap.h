#pragma once

#ifndef HEIGHTMAP_H
#define HEIGHTMAP_H
#include <iostream>
#include "Texture2D.h"
#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "glm/glm.hpp"
#include "Mesh.h"
#include "MeshPart.h"
#include "Material.h"

/**
 * \namespace	Graphics
 *
 * \brief	.
 */

namespace Graphics
{
	/**
	 * \class	Heightmap
	 *
	 * \brief	Heightmap.
	 *
	 * \author	Matthew Vlietstra
	 * \date	22/03/2012
	 */

	class Heightmap
	{
	public:

		/**
		 * \fn	Heightmap::Heightmap(Texture2D *image, const glm::vec3 &textureScale,
		 * 		const glm::vec3 &textureOffset);
		 *
		 * \brief	Constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param [in,out]	image	If non-null, the image.
		 * \param	textureScale 	The texture scale.
		 * \param	textureOffset	The texture offset.
		 */

		Heightmap(Texture2D *image, const glm::vec3 &textureScale, const glm::vec3 &textureOffset);


		Heightmap(Texture2D *image, const glm::vec3 &textureScale, const glm::vec3 &textureOffset, MaterialVector *material);

		/**
		 * \fn	Heightmap::~Heightmap();
		 *
		 * \brief	Destructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 */

		~Heightmap();

		/**
		 * \fn	float Heightmap::GetHeight(float x, float y);
		 *
		 * \brief	Gets a height.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param	x	The x coordinate.
		 * \param	y	The y coordinate.
		 *
		 * \return	The height.
		 */

		float GetHeight(float x, float y);

		/**
		 * \fn	void Heightmap::RenderHeightMap();
		 *
		 * \brief	Renders the height map.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 */

		void RenderHeightMap();


		void RenderHeightMap(glm::mat4x4 *translation);
		/**
		 * \fn	float Heightmap::*GetVerticies();
		 *
		 * \brief	Gets the verticies.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	null if it fails, else the verticies.
		 */

		float *GetVerticies();

		/**
		 * \fn	int Heightmap::GetWidth();
		 *
		 * \brief	Gets the width.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	The width.
		 */

		int GetWidth();

		/**
		 * \fn	int Heightmap::GetDepth();
		 *
		 * \brief	Gets the depth.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	The depth.
		 */

		int GetDepth();

		/**
		 * \fn	float Heightmap::GetMinHeight();
		 *
		 * \brief	Gets the minimum height.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	The minimum height.
		 */

		float GetMinHeight();

		/**
		 * \fn	float Heightmap::GetMaxHeight();
		 *
		 * \brief	Gets the maximum height.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	The maximum height.
		 */

		float GetMaxHeight();

		/**
		 * \fn	unsigned char Heightmap::*GetImageData();
		 *
		 * \brief	Gets the image data.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \return	null if it fails, else the image data.
		 */

		unsigned char *GetImageData();
	private:

		/**
		 * \struct	_VCTN
		 *
		 * \brief	Vctn.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 */

		typedef struct _VCTN
		{
			float vx, vy, vz; 
			float cr, cg, cb;
			float tx, ty, tz;
			float nx, ny, nz;
		} VCTN;

		/**
		 * \struct	_VTN
		 *
		 * \brief	Vtn.
		 *
		 * \author	Matthew Vlietstra
		 * \date	27/03/2012
		 */

		typedef struct _VTN
		{
			float vx, vy, vz; 
			float tx, ty, tz;
			//float nx, ny, nz;
		} VTN;


		/**
		 * \fn	void Heightmap::GenerateHeightMap(Texture2D *image, const glm::vec3 &textureScale,
		 * 		const glm::vec3 &textureOffset);
		 *
		 * \brief	Generates a height map.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 *
		 * \param [in,out]	image	If non-null, the image.
		 * \param	textureScale 	The texture scale.
		 * \param	textureOffset	The texture offset.
		 */

		void GenerateHeightMap(Texture2D *image, const glm::vec3 &textureScale, const glm::vec3 &textureOffset, Graphics::MaterialVector *material);

		///< The texture x coordinate
		int m_textureX;
		///< The texture y coordinate
		int m_textureY;
		
		//float m_width;
		//float m_height;
		//float m_depth;

		//float m_minHeight;
		//float m_maxHeight;

		///< The collision verticies
		float *m_collisionVerticies;

		///< Information describing the image
		unsigned char *m_imageData;
		///< Buffer for index data
		//Graphics::IndexBuffer *m_indexBuffer;
		///< Buffer for vertex data
		//Graphics::VertexBuffer *m_vertexBuffer;


		Graphics::Mesh *m_mesh;

		void ComputeNormals(VTN vtn1, VTN vtn2, VTN vtn3);
	};


}

#endif