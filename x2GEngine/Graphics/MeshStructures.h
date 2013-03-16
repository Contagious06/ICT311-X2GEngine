#pragma once
#ifndef MESHSTRUCTURES_H
#define MESHSTRUCTURES_H

#include <iostream>
#include <vector>

/**
 * \brief	Vertex colour texture coordinate normal.
 *
 * \author	Matthew Vlietstra
 * \date	22/05/2012
 */

typedef struct _VertexColourTextureCoordinateNormal
{
	///< The vz
	float vx, vy, vz;
	///< The cb
	float cr, cg, cb;
	///< The ty
	float tx, ty;
	///< The nz
	float nx, ny, nz;

	///< Number of vertices
	static const int vertexCount = 3;
	///< Number of colours
	static const int colourCount = 3;
	///< Number of texture coordinates
	static const int textureCoordinateCount = 2;
	///< Number of normals
	static const int normalCount = 3;
} VertexColourTextureCoordinateNormal;

/**
 * \brief	Vertex colour texture coordinate 3 d normal.
 *
 * \author	Matthew Vlietstra
 * \date	22/05/2012
 */

typedef struct _VertexColourTextureCoordinate3DNormal
{
	///< The vz
	float vx, vy, vz;
	///< The cb
	float cr, cg, cb;
	///< The tz
	float tx, ty, tz;
	///< The nz
	float nx, ny, nz;

	///< Number of vertices
	static const int vertexCount = 3;
	///< Number of colours
	static const int colourCount = 3;
	///< Number of texture coordinates
	static const int textureCoordinateCount = 3;
	///< Number of normals
	static const int normalCount = 3;
} VertexColourTextureCoordinate3DNormal;

/**
 * \brief	Vertex texture coordinate normal.
 *
 * \author	Matthew Vlietstra
 * \date	22/05/2012
 */

typedef struct _VertexTextureCoordinateNormal
{
	///< The vz
	float vx, vy, vz;
	///< The ty
	float tx, ty;
	///< The nz
	float nx, ny, nz;

	///< Number of vertices
	static const int vertexCount = 3;
	///< Number of colours
	static const int colourCount = 0;
	///< Number of texture coordinates
	static const int textureCoordinateCount = 2;
	///< Number of normals
	static const int normalCount = 3;
} VertexTextureCoordinateNormal;

/**
 * \brief	Vertex texture coordinate 3 d normal.
 *
 * \author	Matthew Vlietstra
 * \date	22/05/2012
 */

typedef struct _VertexTextureCoordinate3DNormal
{
	///< The vz
	float vx, vy, vz;
	///< The tz
	float tx, ty, tz;
	///< The nz
	float nx, ny, nz;

	///< Number of vertices
	static const int vertexCount = 3;
	///< Number of colours
	static const int colourCount = 0;
	///< Number of texture coordinates
	static const int textureCoordinateCount = 3;
	///< Number of normals
	static const int normalCount = 3;
} VertexTextureCoordinate3DNormal;

#endif