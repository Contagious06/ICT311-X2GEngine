#pragma once
#ifndef _IRENDERER_H
#define _IRENDERER_H

//#include "OpenGLRenderer.h"
#include <utility>
#include <string>
#include <vector>
#include "glm/glm.hpp"
//#include "Includes.h"
#include "IndexBuffer.h"
#include "VertexBuffer.h"
//#include "Mesh.h"
#include "Rectangle.h"
#include "Texture.h"
//#include "Texture2D.h"
#include "BitmapFont.h"
#include "IShaderManager.h"
//#include "Spark/SPK.h"

class BitmapFont;

/**
 * \namespace	Graphics
 *
 * \brief	.
 */

namespace Graphics
{
	class IndexBuffer;
	class VertexBuffer;
	class Mesh;
	class Texture;
	class Texture2D;
	
	//Circular dependency issues

	/**
	 * \enum	shapeType
	 *
	 * \brief	Values that represent shapeType.
	 */

	enum shapeType { X2_TRIANGLES, X2_TRIANGLESTRIPS, X2_QUADS, X2_QUADSTRIPTS };

	/**
	 * \enum	textureType
	 *
	 * \brief	Values that represent textureType.
	 */

	enum textureType {X2_TEXTURE1D, X2_TEXTURE2D, X2_TEXTURE3D, X2_TEXTURECUBE, X2_UNKNOWNTEXTURE};

	/**
	 * \enum	imageTypes
	 *
	 * \brief	Values that represent imageTypes.
	 */

	enum imageTypes {X2_COLOUR_INDEX, X2_RED, X2_GREEN, X2_BLUE, X2_ALPHA, X2_INTENSITY, X2_RGB, X2_BGR, X2_RGBA, X2_BGRA, X2_LUMINANCE, X2_LUMINANCE_ALPHA, X2_DEPTH_COMPONENT};

	/**
	 * \enum	MATRIX
	 *
	 * \brief	Values that represent MATRIX.
	 */

	enum MATRIX {MODELVIEW, PROJECTION, VIEW, TEXTURE, COLOUR};

	/**
	 * Values that represent streamTypes.
	 */

	enum streamTypes { X2_STREAM_DRAW, X2_DYNAMIC_DRAW, X2_STATIC_DRAW };

	/**
	 * Values that represent bufferAccessTypes.
	 */

	enum bufferAccessTypes { X2_MAP_READ_BIT, X2_MAP_WRITE_BIT };

	/**
	 * Values that represent bufferTypes.
	 */

	enum bufferTypes { X2_ARRAY_BUFFER, X2_ELEMENT_ARRAY_BUFFER, X2_PIXEL_PACK_BUFFER, X2_PIXEL_UNPACK_BUFFER };

	/**
	 * \class	IRenderer
	 *
	 * \brief	Renderer.
	 * \author	Joseph Skelton
	 * \author	Matthew Vlietstra
	 * \date	15/04/2012
	 */

	class IRenderer
	{
		//protected:

		

	public:
		//IRenderer(){};
		//virtual ~IRenderer() = 0;
		
		//enum imageTypes {X2_RGB, X2_RGBA};



		//virtual void Render() = 0;

		/**
		 * @fn	virtual void IRenderer::Rotate(float angle, float x, float y, float z) = 0;
		 *
		 * @brief	Rotates.
		 *
		 * @author	Joseph Skelton
		 * @param	angle	The angle.
		 * @param	x	 	The float to process.
		 * @param	y	 	The float to process.
		 * @param	z	 	The float to process.
		 */

		virtual void Rotate(float angle, float x, float y, float z) = 0;

		/**
		 * @fn	virtual void IRenderer::Translate(float x, float y, float z) = 0;
		 *
		 * @brief	Translates.
		 *
		 * @author	Joseph Skelton
		 * @param	x	The float to process.
		 * @param	y	The float to process.
		 * @param	z	The float to process.
		 */

		virtual void Translate(float x, float y, float z) = 0;

