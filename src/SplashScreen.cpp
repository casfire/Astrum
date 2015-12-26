#include "SplashScreen.hpp"

SplashScreen::SplashScreen(
	const Window& window,
	Resources& resources
)
: Screen(window)
, resources(resources)
{}
	
void SplashScreen::onInit()
{
	// Set states
	BlendState::disable();
	CullState::disable();
	DepthState::disable();
	ScissorState::disable();
	StencilState::disable();
	ClearState(0, 0, 0, 1).enable();
	
	// Load basic resources
	std::uint8_t white[] = {0xFF, 0xFF, 0xFF, 0xFF};
	resources.quad.load();
	resources.ambient.load(resources.camera);
	resources.white.load(1, 1, 4, white, Texture::NEAREST, Texture::REPEAT);
	
	// Set camera view
	glm::vec2 size = window.getSize();
	resources.camera.setSize(size);
	resources.camera.setCenter(0, 0);
	resources.camera.setRotation(0);
	
	// Load splash texture
	splash.load("assets/splash.png", Texture::BILINEAR, Texture::CLAMP);
	
	// Create screen viewport
	screen.load(size.x, size.y);
	
	// Texture bindings
	resources.white->bind(0);
	splash->bind(1);
	
	// Background
	obj_background.load(
		resources.quad.get(),
		1,
		Transform2D(
			glm::vec2(0),
			glm::vec2(size * 0.5f),
			glm::vec2(size)
		).getMatrix()
	);
	
	// Loading bar border
	loading.setSize(size * glm::vec2(0.9, 0.05));
	loading.setOriginN(0.5, 0.5);
	loading.setPosition(0, size.y * 0.25);
	obj_border.load(
		resources.quad.get(),
		0,
		loading.getMatrix()
	);
	
	// Loading bar
	loading.setSize(loading.getSize() - glm::vec2(2));
	loading.setOriginN(0.5, 0.5);
	loading_width = loading.getSize().x;
	obj_bar.load(
		resources.quad.get(),
		0,
		loading.getMatrix(),
		glm::vec4(0.2, 0.1, 0.8, 1.0)
	);
	
}

void SplashScreen::onRender()
{
	// Clear and bind screen
	screen->bind(true);
	
	// Draw background
	resources.ambient->render(obj_background.get());
	
	// Draw loading bar border
	resources.ambient->render(obj_border.get());
	
	// Draw loading bar
	resources.ambient->render(obj_bar.get());
	
}
