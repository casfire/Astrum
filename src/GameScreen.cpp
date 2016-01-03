#include "GameScreen.hpp"
#include <cmath>

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
	FpsTimer.setSmoothing(0.99);
	FpsText.setPosition(4, size.y - 18);
	FpsText.setSize(size.x, 16);
	FpsText.setTextSize(FpsText.getSizeY());
	FpsText.setTextColor(glm::vec4(1, .1, .2, 1));
	FpsText.setTextAlignX(Label::ALIGN_MIN);
	
	// Button
	button.setSize(190, 49);
	button.setPosition(size * 0.5f);
	button.setOrigin(button.getSize() * 0.5f);
	button.setText("End game");
	button.setTextSize(12);
	button.setButtonColor(glm::vec4(1.0, 0.5, 0.5, 1));
	button.setButtonStyle(Button::HALF);
	
	// Timers
	FpsTimer.restart();
	elapsed.restart();
}

void GameScreen::onPress(glm::vec2 pos)
{
	pos = cameraGUI.toWorld(pos);
	if (button.isInside(pos)) button.setPressed(true);
}

void GameScreen::onRelease(glm::vec2 pos)
{
	pos = cameraGUI.toWorld(pos);
	if (button.isPressed() && button.isInside(pos)) quit();
	button.setPressed(false);
}

void GameScreen::onRender()
{
	
	// Set button color
	float r = 0.5 + 0.25 * (std::sin(elapsed.elapsed() * 2) + 1);
	float g = 0.5 + 0.25 * (std::sin(elapsed.elapsed() * 4) + 1);
	float b = 0.5 + 0.25 * (std::sin(elapsed.elapsed() * 6) + 1);
	button.setButtonColor(glm::vec4(r, g, b, 1));
	
	// Set background color
	ClearState(0.5 * (1 - r), 0.2 * (1 - g), 0.5 * (1 - b), 1).enable();
	
	// Clear and bind screen
	bind(true);
	
	// Render button
	gui->render(cameraGUI, button);
	
	// Render FPS counter
	FpsTimer.restart();
	FpsText.setText(std::string("FPS: ") + FpsTimer.fpsString(3));
	gui->render(cameraGUI, FpsText);
	
}
