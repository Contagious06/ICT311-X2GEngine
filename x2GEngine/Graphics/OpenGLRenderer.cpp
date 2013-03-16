#include "OpenGLRenderer.h"
#include "CameraManagerSingleton.h"

namespace Graphics
{

	OpenGLRenderer::OpenGLRenderer()
	{
		shaderCount = 0;
		modelCount = 0;
		m_alphaSort = 0.0f;
		m_vertexCount = 0;

		frameBufferTexture = 0;
		frameBuffer = 0;
		depthBuffer = 0;
		
	}



	OpenGLRenderer::~OpenGLRenderer()
	{
		delete &modelMatrix;
		delete &projectionMatrix;
		delete &viewMatrix;
	}


	void OpenGLRenderer::Rotate(float angle, float x, float y, float z)
	{
		//currentMatrix = glm::rotate(currentMatrix, angle, glm::vec3(x, y, z));
		modelMatrix = glm::rotate(modelMatrix, angle, glm::vec3(x, y, z));
	}

	void OpenGLRenderer::Translate(float x, float y, float z)
	{
		//currentMatrix = glm::translate(currentMatrix, glm::vec3(x, y, z));
		modelMatrix = glm::translate(modelMatrix, glm::vec3(x, y, z));
	}

	void OpenGLRenderer::Scale(float x, float y, float z)
	{
		//currentMatrix = glm::scale(&currentMatrix, glm::vec3(x, y, z));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(x, y, z));
	}

	void OpenGLRenderer::SetIdentity()
	{
		//currentMatrix = &glm::mat4(1.0f);
		modelMatrix = glm::mat4(1.0f);
	}

	int OpenGLRenderer::LoadShader(std::string shaderName)
	{
		/*
		shaders.push_back( new Shader(vertex.c_str(), pixel.c_str() ) );
		shaderCount++;
	
		*/
		return( gs_shaderManager->AddEffect(shaderName) );
	}

	void OpenGLRenderer::BindShader(int id)
	{
		//shaders[id]->bind();
		gs_shaderManager->Bind(id);
	}

	void OpenGLRenderer::UnbindShader(int id)
	{
		//shaders[id]->unbind(); 
		gs_shaderManager->UnBind(id);

	}

	void OpenGLRenderer::CreateLookAt(float camX, float camY, float camZ, 
									float eyeX, float eyeY, float eyeZ,
									float upX, float upY, float upZ)
	{
		viewMatrix = glm::lookAt(glm::vec3(camX, camY, camZ),
								glm::vec3(eyeX, eyeY, eyeZ),
								glm::vec3(upX, upY, upZ));
	}

	void OpenGLRenderer::SetPerspective(float angle, float aspectRatio, float nearClip, float farClip)
	{
		projectionMatrix = glm::perspective(angle, aspectRatio, nearClip, farClip);
	}

	void OpenGLRenderer::EnableDepthTesting(bool isDepthTested)
	{
		if(isDepthTested)
		{
			glEnable(GL_DEPTH_TEST);
			//glDepthFunc(GL_LESS);
		}
		else
			glDisable(GL_DEPTH_TEST);
	}

