#pragma once
#ifndef _IRENDERER_GL_H
#define _IRENDERER_GL_H

#include "Includes.h"
#include "IRenderer.h"
#include <string>
#include <vector>
//#include "Shader.h"
//#include "IShaderManager.h"
//#include "ShaderStorage.h"
#include "ShaderManagerSingleton.h"
#include "glm/gtc/type_ptr.hpp"
#include "Mesh.h"
#include "BitmapFont.h"
//#include "Spark/SPK.h"
//#include "Spark/SPK_GL.h"
#include "ResourceManagerSingleton.h"
//#include "MeshPart.h"

/**
 * \namespace	Graphics
 *
 * \brief	.
 */

namespace Graphics
{
	class IShaderManager;

	/**
	 * \class	OpenGLRenderer
	 *
	 * \brief	Open gl renderer.
	 *
	 * \author	Joseph Skelton
	 * \author	Matthew Vlietstra
	 * \date	15/04/2012
	 */

	class OpenGLRenderer : public IRenderer
	{
	public:

		/**
		 * @fn	OpenGLRenderer::OpenGLRenderer();
		 *
		 * @brief	Default constructor.
		 *
		 * @author	Joseph Skelton
		 */

		OpenGLRenderer();

		/**
		 * @fn	OpenGLRenderer::~OpenGLRenderer();
		 *
		 * @brief	Destructor.
		 *
		 * @author	Joseph Skelton
		 */

		~OpenGLRenderer();


		//enum MATRIX {MODELVIEW, PROJECTION, VIEW};

		/**
		 * @fn	void OpenGLRenderer::Rotate(float angle, float x, float y, float z);
		 *
		 * @brief	Rotates.
		 *
		 * @author	Joseph Skelton
		 * @param	angle	The angle.
		 * @param	x	 	The float to process.
		 * @param	y	 	The float to process.
		 * @param	z	 	The float to process.
		 */

		void Rotate(float angle, float x, float y, float z);

		/**
		 * @fn	void OpenGLRenderer::Translate(float x, float y, float z);
		 *
		 * @brief	Translates.
		 *
		 * @author	Joseph Skelton
		 * @param	x	The float to process.
		 * @param	y	The float to process.
		 * @param	z	The float to process.
		 */

		void Translate(float x, float y, float z);

		/**
		 * @fn	void OpenGLRenderer::Scale(float x, float y, float z);
		 *
		 * @brief	Scales.
		 *
		 * @author	Joseph Skelton
		 * @param	x	The float to process.
		 * @param	y	The float to process.
		 * @param	z	The float to process.
		 */

		void Scale(float x, float y, float z);
		
		virtual void SwitchMatrix(MATRIX mode)
		{
			glMatrixMode(GetGLMatrixType(mode));
		}

		void SetIdentity();

		/**
		 * @fn	int OpenGLRenderer::LoadShader(std::string shaderName);
		 *
		 * @brief	Loads a shader.
		 *
		 * @author	Joseph Skelton
		 * @param	shaderName	Name of the shader.
		 *
		 * @return	The shader.
		 */

		int LoadShader(std::string shaderName);

		/**
		 * @fn	void OpenGLRenderer::BindShader(int id);
		 *
		 * @brief	Bind shader.
		 *
		 * @author	Joseph Skelton
		 * @param	id	The identifier.
		 */

		void BindShader(int id);

		/**
		 * @fn	void OpenGLRenderer::UnbindShader(int id);
		 *
		 * @brief	Unbind shader.
		 *
		 * @author	Joseph Skelton
		 * @param	id	The identifier.
		 */

		void UnbindShader(int id);

		/**
		 * @fn	void OpenGLRenderer::CreateLookAt(float camX, float camY, float camZ, float eyeX,
		 * 		float eyeY, float eyeZ, float upX, float upY, float upZ);
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

		void CreateLookAt(float camX, float camY, float camZ, 
						float eyeX, float eyeY, float eyeZ,
						float upX, float upY, float upZ);

		/**
		 * @fn	void OpenGLRenderer::SetPerspective(float angle, float aspectRatio, float nearClip,
		 * 		float farClip);
		 *
		 * @brief	Sets a perspective.
		 *
		 * @author	Joseph Skelton
		 * @param	angle	   	The angle.
		 * @param	aspectRatio	The aspect ratio.
		 * @param	nearClip   	The near clip.
		 * @param	farClip	   	The far clip.
		 */

