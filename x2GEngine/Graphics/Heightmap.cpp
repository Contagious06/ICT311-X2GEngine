#include "Heightmap.h"

namespace Graphics
{



	Heightmap::Heightmap( Texture2D *image, const glm::vec3 &textureScale, const glm::vec3 &textureOffset )
	{
		GenerateHeightMap(image, textureScale, textureOffset, nullptr);
	}

	Heightmap::Heightmap( Texture2D *image, const glm::vec3 &textureScale, const glm::vec3 &textureOffset, MaterialVector *material )
	{

		GenerateHeightMap(image, textureScale, textureOffset, material);
	}

	Heightmap::~Heightmap()
	{
		delete m_collisionVerticies;

		delete [] m_imageData;
		//delete m_indexBuffer;
		//delete m_vertexBuffer;
		// 
		delete m_mesh;
	}

	float Heightmap::GetHeight( float x, float y )
	{
		return 0;
	}

	void Heightmap::RenderHeightMap()
	{
		m_mesh->Draw();
		//m_vertexBuffer->RenderBuffer(m_indexBuffer);
	}

	void Heightmap::RenderHeightMap( glm::mat4x4 *translation )
	{
		(*(m_mesh->GetMeshParts()))[0]->SetTransformation(*translation);
		m_mesh->Draw();
	}

	float * Heightmap::GetVerticies()
	{
		return m_collisionVerticies;
	}

	int Heightmap::GetWidth()
	{
		return m_textureX;
	}

	int Heightmap::GetDepth()
	{
		return m_textureY;
	}

	float Heightmap::GetMinHeight()
	{
		return -256;
	}

	float Heightmap::GetMaxHeight()
	{
		return 256;
	}

	unsigned char * Heightmap::GetImageData()
	{
		return m_imageData;
	}

	void Heightmap::GenerateHeightMap( Texture2D *image, const glm::vec3 &textureScale, const glm::vec3 &textureOffset, Graphics::MaterialVector *material )
	{
		m_textureX = image->GetWidth();
		m_textureY = image->GetWidth();

		if (m_textureX != m_textureY)
		{
			std::cout << "Error, height map must be square." << std::endl;
		}


		//m_width = width;
		//m_height = height;
		//m_depth = depth;

		int verticeCount = m_textureX * m_textureY;


		unsigned char *d = new unsigned char[m_textureX * m_textureY];
		m_imageData = d;
		int count = 0;
		for (int i = 0; i < verticeCount * 3; i+=3 )
		{
			d[count] = image->GetTexture()[i];
			count++;
		}

		//float widthSpacing = width / m_textureX;
		//float depthSpacing = depth / m_textureY;


		float widthSpacing = 1.0f;
		float depthSpacing = 1.0f;

		VTN *verticies = new VTN[verticeCount]; 
		m_collisionVerticies = new float[m_textureX * m_textureY * 3];

		bool firstTime = true;

		int x = 0, y = 0;
		for (int i = 0; i < verticeCount; i++)
		{
			float yHeight = d[i];

			verticies[i].vx = x * widthSpacing  - m_textureX/2+0.5f; //Center the height map
			verticies[i].vy = yHeight;
			verticies[i].vz = y * depthSpacing  - m_textureY/2+0.5f;

			m_collisionVerticies[i * 3 + 0] = verticies[i].vx;
			m_collisionVerticies[i * 3 + 1] = verticies[i].vy;
			m_collisionVerticies[i * 3 + 2] = verticies[i].vz;

			//verticies[i].cr = 0;
			//verticies[i].cg = yHeight/255;
			//verticies[i].cb = 0;

			//verticies[i].tx = x * 0.4f;
			//verticies[i].ty	= y * 0.4f;
			// 

			verticies[i].tx = x * textureScale.x + textureOffset.x;
			verticies[i].ty	= y * textureScale.y + textureOffset.y;

			//verticies[i].tz	= yHeight/160;
			verticies[i].tz	= yHeight/256*textureScale.z + textureOffset.z;
			//verticies[i].tz	= 0.;

			x++;
			if (x >= m_textureX)
			{
				x = 0;
				y++;
			}
		}

		//QuadIndices.
		unsigned int *quadIndices = new unsigned int[(m_textureX-1) * (m_textureY-1) * 4];
		x = 0;
		y = 0;

		int i = 0;
		for (int yy = 0; yy < (m_textureY-1); yy++)
		{
			for (int xx = 0; xx < (m_textureX-1); xx++)
			{
				//quadIndices[i + 1] = x + (y + 0) * m_textureY; //Wrong way around
				//quadIndices[i + 0] = x + (y + 1) * m_textureY;

				//quadIndices[i + 2] = x + 1 + (y + 0) * m_textureY;
				//quadIndices[i + 3] = x + 1 + (y + 1) * m_textureY;


				quadIndices[i + 3] = xx + (yy + 0) * m_textureY; //Right way around
				quadIndices[i + 0] = xx + (yy + 1) * m_textureY;

				quadIndices[i + 2] = xx + 1 + (yy + 0) * m_textureY;
				quadIndices[i + 1] = xx + 1 + (yy + 1) * m_textureY;

				i+=4;
			}
		}

		//int numTriIndices = (m_textureX * 2) * (m_textureY - 1) + (m_textureY - 2);
		//unsigned int *triangleIndices = new unsigned int[numTriIndices];
		//x = 0;
		//y = 0;

		//int index = 0;

		//for (int y = 0; y < (m_textureY-1); y++)
		//{
		//	if (y % 2 == 0) //Even
		//	{
		//		for (int x = 0; x < (m_textureX-1); x++)
		//		{
		//			triangleIndices[index++] = x + (y + 0) * m_textureY; //C
		//			triangleIndices[index++] = x + (y + 1) * m_textureY; //D
		//		}

		//		if (y != (m_textureY-2))
		//		{
		//			triangleIndices[index++] = --x + (y + 1) * m_textureY; 
		//		}
		//	}
		//	else
		//	{
		//		for (int x = (m_textureX-1); x >= 0; x--)
		//		{
		//			triangleIndices[index++] = x + (y + 0) * m_textureY; //C
		//			triangleIndices[index++] = x + (y + 1) * m_textureY; //D
		//		}

		//		if (y != (m_textureY-2))
		//		{
		//			triangleIndices[index++] = ++x + (y + 1) * m_textureY; 
		//		}
		//	}

		//}



		//m_indexBuffer = new Graphics::IndexBuffer(triangleIndices, numTriIndices, Graphics::X2_TRIANGLESTRIPS);
		Graphics::IndexBuffer *indexBuffer = new Graphics::IndexBuffer(quadIndices, (m_textureX-1) * (m_textureY-1) * 4, Graphics::X2_QUADS, Graphics::X2_STATIC_DRAW);
		Graphics::VertexBuffer *vertexBuffer = new Graphics::VertexBuffer(verticies, m_textureX * m_textureY, 3, 0, 3, 0, Graphics::X2_STATIC_DRAW);
		
		m_mesh = new Graphics::Mesh;
		m_mesh->SetVertexBuffer(vertexBuffer);

		if (material != nullptr)
		{
			m_mesh->AddMaterials(material->Clone()->materials);
		}
		else
		{
			m_mesh->AddMaterials(nullptr);
		}

		m_mesh->AddMeshPart(new Graphics::MeshPart("HeightMap", 0, indexBuffer));


		delete [] quadIndices;
		delete [] verticies;
	}

	void Heightmap::ComputeNormals( VTN vtn1, VTN vtn2, VTN vtn3 )
	{

	}


}