		/**
		 * @fn	virtual void IRenderer::Scale(float x, float y, float z) = 0;
		 *
		 * @brief	Scales.
		 *
		 * @author	Joseph Skelton
		 * @param	x	The float to process.
		 * @param	y	The float to process.
		 * @param	z	The float to process.
		 */

		virtual void Scale(float x, float y, float z) = 0;

		/**
		 * @fn	virtual void IRenderer::SwitchMatrix(MATRIX mode) = 0;
		 *
		 * @brief	Switch matrix.
		 *
		 * @author	Joseph Skelton
		 * @param	mode	The mode.
		 */

		virtual void SwitchMatrix(MATRIX mode) = 0;

		/**
		 * @fn	virtual void IRenderer::SetIdentity() = 0;
		 *
		 * @brief	Sets the identity.
		 *
		 * @author	Joseph Skelton
		 */

		virtual void SetIdentity() = 0;

		/**
		 * @fn	virtual int IRenderer::LoadShader(std::string shaderName) = 0;
		 *
		 * @brief	Loads a shader.
		 *
		 * @author	Joseph Skelton
		 * @param	shaderName	Name of the shader.
		 *
		 * @return	The shader.
		 */

		virtual int LoadShader(std::string shaderName) = 0;

		/**
		 * @fn	virtual void IRenderer::BindShader(int id) = 0;
		 *
		 * @brief	Bind shader.
		 *
		 * @author	Joseph Skelton
		 * @param	id	The identifier.
		 */

		virtual void BindShader(int id) = 0;

		/**
		 * @fn	virtual void IRenderer::UnbindShader(int id) = 0;
		 *
		 * @brief	Unbind shader.
		 *
		 * @author	Joseph Skelton
		 * @param	id	The identifier.
		 */

		virtual void UnbindShader(int id) = 0;

		/**
		 * @fn	virtual void IRenderer::CreateLookAt(float camX, float camY, float camZ, float eyeX,
		 * 		float eyeY, float eyeZ, float upX, float upY, float upZ) = 0;
		 *
		 * @brief	Creates a look at.
		 *
		 * @author	Joseph Skelton
		 * @param	camX	The camera x coordinate.
		 * @param	camY	The camera y coordinate.
		 * @param	camZ	The camera z coordinate.
		 * @param	eyeX	The eye x coordinate.
		 * @param	eyeY	The eye y coordinate.
		 * @param	eyeZ	The eye z coordinate.
		 * @param	upX 	The up x coordinate.
		 * @param	upY 	The up y coordinate.
		 * @param	upZ 	The up z coordinate.
		 */

		virtual void CreateLookAt(float camX, float camY, float camZ, 
									float eyeX, float eyeY, float eyeZ,
									float upX, float upY, float upZ) = 0;

		/**
		 * @fn	virtual void IRenderer::SetPerspective(float angle, float aspectRatio, float nearClip,
		 * 		float farClip) = 0;
		 *
		 * @brief	Sets a perspective.
		 *
		 * @author	Joseph Skelton
		 * @param	angle	   	The angle.
		 * @param	aspectRatio	The aspect ratio.
		 * @param	nearClip   	The near clip.
		 * @param	farClip	   	The far clip.
		 */

		virtual void SetPerspective(float angle, float aspectRatio, float nearClip, float farClip) = 0;

		/**
		 * @fn	virtual void IRenderer::EnableDepthTesting(bool isDepthTested) = 0;
		 *
		 * @brief	Enables the depth testing.
		 *
		 * @author	Joseph Skelton
		 * @param	isDepthTested	true if this IRenderer is depth tested.
		 */

		virtual void EnableDepthTesting(bool isDepthTested) = 0;

		/**
		 * @fn	virtual void IRenderer::ClearScreen() = 0;
		 *
		 * @brief	Clears the screen.
		 *
		 * @author	Joseph Skelton
		 */

		virtual void ClearScreen() = 0;