	void OpenGLRenderer::ClearScreen()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		m_alphaSort = 0.0f; //Reset the 2D sorting value.
		m_vertexCount = 0;
	}

	void OpenGLRenderer::BindTextureCube(unsigned int &id, int activeTexture, imageTypes type, int width, int height, unsigned char *texture )
	{
		glActiveTexture(GL_TEXTURE0+activeTexture);
		if (id == 0)
		{
			glGenTextures(1, &id);
			glBindTexture(GL_TEXTURE_CUBE_MAP, id);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR); 

			//int type = 0;
			int size = 0;

			int tp = GetGLTextureType(type, size);

			for (int i = 0; i < 6; i++)
			{
				glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X+i, 0, GL_RGB8, width, height, 0, tp, GL_UNSIGNED_BYTE, texture + (width * height * size * i));
			}
		}

		
		glEnable(GL_TEXTURE_CUBE_MAP);
		glBindTexture(GL_TEXTURE_CUBE_MAP, id);
	}

	void OpenGLRenderer::ClearTexture( unsigned int &textureID )
	{
		if (textureID != 0)
		{
			glDeleteTextures(1, &textureID);
		}
	}

	void OpenGLRenderer::BindTexture3D(unsigned int &id, int activeTexture, imageTypes type, int width, int height, int depth, unsigned char *texture )
	{
		glActiveTexture(GL_TEXTURE0+activeTexture);
		if (id == 0)
		{
			
			//glEnable(GL_DEPTH_TEST);
			glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 
			glClearColor(1.0, 1.0, 1.0, 1.0);
			glColor4d(0.0, 0.0, 0.0, 1.0);
			glPointSize(3.0);

			//unsigned int textureID;
			glGenTextures(1, &id);	

			glBindTexture(GL_TEXTURE_3D, id);	

			glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

			glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_REPEAT);

			glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_REPEAT);

			glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_REPEAT);

			glTexImage3D(GL_TEXTURE_3D, 0, GL_RGB8, width,  height,  depth, 0, GetGLTextureType(type), GL_UNSIGNED_BYTE, texture);
		}

		
		glEnable(GL_TEXTURE_3D);
		glBindTexture(GL_TEXTURE_3D, id);

		//return textureID;
	}

	void OpenGLRenderer::BindTexture2D(unsigned int &id, int activeTexture, imageTypes type, int width, int height, unsigned char *texture)
	{
		glActiveTexture(GL_TEXTURE0+activeTexture);
		if (id == 0)
		{
			glGenTextures(1, &id);
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
			glBindTexture(GL_TEXTURE_2D, id);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );

			int t = GetGLTextureType(type);

			gluBuild2DMipmaps(GL_TEXTURE_2D, t, width, height, t, GL_UNSIGNED_BYTE, texture);
		}

		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, id);
	}

	void OpenGLRenderer::LoadMatrix( const glm::mat4 &mtrx )
	{
		glLoadMatrixf(glm::value_ptr(mtrx));
	}

	#define BUFFER_OFFSET(i) (reinterpret_cast<void*>(i))
	void OpenGLRenderer::RenderBuffer( Graphics::IndexBuffer *indexBuffer, Graphics::VertexBuffer *vertexBuffer )
	{
		int strideSize = vertexBuffer->GetStrideSize();

		int vertex = vertexBuffer->GetVertex();
		int colour = vertexBuffer->GetColour();
		int texCoord = vertexBuffer->GetTexCoord();
		int normal = vertexBuffer->GetNormal();

		unsigned int vbo = vertexBuffer->GetVBO();

		glEnableClientState(GL_INDEX_ARRAY);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		if (vertex > 0)
		{
			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(vertex, GL_FLOAT, strideSize, 0);
		}

		if (colour > 0)
		{
			glEnableClientState(GL_COLOR_ARRAY);
			glColorPointer(colour, GL_FLOAT, strideSize, BUFFER_OFFSET(vertex * sizeof(float))); // need to test the offset.
		}

		if (texCoord > 0)
		{
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glTexCoordPointer(texCoord, GL_FLOAT, strideSize, BUFFER_OFFSET((vertex + colour) * sizeof(float)));
		}

		if (normal > 0)
		{
			glEnableClientState(GL_NORMAL_ARRAY);
			glNormalPointer(GL_FLOAT, strideSize, BUFFER_OFFSET((vertex + colour + texCoord) * sizeof(float)));
		}
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer->GetVBO());
		glDrawElements(GetGLShape(indexBuffer->GetShape()), indexBuffer->GetIndiceCount(), GL_UNSIGNED_INT, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		m_vertexCount+= indexBuffer->GetIndiceCount();

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_INDEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
	}

	void OpenGLRenderer::DeleteBuffer( unsigned int bufferID )
	{
		glDeleteBuffers(1, &bufferID);
	}

	unsigned int OpenGLRenderer::BindVertexBuffer( const void *buffer, unsigned int vertexCount, int strideSize, streamTypes type )
	{
		//Create VBO
		unsigned int bufferID = 0;
		glGenBuffers(1, &bufferID);
		glBindBuffer(GL_ARRAY_BUFFER, bufferID);
		//glBufferData(GL_ARRAY_BUFFER, vertexCount * strideSize, buffer, GL_STATIC_DRAW); 
		glBufferData(GL_ARRAY_BUFFER, vertexCount * strideSize, buffer, this->GetGLStreamType(type)); 
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		return bufferID;
	}

	void OpenGLRenderer::UpdateVertexBuffer( unsigned int vboId, int offset, const float *data, unsigned int vertexCount )
	{
		glBindBuffer(GL_ARRAY_BUFFER, vboId);
		glBufferSubData(GL_ARRAY_BUFFER, sizeof(float) * offset, sizeof(float) * vertexCount, data);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	float *OpenGLRenderer::MapVertexBufferRange(unsigned int vboId, int offset, unsigned int length, bufferAccessTypes access)
	{
		glBindBuffer(GL_ARRAY_BUFFER, vboId);
		float *bufferP = (float *)glMapBufferRange(GL_ARRAY_BUFFER, sizeof(float) * offset, sizeof(float) * length, GetGLBufferAccessType(access));
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		return bufferP;
	}

	unsigned int *OpenGLRenderer::MapIndexBufferRange(unsigned int vboId, int offset, unsigned int length, bufferAccessTypes access)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboId);
		unsigned int *bufferP = (unsigned int *)glMapBufferRange(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * offset, sizeof(unsigned int) * length, GetGLBufferAccessType(access));
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		return bufferP;
	}

	bool OpenGLRenderer::UnmapBuffer( int vboId, bufferTypes type )
	{
		glBindBuffer(GetGLBufferType(type), vboId);

		bool b = (bool)glUnmapBuffer(GetGLBufferType(type));

		glBindBuffer(GetGLBufferType(type), 0);
		return b;
	}

	int OpenGLRenderer::GetGLTextureType( imageTypes t, int &size )
	{
		int type = 0;
		switch(t)
		{
		case X2_COLOUR_INDEX:
			type = GL_COLOR_INDEX;
			size = 1;
			break;

		case X2_RED:
			type = GL_RED;
			size = 1;
			break;

		case X2_GREEN:
			type = GL_GREEN;
			size = 1;
			break;

		case X2_BLUE:
			type = GL_BLUE;
			size = 1;
			break;

		case X2_ALPHA:
			type = GL_ALPHA;
			size = 1;
			break;

		case X2_INTENSITY:
			type = GL_RGB;
			size = 1;
			break;

		case X2_RGB:
			type = GL_RGB;
			size = 3;
			break;

		case X2_BGR:
			type = GL_BGR;
			size = 3;
			break;

		case X2_RGBA:
			type = GL_RGBA;
			size = 4;
			break;

		case X2_BGRA:
			type = GL_BGRA;
			size = 4;
			break;

		case X2_LUMINANCE:
			type = GL_LUMINANCE;
			size = 1;
			break;

		case X2_LUMINANCE_ALPHA:
			type = GL_LUMINANCE_ALPHA;
			size = 1;
			break;

		default:
			size = 3;
			type = GL_RGB;
		}
		return type;
	}

	int OpenGLRenderer::GetGLMatrixType( MATRIX type )
	{
		switch(type)
		{
		case MODELVIEW:
			return GL_MODELVIEW;
			break;
		case PROJECTION:
			return GL_PROJECTION;
			break;

		case VIEW:

			break;
		case TEXTURE:
			return GL_TEXTURE;
			break;
		case  GL_COLOR:
			return GL_COLOR;
			break;
		}
		return 0;
	}

	unsigned int OpenGLRenderer::GetGLShape( shapeType shape )
	{
		if (shape == X2_TRIANGLES) return GL_TRIANGLES;
		if (shape == X2_TRIANGLESTRIPS) return GL_TRIANGLE_STRIP;
		if (shape == X2_QUADS) return GL_QUADS;
		if (shape == X2_QUADSTRIPTS) return GL_QUAD_STRIP;
		return 0;
	}

	//void OpenGLRenderer::DrawTexture( Texture2D *texture, const glm::vec2 &location, Rectangle &rectangle, float fade )
	void OpenGLRenderer::DrawTexture(Texture2D *texture, const glm::vec2 &location, float rotation, const glm::vec2 &scale, Rectangle &rectangle, const glm::vec4 &colour)
	{
		float fade = colour.w;

		int windowWidth = 0;
		int windowHeight = 0;

		glfwGetWindowSize(&windowWidth, &windowHeight); //Should actually use the device...

		int tWidth = texture->GetWidth();
		int tHeight = texture->GetHeight();



		glMatrixMode(GL_PROJECTION);

		glPushMatrix();
		glLoadIdentity();
		glOrtho(0, windowWidth, 0, windowHeight, -10000, 10000);


		glMatrixMode(GL_MODELVIEW);

		glPushMatrix();

		glEnable(GL_TEXTURE_2D);
		texture->Bind();

		m_alphaSort += 0.001f;
		glEnable(GL_BLEND);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE_ARB);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		glColor4f(1.0, 1.0, 1.0, fade);

		glPushMatrix();
		glLoadIdentity();

		
		glTranslatef(location.x+(float)rectangle.GetDimensions().x/2, location.y+(float)rectangle.GetDimensions().y/2, 0.0f);
		glScalef(scale.x, scale.y, 1);
		glRotatef(rotation, 0, 0, 1);


		glBegin(GL_QUADS);
		glTexCoord2f((float)rectangle.GetLocation().x/tWidth, (float)rectangle.GetLocation().y/tHeight);
		glVertex3f(-(float)rectangle.GetDimensions().x/2, -(float)rectangle.GetDimensions().y/2, m_alphaSort);

		glTexCoord2f((float)rectangle.GetMax().x/tWidth, (float)rectangle.GetLocation().y/tHeight);
		glVertex3f((float)rectangle.GetDimensions().x/2, -(float)rectangle.GetDimensions().y/2, m_alphaSort);

		glTexCoord2f((float)rectangle.GetMax().x/tWidth, (float)rectangle.GetMax().y/tHeight);
		glVertex3f((float)rectangle.GetDimensions().x/2, (float)rectangle.GetDimensions().y/2, m_alphaSort);

		glTexCoord2f((float)rectangle.GetLocation().x/tWidth, (float)rectangle.GetMax().y/tHeight);
		glVertex3f(-(float)rectangle.GetDimensions().x/2, (float)rectangle.GetDimensions().y/2, m_alphaSort);
		glEnd();


		glPopMatrix();
		glDisable(GL_TEXTURE_2D);

		glPopMatrix();

		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		glDisable(GL_BLEND);
		glColor4f(1.0, 1.0, 1.0, 1.0); //Reset the colour
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	}

	void OpenGLRenderer::ClearColour( float r, float g, float b, float a )
	{
		glClearColor(r, g, b, a);
	}

	void OpenGLRenderer::RenderMesh( Mesh *mesh )
	{
		Mesh::mp *meshParts = mesh->GetMeshParts();
		Mesh::m *material = mesh->GetMaterial();
		VertexBuffer *vertexBuffer = mesh->GetVertexBuffer();

		

		int i = 0;
		for (Mesh::mpIt it = meshParts->begin(); it != meshParts->end(); it++)
		{
			unsigned int materialID = (*it)->GetMaterialID();
			Material *mat = nullptr;
			if (material != nullptr)
			{
				if (materialID >= 0 && materialID < material->size())
				{
					//glColor3f(1,1,1);
					mat = (*material)[materialID];

					//if (mat->effectID >= 0)
					//{
					//	this->BindShader(mat->effectID);
					//	this->SParameter1fv(mat->effectID, "time", (float)glfwGetTime());

					//	float *para = nullptr;
					//	
					//	para = mat->ambient;
					//	this->SParameter4f(mat->effectID, "ambientMat", para[0], para[1], para[2], para[3]);

					//	para = mat->diffuse;
					//	this->SParameter4f(mat->effectID, "ambientMat", para[0], para[1], para[2], para[3]);

					//	para = mat->specular;
					//	this->SParameter4f(mat->effectID, "ambientMat", para[0], para[1], para[2], para[3]);
					//} 
					// 
				
					if (mat->cullFace) //Need to make more efficient i.e. keep track of culling.
					{
						glEnable(GL_CULL_FACE);
					}
					else
					{
						glDisable(GL_CULL_FACE);
					}

					if (mat->effect != "" && mat->effectID < 0)
					{
						mat->effectID = this->LoadShader(mat->effect);

						if (mat->effectID >= 0)
						{
							this->BindShader(mat->effectID);
							this->SParameter1i(mat->effectID, "ambient", 0);
							this->SParameter1i(mat->effectID, "diffuse", 1);
							this->SParameter1i(mat->effectID, "specular", 2);
							this->SParameter1i(mat->effectID, "bump", 3);
							this->SParameter1i(mat->effectID, "mapReflect", 4);

							this->UnbindShader(mat->effectID);
						}
					}

					if (mat->effectID >= 0)
					{
						this->BindShader(mat->effectID);
						float *para = nullptr;

						para = mat->ambient;
						this->SParameter4f(mat->effectID, "ambientMat", para[0], para[1], para[2], para[3]);

						para = mat->diffuse;
						this->SParameter4f(mat->effectID, "diffuseMat", para[0], para[1], para[2], para[3]);

						para = mat->specular;
						this->SParameter4f(mat->effectID, "specularMat", para[0], para[1], para[2], para[3]);

						this->SParameter1fv(mat->effectID, "time", (float)glfwGetTime());

						this->SParameter1fv(mat->effectID, "bumpAmount", mat->m_bumpAmount);
						//gs_cameraManager->GetProjection();
						this->SParameterMatrix4fv(mat->effectID, "projectionMatrix", *(gs_cameraManager->GetProjection()));

						this->SParameterMatrix4fv(mat->effectID, "viewMatrix", *(gs_cameraManager->GetView())); //Change to view Matrix ASAP

						this->SParameterMatrix4fv(mat->effectID, "modelMatrix", (*it)->GetTransformation());

						glm::vec3 eyeLoc = gs_cameraManager->GetCurrentCamera()->GetLocation();

						this->SParameter3f(mat->effectID, "eyePosition", eyeLoc.x, eyeLoc.y, eyeLoc.z);


						this->SParameter1fv(mat->effectID, "specularWeight", mat->specularWeight);
						//mat->specularWeight


					}

					if (m_Light.size() > (unsigned int)0)
					{
						float *parameter = nullptr;
						parameter = glm::value_ptr(m_Light[0]->ambient);
						this->SParameter4f(mat->effectID, "lAmbient", parameter[0], parameter[1], parameter[2], parameter[3]);
						parameter = glm::value_ptr(m_Light[0]->diffuse);
						this->SParameter4f(mat->effectID, "lDiffuse", parameter[0], parameter[1], parameter[2], parameter[3]);
						parameter = glm::value_ptr(m_Light[0]->specular);
						this->SParameter4f(mat->effectID, "lSpecular", parameter[0], parameter[1], parameter[2], parameter[3]);
						parameter = glm::value_ptr(m_Light[0]->position);
						this->SParameter4f(mat->effectID, "lPosition", parameter[0], parameter[1], parameter[2], parameter[3]);
					}



					//glEnable(GL_LIGHTING);
					//glEnable(GL_COLOR_MATERIAL);
					glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat->ambient);
					glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat->diffuse);
					glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat->specular);

					if ((*material)[materialID]->mapReflect != nullptr)
					{
						(*material)[materialID]->mapReflect->Bind(4);
					}

					if ((*material)[materialID]->bumpMap != nullptr)
					{
						(*material)[materialID]->bumpMap->Bind(3);
					}

					if ((*material)[materialID]->mapSpecular != nullptr)
					{
						(*material)[materialID]->mapSpecular->Bind(2);
					}

					if ((*material)[materialID]->mapDiffuse != nullptr)
					{
						(*material)[materialID]->mapDiffuse->Bind(1);
					}

					if ((*material)[materialID]->mapAmbient != nullptr)
					{
						(*material)[materialID]->mapAmbient->Bind(0);
					}

				}
			}
			vertexBuffer->RenderBuffer((*it)->GetIndexBuffer());
			//glDisable(GL_TEXTURE_2D);
			

			if (mat != nullptr)
			{
				if (mat->effectID >= 0)
				{
					this->UnbindShader(mat->effectID);
				}
			}

			i++;
		}
		UnbindTexture();
	}

	void OpenGLRenderer::RenderText( const std::string &text, const BitmapFont *font, const glm::vec2 &location, const glm::vec3 &colour, float fade )
	{
		if (!font)
		{
			return;
		}

		int windowWidth = 0;
		int windowHeight = 0;

		glfwGetWindowSize(&windowWidth, &windowHeight); //Should actually use the device...

		BitmapCharacterSet *charSet = font->GetBitmapCharacterSet();

		glPushMatrix();
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();

		glOrtho(0, (double)windowWidth, 0, (double)windowHeight, -10000.0, 10000.0);

		glMatrixMode(GL_MODELVIEW);

		glPushMatrix();
		glLoadIdentity();
		glEnable (GL_ALPHA_TEST);
		glEnable(GL_BLEND);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE_ARB);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glColor4f(colour.x, colour.y, colour.z, fade);
		glTranslatef(location.x, location.y, 0);

		m_alphaSort += 0.001f;
		glEnable(GL_TEXTURE_2D);
		for (unsigned int i = 0; i < text.length(); i++)
		{
			m_alphaSort += 0.001f;

			BitmapCharacter *character = charSet->GetCharacter(text.c_str()[i]);

			if(character != nullptr)
			{
				int pageNumber = character->GetPage();

				float tWidth = (float)font->GetFontTexture(pageNumber)->GetWidth();
				float tHeight = (float)font->GetFontTexture(pageNumber)->GetHeight();

				float cX = (float)character->GetX();
				float cY = (float)character->GetY();

				float cWidth = (float)character->GetWidth();
				float cHeight = (float)character->GetHeight();

				float xOffset = (float)character->GetXOffset();
				float yOffset = (float)character->GetYOffset();


			
				font->GetFontTexture(pageNumber)->Bind(0);


				//glScalef(10, 10, 10);
				glTranslatef(xOffset, -(yOffset + cHeight), 0);
				glBegin(GL_QUADS);
				//glTexCoord2d(0.0, 0.0);
				glTexCoord2d((cX / tWidth ), -((cY+cHeight)/tHeight)); //Bottom Left
				glVertex3f(0.0, 0.0, m_alphaSort);

				//glTexCoord2d(1.0,0.0);
				glTexCoord2d(((cX+cWidth)/tWidth), -((cY+cHeight)/tHeight)); //Bottom Right
				glVertex3f((float)character->GetWidth(), 0.0, m_alphaSort);

				//glTexCoord2d(1.0,1.0);
				glTexCoord2d(((cX+cWidth)/tWidth), -((cY)/tHeight)); //Top Right
				glVertex3f((float)character->GetWidth(), (float)character->GetHeight(), m_alphaSort);

				//glTexCoord2d(0.0,1.0);
				glTexCoord2d((cX/tWidth),  -(cY/tHeight)); //Top Left
				glVertex3f(0.0, (float)character->GetHeight(), m_alphaSort);
				glEnd();
				glTranslatef(-xOffset, (yOffset + cHeight), 0); //Reset Translate offset

				glTranslatef(cWidth, 0.0, 0.0);
			}
		}
		glPopMatrix();

		UnbindTexture();
		glDisable(GL_TEXTURE_2D);
		glColor4f(1.0, 1.0, 1.0, 1.0);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		glDisable(GL_BLEND);
		glDisable (GL_ALPHA_TEST);
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();
	}

	void OpenGLRenderer::SetClearColour(float red, float green, float blue, float alpha)
	{
		glClearColor(red, green, blue, alpha);
	}

	void OpenGLRenderer::SwapBuffers()
	{
		glfwSwapBuffers();
	}

	int OpenGLRenderer::CreateLight(const glm::vec4 &ambient, const glm::vec4 &diffuse, const glm::vec4 &specular, const glm::vec4 &position)
	{
		if (lightCount >= 7)
			return -1;

		//SetLight(lightCount, ambient, diffuse, specular, position);
		lightCount++;
		
		aLight *tempLight = new aLight;


		tempLight->ambient = ambient;
		tempLight->diffuse = diffuse;
		tempLight->specular = specular;
		tempLight->position = position;

		m_Light.push_back(tempLight);
		
		

		return ( lightCount -1 );
	}

	bool OpenGLRenderer::SetLight(int lightIndex, const glm::vec4 &ambient, const glm::vec4 &diffuse, const glm::vec4 &specular, const glm::vec4 &position)
	{
		bool lightSet = false;
		
			if (m_Light.size() > (unsigned int)lightIndex)
			{
				lightSet = true;

				m_Light[lightIndex]->ambient = ambient;
				m_Light[lightIndex]->diffuse = diffuse;
				m_Light[lightIndex]->specular = specular;
				m_Light[lightIndex]->position = position;

				//m_Light[lightIndex]->m_fAmbient = ambient;
				//m_Light[lightIndex]->m_fDiffuse = diffuse;
				//m_Light[lightIndex]->m_fSpecular = specular;
				//m_Light[lightIndex]->m_fPosition = position;
			}

			

			return (lightSet);
	}

	void OpenGLRenderer::UnbindTexture()
	{
		int maxTextures = 0;
		glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &maxTextures);

		//Need to optimize this, maybe keep track of the bound textures or something.
		for (int i = 0; i < 6; i++)
		{
			glActiveTexture(GL_TEXTURE0 + i);
			glBindTexture(GL_TEXTURE_2D, 0);
			glBindTexture(GL_TEXTURE_3D, 0);
			glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
			glDisable(GL_TEXTURE_2D);
			glDisable(GL_TEXTURE_3D);
			glDisable(GL_TEXTURE_CUBE_MAP);

		}

		//glDisable(GL_TEXTURE_2D);
		//glDisable(GL_TEXTURE_3D);
		//glDisable(GL_TEXTURE_CUBE_MAP);

		//glActiveTexture(GL_TEXTURE0); //Reset
	}

	void OpenGLRenderer::SParameter1i( unsigned int shaderID, const std::string &name, int value )
	{
		int uloc = glGetUniformLocation(gs_shaderManager->GetShaderID(shaderID), name.c_str());
		//std::cout << uloc << " " << value << " " << name << std::endl;

		glUniform1i(uloc, value);
	}

	void OpenGLRenderer::SParameter1fv( unsigned int shaderID, const std::string &name, float value )
	{
		int uloc = glGetUniformLocation(gs_shaderManager->GetShaderID(shaderID), name.c_str());
		//std::cout << uloc << " " << value << " " << name << std::endl;
		if (uloc != -1)
		{
			//std::cout << value << " " << name << std::endl;
			glUniform1f(uloc, value);
		}
	}

	void OpenGLRenderer::SParameter4f( unsigned int shaderID, const std::string &name, float v0, float v1, float v2, float v3 )
	{
		int uloc = glGetUniformLocation(gs_shaderManager->GetShaderID(shaderID), name.c_str());
		//std::cout << uloc << " " << value << " " << name << std::endl;
		if (uloc != -1)
		{
			//std::cout << value << " " << name << std::endl;
			//glUniform1f(uloc, value);
			glUniform4f(uloc, v0, v1, v2, v3);
		}
	}

	void OpenGLRenderer::SParameterMatrix4fv( unsigned int shaderID, const std::string &name, const glm::mat4x4 &matrix )
	{
		int uloc = glGetUniformLocation(gs_shaderManager->GetShaderID(shaderID), name.c_str());
		//std::cout << uloc << " " << value << " " << name << std::endl;
		if (uloc != -1)
		{
			glUniformMatrix4fv(uloc, 1, GL_FALSE, glm::value_ptr(matrix));
		}
	}

	glm::vec2 OpenGLRenderer::GetScreenDimensions()
	{
		int windowWidth = 0;
		int windowHeight = 0;

		glfwGetWindowSize(&windowWidth, &windowHeight);

		return glm::vec2(windowWidth, windowHeight);
	}

	void OpenGLRenderer::PushMatrix()
	{
		glPushMatrix();
	}

	void OpenGLRenderer::PopMatrix()
	{
		glPopMatrix();
	}

	void OpenGLRenderer::CullFrontFace()
	{
		glCullFace(GL_FRONT);
	}

	void OpenGLRenderer::CullBackFace()
	{
		glCullFace(GL_BACK);
	}

	void OpenGLRenderer::EnableDepthTest( bool enable )
	{
		if (enable)
		{
			glEnable(GL_DEPTH_TEST);
		}
		else
		{
			glDisable(GL_DEPTH_TEST);
		}
	}

	void OpenGLRenderer::EnableColourMaterial( bool enable )
	{
		if (enable)
		{
			glEnable(GL_COLOR_MATERIAL);
		}
		else
		{
			glDisable(GL_COLOR_MATERIAL);
		}
	}

	void OpenGLRenderer::EnableCullFace( bool enable )
	{
		if (enable)
		{
			glEnable(GL_CULL_FACE);
		}
		else
		{
			glDisable(GL_CULL_FACE);
		}
	}

	void OpenGLRenderer::LoadIdentity()
	{
		glLoadIdentity();
	}

	unsigned int OpenGLRenderer::GetDrawnVertexCount()
	{
		return m_vertexCount;
	}

	void OpenGLRenderer::SParameter3f( unsigned int shaderID, const std::string &name, float v0, float v1, float v2 )
	{
		int uloc = glGetUniformLocation(gs_shaderManager->GetShaderID(shaderID), name.c_str());
		if (uloc != -1)
		{
			glUniform3f(uloc, v0, v1, v2);
		}
	}

	void OpenGLRenderer::SetupDepthBuffer(int width, int height)
	{
		glGenRenderbuffersEXT(1, &depthBuffer); 
		glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, depthBuffer);

		glRenderbufferStorageEXT(GL_RENDERBUFFER_EXT, GL_DEPTH_COMPONENT, width, height);
		//glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthBuffer);
		glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, 0);
	}	

	void OpenGLRenderer::SetuptFramBufferTexture(int width, int height)
	{

		glGenTextures(1, &frameBufferTexture);
		glBindTexture(GL_TEXTURE_2D, frameBufferTexture);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void OpenGLRenderer::SetupFrameBuffer()
	{
		int width = 0;
		int height = 0;

		glfwGetWindowSize(&width, &height);
	
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);

		std::cout << width << "   " << height << std::endl;

		SetupDepthBuffer(width, height);
		SetuptFramBufferTexture(width, height);

		glGenFramebuffersEXT(1, &frameBuffer);
		glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, frameBuffer);

		glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, frameBufferTexture, 0);
		glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER, depthBuffer);

		GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER_EXT);

		if(status != GL_FRAMEBUFFER_COMPLETE_EXT)
		{
			std::cout << "Problem creating frame buffer" << std::endl;
			exit(0);
		}

		glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
		
	}


	void OpenGLRenderer::SwitchRenderTarget(bool renderToTexture)
	{
		if (renderToTexture)
		{
			RenderTargetTexture();
			//std::cout << "Render to buffer" << std::cout;
		}
		else
		{
			//glPopAttrib();
			glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
			//std::cout << "Render to screen" << std::endl;

			RenderToScreen();
		}
	}

	void OpenGLRenderer::RenderTargetTexture()
	{
		int width = 0;
		int height = 0;

		glfwGetWindowSize(&width, &height);

		glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, frameBuffer);
		glPushAttrib(GL_VIEWPORT_BIT | GL_ENABLE_BIT);
		glViewport(0, 0, width, height);

		glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

	}

	void OpenGLRenderer::RenderToScreen()
	{
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		glMatrixMode(GL_MODELVIEW);
		//glPushMatrix();
		glLoadIdentity();
		glMatrixMode(GL_PROJECTION);
		//glPushMatrix();
		glLoadIdentity();

		glBindTexture(GL_TEXTURE_2D, frameBufferTexture);

		//glDisable(GL_BLEND);
		// bind post processing shader here;
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f);	glVertex3f(-1.0f, -1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f);   glVertex3f(-1.0f, 1.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f);	glVertex3f(1.0f, 1.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f);	glVertex3f(1.0f, -1.0f, 0.0f);
		glEnd();
		//glEnable(GL_BLEND);
		glBindTexture(GL_TEXTURE_2D, 0);
		//glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
		//glPopMatrix();
	}

	void OpenGLRenderer::DrawPixels( int width, int height, imageTypes type, const unsigned char *buffer )
	{
		int size;

		int windowWidth = 0;
		int windowHeight = 0;

		glfwGetWindowSize(&windowWidth, &windowHeight); //Should actually use the device...

		glPushMatrix();
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();

		glOrtho(0, (double)windowWidth, 0, (double)windowHeight, -10000.0, 10000.0);

		glMatrixMode(GL_MODELVIEW);

		glPushMatrix();
		glLoadIdentity();
		glEnable (GL_ALPHA_TEST);
		glEnable(GL_BLEND);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE_ARB);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);



				glRasterPos2i(0, height);
		glPixelZoom(1.0f,-1.0f);
		glDrawPixels(width, height, GetGLTextureType(type, size), GL_UNSIGNED_BYTE, buffer);


		glPopMatrix();


		glDisable(GL_TEXTURE_2D);
		glColor4f(1.0, 1.0, 1.0, 1.0);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		glDisable(GL_BLEND);
		glDisable (GL_ALPHA_TEST);
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();
	}

	int OpenGLRenderer::GetGLStreamType( streamTypes type )
	{
		int value = -1;
		switch (type)
		{
		case X2_STATIC_DRAW:
			value = GL_STATIC_DRAW;
			break;
		case X2_DYNAMIC_DRAW:
			value = GL_DYNAMIC_DRAW;
			break;
		case X2_STREAM_DRAW:
			value = GL_STREAM_DRAW;
			break;
		}

		return value;
	}

	unsigned int OpenGLRenderer::GetGLBufferAccessType( bufferAccessTypes type )
	{
		int value = -1;
		switch (type)
		{
		case X2_MAP_WRITE_BIT:
			value = GL_MAP_WRITE_BIT;
			break;
		case X2_MAP_READ_BIT:
			value = GL_MAP_READ_BIT;
			break;
		}

		return value;
	}

	unsigned int OpenGLRenderer::GetGLBufferType( bufferTypes type )
	{
		int value = -1;
		switch (type)
		{
		case X2_ARRAY_BUFFER:
			value = GL_ARRAY_BUFFER;
			break;
		case X2_ELEMENT_ARRAY_BUFFER:
			value = GL_ELEMENT_ARRAY_BUFFER;
			break;
		case X2_PIXEL_PACK_BUFFER:
			value = GL_PIXEL_PACK_BUFFER;
			break;
		case X2_PIXEL_UNPACK_BUFFER:
			value = GL_PIXEL_UNPACK_BUFFER;
			break;


		}

		return value;
	}
}