		void SetPerspective(float angle, float aspectRatio, float nearClip, float farClip);

		/**
		 * @fn	void OpenGLRenderer::EnableDepthTesting(bool isDepthTested);
		 *
		 * @brief	Enables the depth testing.
		 *
		 * @author	Joseph Skelton
		 * @param	isDepthTested	true if this OpenGLRenderer is depth tested.
		 */

		void EnableDepthTesting(bool isDepthTested);

		/**
		 * @fn	void OpenGLRenderer::ClearScreen();
		 *
		 * @brief	Clears the screen.
		 *
		 * @author	Joseph Skelton
		 */

		void ClearScreen();
		

		/**
		 * \fn	virtual unsigned int OpenGLRenderer::BindTexture2D(imageTypes type, int width, int height,
		 * 		unsigned char *texture);
		 *
		 * \brief	Bind texture 2 d. Transfer texture to the GPU (if id is == 0), if not it binds it.
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

		virtual void BindTexture2D(unsigned int &id, int activeTexture, imageTypes type, int width, int height, unsigned char *texture);

		/**
		 * \fn	virtual unsigned int OpenGLRenderer::BindTexture3D(imageTypes type, int width, int height,
		 * 		int depth, unsigned char *texture);
		 *
		 * \brief	Bind texture 3 d. Transfer texture to the GPU (if id is == 0), if not it binds it.
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

		virtual void BindTexture3D(unsigned int &id, int activeTexture, imageTypes type, int width, int height, int depth, unsigned char *texture);

		/**
		 * \fn	virtual unsigned int OpenGLRenderer::BindTextureCube(imageTypes type, int width,
		 * 		int height, unsigned char *texture);
		 *
		 * \brief	Bind texture cube. Transfer texture to the GPU (if id is == 0), if not it binds it.
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

		virtual void BindTextureCube(unsigned int &id, int activeTexture, imageTypes type, int width, int height, unsigned char *texture);

		/**
		 * \fn	virtual void OpenGLRenderer::UnbindTexture(unsigned int textureID);
		 *
		 * \brief	Unbind texture.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \param	textureID	Identifier for the texture.
		 */

		virtual void ClearTexture(unsigned int &textureID);

		/**
		 * \fn	virtual void OpenGLRenderer::UnbindTexture();
		 *
		 * \brief	Unbind texture.
		 *
		 * \author	Matthew Vlietstra
		 * \date	1/04/2012
		 */

		virtual void UnbindTexture();

		/**
		 * \fn	virtual void OpenGLRenderer::LoadMatrix(const glm::mat4 &mtrx);
		 *
		 * \brief	Loads a matrix.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \param	mtrx	The mtrx.
		 */

		virtual void LoadMatrix(const glm::mat4 &mtrx);

		
		

		/**
		 * \fn	virtual unsigned int OpenGLRenderer::BindVertexBuffer(const void *buffer,
		 * 		unsigned int vertexCount, int strideSize)
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

		virtual unsigned int BindVertexBuffer(const void *buffer, unsigned int vertexCount, int strideSize, streamTypes type );

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

		virtual void UpdateVertexBuffer(unsigned int vboId, int offset, const float *data, unsigned int vertexCount);

		/**
		 * Map buffer range.
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

		virtual float *MapVertexBufferRange(unsigned int vboId, int offset, unsigned int length, bufferAccessTypes access);

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

		virtual unsigned int *MapIndexBufferRange(unsigned int vboId, int offset, unsigned int length, bufferAccessTypes access);

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

		virtual bool UnmapBuffer(int vboId, bufferTypes type);

		/**
		 * \fn	virtual unsigned int OpenGLRenderer::BindIndexBuffer(unsigned int *indexBuffer,
		 * 		unsigned int indiceCount, shapeType shape)
		 *
		 * \brief	Bind index buffer.
		 *
		 * \author	Matthew Vlietstra
		 * \date	1/04/2012
		 *
		 * \param [in,out]	indexBuffer	If non-null, buffer for index data.
		 * \param	indiceCount		   	Number of indices.
		 * \param	shape			   	The shape.
		 *
		 * \return	.
		 */