		/**
		 * @fn	virtual void IRenderer::SetClearColour(float red, float green, float blue,
		 * 		float alpha) = 0;
		 *
		 * @brief	Sets a clear colour.
		 *
		 * @author	Joseph Skelton
		 * @param	red  	The red.
		 * @param	green	The green.
		 * @param	blue 	The blue.
		 * @param	alpha	The alpha.
		 */

		virtual void SetClearColour(float red, float green, float blue, float alpha) = 0;

		/**
		 * @fn	virtual void IRenderer::SwapBuffers() = 0;
		 *
		 * @brief	Swap buffers.
		 *
		 * @author	Joseph Skelton
		 */

		virtual void SwapBuffers() = 0;

		//virtual GLuint BindTex2D() = 0;
		//virtual GLuint BindTex3D() = 0;

		/**
		 * \fn	virtual unsigned int IRenderer::BindTexture2D(imageTypes type, int width, int height,
		 * 		unsigned char *texture) = 0;
		 *
		 * \brief	Bind texture 2 d.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \param	type		   	The type.
		 * \param	width		   	The width.
		 * \param	height		   	The height.
		 * \param [in,out]	texture	If non-null, the texture.
		 *
		 * \return	.
		 */

		virtual void BindTexture2D(unsigned int &id, int activeTexture, imageTypes type, int width, int height, unsigned char *texture) = 0;

		/**
		 * \fn	virtual unsigned int IRenderer::BindTexture3D(imageTypes type, int width, int height,
		 * 		int depth, unsigned char *texture) = 0;
		 *
		 * \brief	Bind texture 3 d.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \param	type		   	The type.
		 * \param	width		   	The width.
		 * \param	height		   	The height.
		 * \param	depth		   	The depth.
		 * \param [in,out]	texture	If non-null, the texture.
		 *
		 * \return	.
		 */

		virtual void BindTexture3D(unsigned int &id, int activeTexture, imageTypes type, int width, int height, int depth, unsigned char *texture) = 0;

		/**
		 * \fn	virtual unsigned int IRenderer::BindTextureCube(imageTypes type, int width, int height,
		 * 		unsigned char *texture) = 0;
		 *
		 * \brief	Bind texture cube.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \param	type		   	The type.
		 * \param	width		   	The width.
		 * \param	height		   	The height.
		 * \param [in,out]	texture	If non-null, the texture.
		 *
		 * \return	.
		 */

		virtual void BindTextureCube(unsigned int &id, int activeTexture, imageTypes type, int width, int height, unsigned char *texture) = 0;

		/**
		 * \fn	virtual void IRenderer::ClearTexture(unsigned int &textureID) = 0;
		 *
		 * \brief	Unbind texture.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \param [in,out]	textureID	Identifier for the texture.
		 *
		 * ### param	activeTexture	The active texture.
		 */

		virtual void ClearTexture(unsigned int &textureID) = 0;

		/**
		 * \fn	virtual void IRenderer::UnbindTexture() = 0;
		 *
		 * \brief	Unbind texture.
		 *
		 * \author	Matthew Vlietstra
		 * \date	30/03/2012
		 */

		virtual void UnbindTexture() = 0;


		//virtual void DrawModel(int shaderID, i)
		// still to do lighting settings methods, material settings methods, draw method (/w texture override).  Will add a WORLD option to the enum if it causes issues.
		// set render targets , render 2d component, bind texture

		/**
		 * \fn	virtual void IRenderer::LoadMatrix(const glm::mat4 &mtrx) = 0;
		 *
		 * \brief	Loads a matrix.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \param	mtrx	The mtrx.
		 */

		virtual void LoadMatrix(const glm::mat4 &mtrx) = 0;

		/**
		 * \fn	virtual unsigned int IRenderer::BindVertexBuffer(const void *buffer,
		 * 		unsigned int vertexCount, int strideSize) = 0;
		 *
		 * \brief	Bind vertex buffer.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \param	buffer	   	The buffer.
		 * \param	vertexCount	Number of vertices.
		 * \param	strideSize 	Size of the stride.
		 *
		 * \return	.
		 */

