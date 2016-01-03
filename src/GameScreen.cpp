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
	
	// Texture bindings
	resources.white->bind(0);
	resources.font->bind(1);
	resources.gui->bind(2);
	
	// Set GUI
	glm::vec2 size = window.getSize();
	cameraGUI.setSize(size);
	cameraGUI.setCenter(size * 0.5f);
	cameraGUI.setRotation(0);
	gui.load(resources.ambient.get(), resources.quad.get(), 1, 2);
	
	// Set FPS counter
	window.setVsync(false);
	timer.setSmoothing(0.99);
	textFPS.setPosition(4, size.y - 18);
	textFPS.setSize(size.x, 16);
	textFPS.setTextSize(textFPS.getSizeY());
	textFPS.setTextColor(glm::vec4(1, .1, .2, 1));
	textFPS.setTextAlignX(Label::ALIGN_MIN);
	
	// Initialization
	timer.restart();
	
	// Button
	button.setSize(190, 49);
	button.setPosition(size * 0.5f);
	button.setOrigin(button.getSize() * 0.5f);
	button.setText("End game");
	button.setTextSize(12);
	button.setButtonColor(glm::vec4(0.5, 0.5, 1.0, 1));
}

void GameScreen::onPress(glm::vec2 pos)
{
	glm::vec2 world = cameraGUI.toWorld(pos);
	if (button.isInside(world)) button.setPressed(true);
}

void GameScreen::onRelease(glm::vec2)
{
	if (button.isPressed()) {
		button.setPressed(false);
		quit();
	}
}

void GameScreen::onRender()
{
	timer.restart();
	
	// Clear and bind screen
	bind(true);
	
	// Render FPS counter
	textFPS.setText(std::string("FPS: ") + timer.fpsString(3));
	gui->render(cameraGUI, textFPS);
	
	// Render button
	gui->render(cameraGUI, button);
}