		virtual unsigned int BindIndexBuffer(unsigned int *indexBuffer, unsigned int indiceCount, shapeType shape, streamTypes type)
		{
			unsigned int vboId = 0;
			glGenBuffers(1, &vboId);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboId);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indiceCount, indexBuffer, GetGLStreamType(type));
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			return  vboId;
		}


		virtual void UpdateIndexBuffer(unsigned int vboId, int offset, const unsigned int *data, unsigned int indiceCount)
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboId);
			glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * offset, sizeof(unsigned int) * indiceCount, data);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

		/**
		 * \fn	virtual void OpenGLRenderer::DeleteBuffer(unsigned int bufferID)
		 *
		 * \brief	Deletes the buffer described by bufferID.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \param	bufferID	Identifier for the buffer.
		 */

		virtual void DeleteBuffer(unsigned int bufferID);
		
		/**
		 * \fn	virtual void OpenGLRenderer::RenderBuffer(Graphics::IndexBuffer *indexBuffer,
		 * 		Graphics::VertexBuffer *vertexBuffer)
		 *
		 * \brief	Renders the buffer.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \param [in,out]	indexBuffer 	If non-null, buffer for index data.
		 * \param [in,out]	vertexBuffer	If non-null, buffer for vertex data.
		 */

		virtual void RenderBuffer(Graphics::IndexBuffer *indexBuffer, Graphics::VertexBuffer *vertexBuffer);
		//virtual void RenderMesh(Mesh *mesh)
		//{
		//
		//}

		/**
		 * \fn	virtual void OpenGLRenderer::RenderMesh(Mesh *mesh);
		 *
		 * \brief	Renders the mesh described by mesh.
		 *
		 * \author	Matthew Vlietstra
		 * \date	1/04/2012
		 *
		 * \param [in,out]	mesh	If non-null, the mesh.
		 */

		virtual void RenderMesh(Mesh *mesh);

		/**
		 * \fn	virtual void OpenGLRenderer::SParameter1i(unsigned int shaderID, const std::string &name,
		 * 		int value)
		 *
		 * \brief	Parameter 1i.
		 *
		 * \author	Matthew Vlietstra
		 * \date	1/04/2012
		 *
		 * \param	shaderID	Identifier for the shader.
		 * \param	name		The name.
		 * \param	value   	The value.
		 */

		virtual void SParameter1i(unsigned int shaderID, const std::string &name, int value);

		/**
		 * \fn	virtual void OpenGLRenderer::SParameter1fv(unsigned int shaderID, const std::string &name,
		 * 		float value)
		 *
		 * \brief	Parameter 1fv.
		 *
		 * \author	Matthew Vlietstra
		 * \date	1/04/2012
		 *
		 * \param	shaderID	Identifier for the shader.
		 * \param	name		The name.
		 * \param	value   	The value.
		 */

		virtual void SParameter1fv(unsigned int shaderID, const std::string &name, float value);

		/**
		 * \fn	virtual void OpenGLRenderer::SParameter4f(unsigned int shaderID, const std::string &name,
		 * 		float v0, float v1, float v2, float v3)
		 *
		 * \brief	Parameter 4f.
		 *
		 * \author	Matthew Vlietstra
		 * \date	31/03/2012
		 *
		 * \param	shaderID	Identifier for the shader.
		 * \param	name		The name.
		 * \param	v0			The v 0.
		 * \param	v1			The first float.
		 * \param	v2			The second float.
		 * \param	v3			The third float.
		 */

		virtual void SParameter4f(unsigned int shaderID, const std::string &name, float v0, float v1, float v2, float v3);

		/**
		 * \fn	virtual void OpenGLRenderer::SParameter3f(unsigned int shaderID, const std::string &name,
		 * 		float v0, float v1, float v2)
		 *
		 * \brief	Parameter 3f.
		 *
		 * \author	Matthew Vlietstra
		 * \date	8/04/2012
		 *
		 * \param	shaderID	Identifier for the shader.
		 * \param	name		The name.
		 * \param	v0			The v 0.
		 * \param	v1			The first float.
		 * \param	v2			The second float.
		 */

		virtual void SParameter3f(unsigned int shaderID, const std::string &name, float v0, float v1, float v2);

		/**
		 * \fn	virtual void OpenGLRenderer::SParameterMatrix4fv(unsigned int shaderID,
		 * 		const std::string &name, const glm::mat4x4 &matrix)
		 *
		 * \brief	Parameter matrix 4fv.
		 *
		 * \author	Matthew Vlietstra
		 * \date	31/03/2012
		 *
		 * \param	shaderID	Identifier for the shader.
		 * \param	name		The name.
		 * \param	matrix  	The matrix.
		 */

		virtual void SParameterMatrix4fv(unsigned int shaderID, const std::string &name, const glm::mat4x4 &matrix);


		/**
		 * \fn	virtual void OpenGLRenderer::RenderText(const std::string &text, const BitmapFont *font,
		 * 		const glm::vec2 &location, const glm::vec3 &colour, float fade);
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

		void SetClearColour(float red, float green, float blue, float alpha);

		/**
		 * \fn	virtual glm::vec2 OpenGLRenderer::GetScreenDimensions();
		 *
		 * \brief	Gets the screen dimensions.
		 *
		 * \author	Matthew Vlietstra
		 * \date	1/04/2012
		 *
		 * \return	The screen dimensions.
		 */

		virtual glm::vec2 GetScreenDimensions();

		/**
		 * \fn	virtual void OpenGLRenderer::RenderText(const std::string &text, const BitmapFont *font,
		 * 		const glm::vec2 &location, const glm::vec3 &colour, float fade);
		 *
		 * \brief	Renders the text.
		 *
		 * \author	Matthew Vlietstra
		 * \date	1/04/2012
		 *
		 * \param	text		The text.
		 * \param	font		The font.
		 * \param	location	The location.
		 * \param	colour  	The colour.
		 * \param	fade		The fade.
		 */

		virtual void RenderText(const std::string &text, const BitmapFont *font, const glm::vec2 &location, const glm::vec3 &colour, float fade);

		/**
		 * \fn	virtual void OpenGLRenderer::PushMatrix()
		 *
		 * \brief	Pushes the matrix.
		 *
		 * \author	Matthew Vlietstra
		 * \date	1/04/2012
		 */

		virtual void PushMatrix();

		/**
		 * \fn	virtual void OpenGLRenderer::PopMatrix();
		 *
		 * \brief	Pops the matrix.
		 *
		 * \author	Matthew Vlietstra
		 * \date	1/04/2012
		 */

		virtual void PopMatrix();

		/**
		 * \fn	virtual void OpenGLRenderer::CullFrontFace();
		 *
		 * \brief	Cull front face.
		 *
		 * \author	Matthew Vlietstra
		 * \date	1/04/2012
		 */

		virtual void CullFrontFace();

		/**
		 * \fn	virtual void OpenGLRenderer::CullBackFace();
		 *
		 * \brief	Cull back face.
		 *
		 * \author	Matthew Vlietstra
		 * \date	1/04/2012
		 */

		virtual void CullBackFace();

		/**
		 * \fn	virtual void OpenGLRenderer::EnableDepthTest(bool enable);
		 *
		 * \brief	Tests enable depth.
		 *
		 * \author	Matthew Vlietstra
		 * \date	1/04/2012
		 *
		 * \param	enable	true to enable, false to disable.
		 */

		virtual void EnableDepthTest(bool enable);

		/**
		 * \fn	virtual void OpenGLRenderer::EnableColourMaterial(bool enable);
		 *
		 * \brief	Enables the colour material.
		 *
		 * \author	Matthew Vlietstra
		 * \date	1/04/2012
		 *
		 * \param	enable	true to enable, false to disable.
		 */

		virtual void EnableColourMaterial(bool enable);

		/**
		 * \fn	virtual void OpenGLRenderer::EnableCullFace(bool enable);
		 *
		 * \brief	Enables the cull face.
		 *
		 * \author	Matthew Vlietstra
		 * \date	1/04/2012
		 *
		 * \param	enable	true to enable, false to disable.
		 */

		virtual void EnableCullFace(bool enable);

		/**
		 * \fn	virtual void OpenGLRenderer::LoadIdentity();
		 *
		 * \brief	Loads the identity.
		 *
		 * \author	Matthew Vlietstra
		 * \date	1/04/2012
		 */

		virtual void LoadIdentity();

		/**
		 * \fn	virtual void OpenGLRenderer::DrawTexture(const Texture2D *texture,
		 * 		const glm::vec2 &location, const Rectangle &rectangle)
		 *
		 * \brief	Draw texture.
		 *
		 * \author	Matthew Vlietstra
		 * \date	25/03/2012
		 *
		 * \param	texture  	The texture.
		 * \param	location 	The location.
		 * \param	rectangle	The rectangle.
		 */

		//virtual void DrawTexture(Texture2D *texture, const glm::vec2 &location, Rectangle &rectangle, float fade);

		virtual void DrawTexture(Texture2D *texture, const glm::vec2 &location, float rotation, const glm::vec2 &scale, Rectangle &rectangle, const glm::vec4 &colour);

		/**
		 * \fn	virtual unsigned int OpenGLRenderer::GetDrawnVertexCount()
		 *
		 * \brief	Gets the drawn vertex count.
		 *
		 * \author	Matthew Vlietstra
		 * \date	6/04/2012
		 *
		 * \return	The drawn vertex count.
		 */

		virtual unsigned int GetDrawnVertexCount();

		/**
		 * \fn	virtual void OpenGLRenderer::WireFrame(bool wireFrame)
		 *
		 * \brief	Wire frame.
		 *
		 * \author	Matthew Vlietstra
		 * \date	8/04/2012
		 *
		 * \param	wireFrame	true to wire frame.
		 */

		virtual void WireFrame(bool wireFrame)
		{
			if (wireFrame)
			{
				glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
			}
			else
			{
				glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
			}
		}


		virtual void ClearColour(float r, float g, float b, float a);


		//void SwapBuffers();

		virtual void SwapBuffers();

		//virtual unsigned int AddModelArray(const GLfloat *vertices, const GLfloat *colorBufferData, const GLfloat *texCoords, unsigned int bufferSize, int isNormalized, int shader)
		//{
		//	return 0;
		//}

