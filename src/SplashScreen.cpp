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
	
	// Load resources
	std::uint8_t white[] = {0xFF, 0xFF, 0xFF, 0xFF};
	resources.quad.load();
	resources.ambient.load();
	resources.white.load(1, 1, 4, white, Texture::NEAREST, Texture::REPEAT);
	splash.load("assets/splash.png", Texture::BILINEAR, Texture::CLAMP);
	
	// Set camera
	glm::vec2 size = window.getSize();
	camera.setSize(size);
	camera.setCenter(0, 0);
	camera.setRotation(0);
	
	// Texture bindings
	resources.white->bind(0);
	splash->bind(1);
	
	// Background
	obj_background.load(resources.quad.get(), 1);
	obj_background->setSize(size);
	obj_background->setOrigin(size * 0.5f);
	
	// Loading bar border
	obj_border.load(resources.quad.get(), 0);
	obj_border->setSize(size * glm::vec2(0.9, 0.05));
	obj_border->setOrigin(obj_border->getSize() * 0.5f);
	obj_border->setPosition(0, size.y * 0.25);
	
	// Loading bar
	obj_bar.load(resources.quad.get(), 0, glm::vec4(0.2, 0.1, 0.8, 1.0));
	obj_bar->setSize(obj_border->getSize() - glm::vec2(2));
	obj_bar->setOrigin(obj_bar->getSize() * 0.5f);
	obj_bar->setPosition(0, size.y * 0.25);
	
	// Initialization
	count = 0;
	
}

void SplashScreen::onRender()
{
	
	// Load next resource
	Texture::Filter filter = Texture::TRILINEAR;
	switch (count) {
	case 0: break;
	case 1:  resources.font   .load("assets/sprites/font.png",    filter, Texture::CLAMP); break;
	case 2:  resources.gui    .load("assets/sprites/gui.png",     filter, Texture::CLAMP); break;
	case 3:  resources.planets.load("assets/sprites/planets.png", filter, Texture::CLAMP); break;
	case 4:  resources.thrust .load("assets/sprites/thrust.png",  filter, Texture::CLAMP); break;
	case 5:  resources.ship   .load("assets/sprites/ship.png",    filter, Texture::CLAMP); break;
	case 6:  resources.sat    .load("assets/sprites/sat.png",     filter, Texture::CLAMP); break;
	case 7:  resources.space_back1.load("assets/space/back1.png", filter, Texture::CLAMP); break;
	case 8:  resources.space_back2.load("assets/space/back2.png", filter, Texture::CLAMP); break;
	case 9:  resources.space_dust1.load("assets/space/dust1.png", filter, Texture::CLAMP); break;
	case 10: resources.space_dust2.load("assets/space/dust2.png", filter, Texture::CLAMP); break;
	case 11: resources.space_dust3.load("assets/space/dust3.png", filter, Texture::CLAMP); break;
	case 12: resources.space_dust4.load("assets/space/dust4.png", filter, Texture::CLAMP); break;
	default:
		quit();
		return;
	}
	
	// Set progress
	float progress = count++ / 13.f;
	obj_bar->setSizeX(progress * (obj_border->getSizeX() - 2));
	
	// Clear and bind screen
	bind(true);
	
	// Draw background
	resources.ambient->render(camera, obj_background.get());
	
	// Draw loading bar border
	resources.ambient->render(camera, obj_border.get());
	
	// Draw loading bar
	resources.ambient->render(camera, obj_bar.get());
	
}