		virtual unsigned int BindVertexBuffer(const void *buffer, unsigned int vertexCount, int strideSize, streamTypes type ) = 0;

		/**
		 * Updates the vertex buffer.
		 *
		 * @author	Matthew Vlietstra
		 * @date	13/05/2012
		 *
		 * @param	vboId	   	Identifier for the vbo.
		 * @param	offset	   	The offset.
		 * @param	data	   	The data.
		 * @param	vertexCount	Number of vertices.
		 */

		virtual void UpdateVertexBuffer( unsigned int vboId, int offset, const float *data, unsigned int vertexCount ) = 0;

		/**
		 * Map vertex buffer range.
		 *
		 * @author	Matthew Vlietstra
		 * @date	13/05/2012
		 *
		 * @param	vboId 	Identifier for the vbo.
		 * @param	offset	The offset.
		 * @param	length	The length.
		 * @param	access	The access.
		 *
		 * @return	null if it fails, else.
		 */

		virtual float *MapVertexBufferRange(unsigned int vboId, int offset, unsigned int length, bufferAccessTypes access) = 0;

		/**
		 * Map index buffer range.
		 *
		 * @author	Matthew Vlietstra
		 * @date	13/05/2012
		 *
		 * @param	vboId 	Identifier for the vbo.
		 * @param	offset	The offset.
		 * @param	length	The length.
		 * @param	access	The access.
		 *
		 * @return	.
		 */

		virtual unsigned int *MapIndexBufferRange(unsigned int vboId, int offset, unsigned int length, bufferAccessTypes access) = 0;

		/**
		 * Unmap buffer.
		 *
		 * @author	Matthew Vlietstra
		 * @date	13/05/2012
		 *
		 * @param	type	The type.
		 *
		 * @return	true if it succeeds, false if it fails.
		 */

		virtual bool UnmapBuffer(int vboId, bufferTypes type) = 0;
		
		

		/**
		 * \fn	virtual unsigned int IRenderer::BindIndexBuffer(unsigned int *indexBuffer,
		 * 		unsigned int indiceCount, shapeType shape) = 0;
		 *
		 * \brief	Bind index buffer.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \param [in,out]	indexBuffer	If non-null, buffer for index data.
		 * \param	indiceCount		   	Number of indices.
		 * \param	shape			   	The shape.
		 *
		 * \return	.
		 */

		virtual unsigned int BindIndexBuffer(unsigned int *indexBuffer, unsigned int indiceCount, shapeType shape, streamTypes type) = 0;

		/**
		 * Updates the index buffer.
		 *
		 * @author	Matthew Vlietstra
		 * @date	13/05/2012
		 *
		 * @param	vboId 	Identifier for the vbo.
		 * @param	offset	The offset.
		 * @param	data  	The data.
		 */

		virtual void UpdateIndexBuffer(unsigned int vboId, int offset, const unsigned int *data, unsigned int indiceCount) = 0;

		/**
		 * \fn	virtual void IRenderer::DeleteBuffer(unsigned int bufferID) = 0;
		 *
		 * \brief	Deletes the buffer described by bufferID.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \param	bufferID	Identifier for the buffer.
		 */

		virtual void DeleteBuffer(unsigned int bufferID) = 0;

		/**
		 * \fn	virtual void IRenderer::RenderBuffer(IndexBuffer *indexBuffer,
		 * 		VertexBuffer *vertexBuffer) = 0;
		 *
		 * \brief	Renders the buffer.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \param [in,out]	indexBuffer 	If non-null, buffer for index data.
		 * \param [in,out]	vertexBuffer	If non-null, buffer for vertex data.
		 */

		virtual void RenderBuffer(IndexBuffer *indexBuffer, VertexBuffer *vertexBuffer) = 0;