//		void DrawModel(int id);
//		unsigned int AddModelArray(const float *vertices, const float *colorBufferData, const float *texCoords, const float *normalMap, 
//			unsigned int bufferSize, int isNormalized, int shader, unsigned int texture);// { return 0; }


		int CreateLight(const glm::vec4 &ambient, const glm::vec4 &diffuse, const glm::vec4 &specular, const glm::vec4 &position);

//		void SetMaterial(float *ambient, float  e, float *specular, float *shininess);
//		void SetMaterialToDefault();
		bool SetLight(int lightIndex, const glm::vec4 &ambient, const glm::vec4 &diffuse, const glm::vec4 &specular, const glm::vec4 &position);

		/**
		 * \fn	virtual void OpenGLRenderer::ClearLights()
		 *
		 * \brief	Clears the lights.
		 *
		 * \author	Matthew Vlietstra
		 * \date	8/04/2012
		 */

		virtual void ClearLights()
		{
			std::vector<aLight*>::iterator it;

			for (it = m_Light.begin(); it !=  m_Light.end(); it++)
			{
				delete *it;
			}

			m_Light.clear();
		}

		/**
		 * \fn	virtual int OpenGLRenderer::GetLightCount()
		 *
		 * \brief	Gets the light count.
		 *
		 * \author	Matthew Vlietstra
		 * \date	8/04/2012
		 *
		 * \return	The light count.
		 */

		virtual int GetLightCount()
		{
			return m_Light.size();
		}

		/**
		 * @fn	SPK::Renderer* OpenGLRenderer::SetupParticleRenderer(unsigned int screenHeight,
		 * 		float size, std::string texture);
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

//		SPK::Renderer* SetupParticleRenderer(unsigned int screenHeight, float size, std::string texture, int shaderID);

		/**
		 * @fn	void OpenGLRenderer::RenderParticles(std::deque<SPK::System*> &activeSystems);
		 *
		 * @brief	Renders the particles described by activeSystems.
		 *
		 * @author	Joseph Skelton
		 * @param [in,out]	activeSystems	[in,out] If non-null, the active systems.
		 */

