#include "RendererFactory.h"

Graphics::IRenderer * EngineCore::RendererFactory::CreateRenderer( const std::string &deviceName )
{
	if (deviceName == "OpenGLRenderer") return new Graphics::OpenGLRenderer();
	//if (deviceName == "DirectX11Renderer") return new DirectX11Renderer(); //Coming soon :)
	return nullptr;
}

Graphics::IShaderManager * EngineCore::RendererFactory::CreateShaderManagement(const std::string &deviceName)
{
	if (deviceName == "OpenGLRenderer") return new Graphics::ShaderStorage();
	return nullptr;

}