		/**
		 * \fn	virtual void IRenderer::RenderMesh(Mesh *mesh) = 0;
		 *
		 * \brief	Renders the mesh described by mesh.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \param [in,out]	mesh	If non-null, the mesh.
		 */

		virtual void RenderMesh(Mesh *mesh) = 0;

		/**
		 * \fn	virtual void IRenderer::SParameter1i(unsigned int shaderID, const std::string &name,
		 * 		int value) = 0;
		 *
		 * \brief	Parameter 1i.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 *
		 * \param	shaderID	Identifier for the shader.
		 * \param	name		The name.
		 * \param	value   	The value.
		 */

		virtual void SParameter1i(unsigned int shaderID, const std::string &name, int value) = 0;

		/**
		 * \fn	virtual void IRenderer::SParameter1fv(unsigned int shaderID, const std::string &name,
		 * 		float value) = 0;
		 *
		 * \brief	Parameter 1fv.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 *
		 * \param	shaderID	Identifier for the shader.
		 * \param	name		The name.
		 * \param	value   	The value.
		 */

		virtual void SParameter1fv(unsigned int shaderID, const std::string &name, float value) = 0;

		/**
		 * \fn	virtual void IRenderer::SParameter4f(unsigned int shaderID, const std::string &name,
		 * 		float v0, float v1, float v2, float v3) = 0;
		 *
		 * \brief	Draw texture.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 *
		 * \param	shaderID	If non-null, the texture.
		 * \param	name		The location.
		 * \param	v0			The rectangle.
		 * \param	v1			The fade.
		 * \param	v2			The second float.
		 * \param	v3			The third float.
		 */

		virtual void SParameter4f(unsigned int shaderID, const std::string &name, float v0, float v1, float v2, float v3) = 0;

		/**
		 * \fn	virtual void IRenderer::SParameter3f(unsigned int shaderID, const std::string &name,
		 * 		float v0, float v1, float v2) = 0;
		 *
		 * \brief	Parameter 3f.
		 *
		 * \author	Matthew Vlietstra
		 * \date	10/04/2012
		 *
		 * \param	shaderID	Identifier for the shader.
		 * \param	name		The name.
		 * \param	v0			The v 0.
		 * \param	v1			The first float.
		 * \param	v2			The second float.
		 */

		virtual void SParameter3f(unsigned int shaderID, const std::string &name, float v0, float v1, float v2) = 0;

		/**
		 * \fn	virtual void IRenderer::SParameterMatrix4fv(unsigned int shaderID,
		 * 		const std::string &name, const glm::mat4x4 &matrix) = 0;
		 *
		 * \brief	Draw texture.
		 *
		 * \author	Matthew Vlietstra
		 * \date	31/03/2012
		 *
		 * \param	shaderID	If non-null, the texture.
		 * \param	name		The location.
		 * \param	matrix  	The rectangle.
		 *
		 * ### param	fade	The fade.
		 */

		virtual void SParameterMatrix4fv(unsigned int shaderID, const std::string &name, const glm::mat4x4 &matrix) = 0;

		/**
		 * \fn	virtual void IRenderer::DrawTexture(Texture2D *texture, const glm::vec2 &location,
		 * 		Rectangle &rectangle, float fade) = 0;
		 *
		 * \brief	Draw texture.
		 *
		 * \author	Matthew Vlietstra
		 * \date	1/04/2012
		 *
		 * \param [in,out]	texture  	If non-null, the texture.
		 * \param	location		 	The location.
		 * \param [in,out]	rectangle	The rectangle.
		 * \param	fade			 	The fade.
		 */

		virtual void DrawTexture(Texture2D *texture, const glm::vec2 &location, float rotation, const glm::vec2 &scale, Rectangle &rectangle, const glm::vec4 &colour) = 0;

		/**
		 * \fn	virtual void IRenderer::ClearColour(float r, float g, float b, float a) = 0;
		 *
		 * \brief	Clears the colour.
		 *
		 * \author	Matthew Vlietstra
		 * \date	27/03/2012
		 *
		 * \param	r	The r.
		 * \param	g	The g.
		 * \param	b	The b.
		 * \param	a	a.
		 */