//		void RenderParticles(std::deque<SPK::System*> &activeSystems, int shaderID, bool drawBB);

		//void BindMaterial(int materialIndex, int shader);
		//void BindLight(int materialIndex, int shader);
//		void SetCurrentShader(int shaderIndex);
		/*
		void SetViewMatrix(glm::mat4 view);
		void SetProjectionMatrix(glm::mat4 projection);
		void SetWorldMatrix(glm::mat4 world);
		void SetMVP(glm::mat4 mvp);
		*/

		/**
		 * @fn	void OpenGLRenderer::SetupFrameBuffer();
		 *
		 * @brief	Sets up the frame buffer.
		 *
		 * @author	Joseph Skelton
		 */

		void SetupFrameBuffer();

		/**
		 * @fn	void OpenGLRenderer::SwitchRenderTarget(bool renderToTexture) private:;
		 *
		 * @brief	Switch render target.
		 *
		 * @author	Joseph Skelton
		 * @param	renderToTexture	true to render to texture, false to render to screen
		 */

		void SwitchRenderTarget(bool renderToTexture);


		/**
		 * \fn	virtual void OpenGLRenderer::DrawPixels(int width, int height, imageTypes type,
		 * 		const unsigned char *buffer)
		 *
		 * \brief	Draw pixels.
		 *
		 * \author	Matthew Vlietstra
		 * \date	13/04/2012
		 *
		 * \param	width 	The width.
		 * \param	height	The height.
		 * \param	type  	The type.
		 * \param	buffer	The buffer.
		 */

		virtual void DrawPixels(int width, int height, imageTypes type, const unsigned char *buffer);


	private:
