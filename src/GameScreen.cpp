#include "GameScreen.hpp"

GameScreen::GameScreen(
	const Window& window,
	Resources& resources
)
: Screen(window)
, resources(resources)
{}

void GameScreen::onInit()
{
	
	// Set states
	CullState::disable();
	DepthState::disable();
	ScissorState::disable();
	StencilState::disable();
	ClearState(0, 0, 0, 1).enable();
	BlendState(
		BlendState::SRC_ALPHA,
		BlendState::ONE_MINUS_SRC_ALPHA,
		BlendState::ADD
	).enable();
	
	// Set GUI camera
	glm::vec2 size = window.getSize();
	cameraGUI.setSize(size);
	cameraGUI.setCenter(size / glm::vec2(2, 2));
	cameraGUI.setRotation(0);
	
	// Set FPS 
	timer.setSmoothing(0.9);
	textFPS.setPosition(4, size.y - 18);
	textFPS.setSize(size.x, 16);
	window.setVsync(false);
	
	// Texture bindings
	resources.white->bind(0);
	resources.font->bind(1);
	
	// Initialization
	timer.restart();
	
}

void GameScreen::onRender()
{
	timer.restart();
	
	textFPS.setText(std::string("FPS: ") + timer.fpsString(3));
	
	bind(true);
	textFPS.render(
		cameraGUI,
		resources.ambient.get(),
		resources.quad.get(),
		1,
		glm::vec4(1, .1, .2, 1)
	);
	
}