		virtual void ClearColour(float r, float g, float b, float a) = 0;


		/**
		 * \fn	virtual void IRenderer::RenderText(const std::string &text, const BitmapFont *font,
		 * 		const glm::vec2 &location, const glm::vec3 &colour, float fade) = 0;
		 *
		 * \brief	Renders the text.
		 *
		 * \author	Matthew Vlietstra
		 * \date	27/03/2012
		 *
		 * \param	text		The text.
		 * \param	font		The font.
		 * \param	location	The location.
		 * \param	colour  	The colour.
		 * \param	fade		The fade.
		 */

		virtual void RenderText(const std::string &text, const BitmapFont *font, const glm::vec2 &location, const glm::vec3 &colour, float fade) = 0;

		/**
		 * \fn	virtual void IRenderer::WireFrame(bool wireFrame) = 0;
		 *
		 * \brief	Wire frame.
		 *
		 * \author	Matthew Vlietstra
		 * \date	10/04/2012
		 *
		 * \param	wireFrame	true to wire frame.
		 */

		virtual void WireFrame(bool wireFrame) = 0;

		/**
		 * \fn	virtual unsigned int IRenderer::GetDrawnVertexCount() = 0;
		 *
		 * \brief	Gets the drawn vertex count.
		 *
		 * \author	Matthew Vlietstra
		 * \date	10/04/2012
		 *
		 * \return	The drawn vertex count.
		 */

		virtual unsigned int GetDrawnVertexCount() = 0;

		//virtual void SwapBuffers() = 0;


//		virtual void DrawModel(int ModelID) = 0;
//		virtual unsigned int AddModelArray(const float *vertices, const float *colorBufferData, const float *texCoords, const float *normalMap,
//			unsigned int bufferSize, int isNormalized, int shader, unsigned int texture) = 0;
		
		virtual int CreateLight(const glm::vec4 &ambient, const glm::vec4 &diffuse, const glm::vec4 &specular, const glm::vec4 &position) = 0;

		//virtual void SetMaterial(float *ambient, float *diffuse, float *specular, float *shininess) = 0;
		virtual bool SetLight(int lightIndex, const glm::vec4 &ambient, const glm::vec4 &diffuse, const glm::vec4 &specular, const glm::vec4 &position) = 0;

		virtual glm::vec2 GetScreenDimensions() = 0;

		/**
		 * \fn	virtual void IRenderer::PushMatrix() = 0;
		 *
		 * \brief	Pushes the matrix.
		 *
		 * \author	Matthew Vlietstra
		 * \date	10/04/2012
		 */

		virtual void PushMatrix() = 0;

		/**
		 * \fn	virtual void IRenderer::PopMatrix() = 0;
		 *
		 * \brief	Pops the matrix.
		 *
		 * \author	Matthew Vlietstra
		 * \date	10/04/2012
		 */

		virtual void PopMatrix() = 0;

		/**
		 * \fn	virtual void IRenderer::CullFrontFace() = 0;
		 *
		 * \brief	Cull front face.
		 *
		 * \author	Matthew Vlietstra
		 * \date	10/04/2012
		 */

		virtual void CullFrontFace() = 0;

		/**
		 * \fn	virtual void IRenderer::CullBackFace() = 0;
		 *
		 * \brief	Cull back face.
		 *
		 * \author	Matthew Vlietstra
		 * \date	10/04/2012
		 */

		virtual void CullBackFace() = 0;

		/**
		 * \fn	virtual void IRenderer::EnableDepthTest(bool enable) = 0;
		 *
		 * \brief	Tests enable depth.
		 *
		 * \author	Matthew Vlietstra
		 * \date	10/04/2012
		 *
		 * \param	enable	true to enable, false to disable.
		 */

		virtual void EnableDepthTest(bool enable) = 0;