//		gs_shaderManager *gs_shaderManager;
//		std::vector<Shader*> shaders;
		///< Number of shaders
		int shaderCount;
		///< Number of models
		int modelCount;
		///< The projection matrix
		glm::mat4 projectionMatrix; 
		///< The model matrix
		glm::mat4 modelMatrix;  
		///< The view matrix
		glm::mat4 viewMatrix;
		///< The model view projection
		glm::mat4 modelViewProjection;  
		///< Number of lights
		int lightCount;
		///< The current shader
		int currentShader;  
		///< Number of vertices
		unsigned int m_vertexCount; 
		///< The alpha sort
		float m_alphaSort;  
		///< The framebuffer
		GLuint frameBuffer;  
		///< The depthbuffer
		GLuint depthBuffer;   
		///< The framebuffer texture
		GLuint frameBufferTexture;	
		//glm::mat4 *currentMatrix;

		/**
		 * @typedef	struct m_bufferCheckStructure
		 *
		 * @brief	Defines an alias representing the buffer check structure.
		 */

		typedef struct m_bufferCheckStructure
		{
			bool hasUV;
			bool hasColour;
			bool hasNormal;
		}m_bufferCheck;

		/**
		 * @typedef	struct m_ModelStructure
		 *
		 * @brief	Defines an alias representing the model structure. was used in the old draw array functions
		 */

		typedef struct m_ModelStructure
		{
			int shader;
			int vertexBufferSize;
			int isNormalized;
			unsigned int textureID;

			m_bufferCheck bufferCheck;

			GLuint vertexBuffer;
			GLuint colorBuffer;
			GLuint uvBuffer;
			GLuint normalBuffer;

		} m_Model;

		std::vector<m_Model*> models;   ///< The models. Used in old draw array function

		/**
		 * @typedef	struct m_LightStructure
		 *
		 * @brief	Defines an alias representing the light structure.
		 */

		typedef struct m_LightStructure
		{
			glm::vec4 ambient;  
			glm::vec4 diffuse;  
			glm::vec4 specular;
			glm::vec4 position;
		} aLight;
		std::vector<aLight*> m_Light;   ///< The light

		/*
		typedef struct m_MaterialStructure
		{
			GLfloat *m_fAmbient;
			GLfloat *m_fDiffuse;
			GLfloat *m_fSpecular;
			GLfloat *m_fShininess;
		} aMaterial;
		*/
		//std::vector<aMaterial*> m_Material;

		int GetGLTextureType(imageTypes t)
		{
			int size = 0;
			return GetGLTextureType(t, size);
		}

		/**
		 * \fn	int OpenGLRenderer::GetGLTextureType(imageTypes t, int &size)
		 *
		 * \brief	Gets a gl texture type.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \param	t				The t.
		 * \param [in,out]	size	The size.
		 *
		 * \return	The gl texture type.
		 */

		int GetGLTextureType(imageTypes t, int &size);

		/**
		 * \fn	int OpenGLRenderer::GetGLMatrixType(MATRIX type)
		 *
		 * \brief	Gets a gl matrix type.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \param	type	The type.
		 *
		 * \return	The gl matrix type.
		 */

		int GetGLMatrixType(MATRIX type);

		/**
		 * Gets a gl stream type.
		 *
		 * @author	Matthew Vlietstra
		 * @date	9/05/2012
		 *
		 * @param	type	The type.
		 *
		 * @return	The gl stream type.
		 */

		int GetGLStreamType(streamTypes type);

		/**
		 * \fn	unsigned int OpenGLRenderer::GetGLShape( shapeType shape );
		 *
		 * \brief	Gets a gl shape.
		 *
		 * \author	Matthew Vlietstra
		 * \date	24/03/2012
		 *
		 * \param	shape	The shape.
		 *
		 * \return	The gl shape.
		 */

		unsigned int GetGLShape( shapeType shape );

		/**
		 * Gets a gl buffer access type.
		 *
		 * @author	Matthew Vlietstra
		 * @date	13/05/2012
		 *
		 * @param	type	The type.
		 *
		 * @return	The gl buffer access type.
		 */

		unsigned int GetGLBufferAccessType( bufferAccessTypes type );

		/**
		 * Gets a gl buffer type.
		 *
		 * @author	Matthew Vlietstra
		 * @date	13/05/2012
		 *
		 * @param	type	The type.
		 *
		 * @return	The gl buffer type.
		 */

		unsigned int GetGLBufferType( bufferTypes type );

		void UniformMatrices(int shaderID);

		/**
		 * @fn	void OpenGLRenderer::DrawParticleBB(SPK::Group *group);
		 *
		 * @brief	Draw particle bb.
		 *
		 * @author	Joseph Skelton
		 * @param [in,out]	group	If non-null, the group.
		 */

		//void DrawParticleBB(SPK::Group *group);

		/**
		 * @fn	void OpenGLRenderer::SetupDepthBuffer(int width, int height);
		 *
		 * @brief	Sets up the depth buffer.
		 *
		 * @author	Joseph Skelton
		 * @param	width 	The width.
		 * @param	height	The height.
		 */

		void SetupDepthBuffer(int width, int height);

		/**
		 * @fn	void OpenGLRenderer::SetuptFramBufferTexture(int width, int height);
		 *
		 * @brief	Setupt fram buffer texture.
		 *
		 * @author	Joseph Skelton
		 * @param	width 	The width.
		 * @param	height	The height.
		 */

		void SetuptFramBufferTexture(int width, int height);

		/**
		 * @fn	void OpenGLRenderer::RenderTargetTexture();
		 *
		 * @brief	Renders the target texture.
		 *
		 * @author	Joseph Skelton
		 */

		void RenderTargetTexture();

		/**
		 * @fn	void OpenGLRenderer::RenderToScreen();
		 *
		 * @brief	Renders to screen.
		 *
		 * @author	Joseph Skelton
		 */

		void RenderToScreen();
	};  

}




//enum {X, Y, Z, Alpha};

#endif