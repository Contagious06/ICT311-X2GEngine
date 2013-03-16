#pragma once

#ifndef MATERIAL_H
#define MATERIAL_H

#include <map>
#include <string>
#include <vector>
//#include <stdexcept>
#include "IAsset.h"
#include "Texture.h"
#include "Texture2D.h"
#include "ICloneable.h"

/**
 * \namespace	Graphics
 *
 * \brief	.
 */

namespace Graphics
{
	/**
	 * \struct	_Material
	 *
	 * \brief	Material.
	 *
	 * \author	Matthew Vlietstra
	 * \date	22/03/2012
	 */
	class Texture;
	class Texture2D;
	class IRenderer;

	typedef struct _Material : public ICloneable<_Material>
	{
		/* Ref: http://en.wikipedia.org/wiki/Wavefront_.obj_file
		0. Color on and Ambient off
		1. Color on and Ambient on
		2. Highlight on
		3. Reflection on and Ray trace on
		4. Transparency: Glass on, Reflection: Ray trace on
		5. Reflection: Fresnel on and Ray trace on
		6. Transparency: Refraction on, Reflection: Fresnel off and Ray trace on
		7. Transparency: Refraction on, Reflection: Fresnel on and Ray trace on
		8. Reflection on and Ray trace off
		9. Transparency: Glass on, Reflection: Ray trace off
		10. Casts shadows onto invisible surfaces
		*/

		/**
		 * \fn	_Material()
		 *
		 * \brief	Default constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 */

		_Material()
		{
			diffuse[0] = 0.8f;
			diffuse[1] = 0.8f;
			diffuse[2] = 0.8f;
			diffuse[3] = 1.0f;

			ambient[0] = 0.0f;
			ambient[1] = 0.0f;
			ambient[2] = 0.0f;
			ambient[3] = 1.0f;

			specular[0] = 0.0f;
			specular[1] = 0.0f;
			specular[2] = 0.0f;
			specular[3] = 1.0f;

			transmissionFilter[0] = 0.0f;
			transmissionFilter[1] = 0.0f;
			transmissionFilter[2] = 0.0f;

			specularWeight = 10.0;

			mapAmbient = nullptr;
			mapDiffuse = nullptr;
			mapSpecular = nullptr;
			mapAlpha = nullptr;
			bumpMap = nullptr;
			mapReflect = nullptr;
			name = "";

			m_bumpAmount = 1.0f;

			effect = "BasicEffect";

			cullFace = true;

			effectID = -1;
		}

		///< The illumination
		int illumination;

		///< The diffuse
		float diffuse[4];
		///< The ambient
		float ambient[4];
		///< The specular
		float specular[4];
		///< A filter specifying the transmission
		float transmissionFilter[3];

		///< The specular weight
		float specularWeight; //Specular Weight -> num between 0 & 1000
		///< The optical density
		float opticalDensity;
		///< The transparency
		float transparency;

		///< The map ambient
		Graphics::Texture *mapAmbient;
		///< The map diffuse
		Graphics::Texture *mapDiffuse;
		///< The map specular
		Graphics::Texture *mapSpecular;
		///< The map alpha
		Graphics::Texture *mapAlpha;
		///< The bump map
		Graphics::Texture *bumpMap;

		Graphics::Texture *mapReflect;

		///< The bump amount
		float m_bumpAmount;

		///< The name
		std::string name;

		///< The effect
		std::string effect;

		///< true to cull face
		bool cullFace;

		///< Identifier for the effect
		int effectID;

		_Material *Clone()
		{
			Material *mat = new Material(*this);
			return mat;
		}
	} Material;

	//Used in the content loader as theres multiple materials in a material file

	/**
	 * \struct	_MaterialVector
	 *
	 * \brief	Material vector.
	 *
	 * \author	Matthew Vlietstra
	 * \date	22/03/2012
	 */

	typedef struct _MaterialVector  : public Content::IAsset, public ICloneable<_MaterialVector>
	{
		/**
		 * \fn	_MaterialVector()
		 *
		 * \brief	Default constructor.
		 *
		 * \author	Matthew Vlietstra
		 * \date	22/03/2012
		 */

		_MaterialVector()
		{
			materials = nullptr;
		}

		_MaterialVector *Clone()
		{
			if (materials == nullptr) return nullptr;

			std::vector<Material*> *newMat = new std::vector<Material*>;

			std::vector<Material*>::iterator it;
			for (it = materials->begin(); it != materials->end(); it++)
			{
				newMat->push_back((*it)->Clone());
			}

			_MaterialVector *newMatV = new _MaterialVector();
			newMatV->materials = newMat;

			return newMatV;
		}

		///< The materials
		std::vector<Material*> *materials;
		//std::map<std::string, Material*> *materials;
	} MaterialVector;
}
#endif