		/**
		 * \fn	virtual void IRenderer::EnableColourMaterial(bool enable) = 0;
		 *
		 * \brief	Enables the colour material.
		 *
		 * \author	Matthew Vlietstra
		 * \date	10/04/2012
		 *
		 * \param	enable	true to enable, false to disable.
		 */

		virtual void EnableColourMaterial(bool enable) = 0;

		/**
		 * \fn	virtual void IRenderer::EnableCullFace(bool enable) = 0;
		 *
		 * \brief	Enables the cull face.
		 *
		 * \author	Matthew Vlietstra
		 * \date	10/04/2012
		 *
		 * \param	enable	true to enable, false to disable.
		 */

		virtual void EnableCullFace(bool enable) = 0;

		/**
		 * \fn	virtual void IRenderer::LoadIdentity() = 0;
		 *
		 * \brief	Loads the identity.
		 *
		 * \author	Matthew Vlietstra
		 * \date	10/04/2012
		 */

		virtual void LoadIdentity() = 0;

		/**
		 * \fn	virtual void IRenderer::ClearLights() = 0;
		 *
		 * \brief	Clears the lights.
		 *
		 * \author	Matthew Vlietstra
		 * \date	10/04/2012
		 */

		virtual void ClearLights() = 0;

		/**
		 * \fn	virtual int IRenderer::GetLightCount() = 0;
		 *
		 * \brief	Gets the light count.
		 *
		 * \author	Matthew Vlietstra
		 * \date	10/04/2012
		 *
		 * \return	The light count.
		 */

		virtual int GetLightCount() = 0;

		//virtual void SetMaterialToDefault() = 0;
//		virtual void SetCurrentShader(int shaderIndex) = 0;
		
		//virtual void BindMaterial(int materialIndex, int shader) = 0;
		//virtual void BindLight(int materialIndex, int shader) = 0;
		/*
		virtual void SetViewMatrix(glm::mat4 view) = 0;
		virtual void SetProjectionMatrix(glm::mat4 projection) = 0;
		virtual void SetWorldMatrix(glm::mat4 world) = 0;
		virtual void SetMVP(glm::mat4 mvp) = 0;
		*/

		/**
		 * @fn	virtual SPK::Renderer* IRenderer::SetupParticleRenderer(unsigned int screenHeight,
		 * 		float size, std::string texture) = 0;
		 *
		 * @brief	Sets up the particle renderer.
		 *
		 * @author	Joseph Skelton
		 * @param	screenHeight	Height of the screen.
		 * @param	size			The size.
		 * @param	texture			The texture.
		 *
		 * @return	null if it fails, else.
		 */

		//virtual SPK::Renderer* SetupParticleRenderer(unsigned int screenHeight, float size,  std::string texture, int shaderID) = 0;

		/**
		 * @fn	virtual void IRenderer::RenderParticles(std::deque<SPK::System*> &activeSystems) = 0;
		 *
		 * @brief	Renders the particles described by activeSystems.
		 *
		 * @author	Joseph Skelton
		 * @param [in,out]	activeSystems	[in,out] If non-null, the active systems.
		 */

		//virtual void RenderParticles(std::deque<SPK::System*> &activeSystems, int shaderID, bool drawBB) = 0;

		/**
		 * @fn	virtual void IRenderer::SetupFrameBuffer() = 0;
		 *
		 * @brief	Sets up the frame buffer.
		 *
		 * @author	Joseph Skelton
		 */

		virtual void SetupFrameBuffer() = 0;

		/**
		 * @fn	virtual void IRenderer::SwitchRenderTarget(bool renderToTexture) = 0;
		 *
		 * @brief	Switch render target.
		 *
		 * @author	Joseph Skelton
		 * @param	renderToTexture	true to render to texture, false to render to screen
		 */

		virtual void SwitchRenderTarget(bool renderToTexture) = 0;



		virtual void DrawPixels(int width, int height, imageTypes type, const unsigned char *buffer) = 0;

	};
}
#endif