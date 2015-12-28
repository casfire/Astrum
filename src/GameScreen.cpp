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
	textFPS.setColor(glm::vec4(1, .1, .2, 1));
	textFPS.setPosition(4, size.y - 18);
	textFPS.setSize(size.x, 16);
	textFPS.setAlignX(TextField::MIN);
	window.setVsync(false);
	
	// Texture bindings
	resources.white->bind(0);
	resources.font->bind(1);
	resources.gui->bind(2);
	
	// Initialization
	timer.restart();
	
	// Buttons
	for (int x = 0; x < 3; x++) for (int y = 0; y < 3; y++) {
		button[x][y].setSize(190, 49);
		button[x][y].setStyle(static_cast<Button::Style>(y));
		button[x][y].setPosition(200 + x * 250, 200 + y * 100);
		button[x][y].setRotation(rand() % 800 / 400.f - 1.f);
		if (x == 0) button[x][y].setColor(glm::vec4(0.5, 0.5, 1.0, 1));
		if (x == 1) button[x][y].setColor(glm::vec4(0.5, 0.8, 0.5, 1));
		if (x == 2) button[x][y].setColor(glm::vec4(1.0, 0.5, 0.5, 1));
	}
}

void GameScreen::onPress(glm::vec2 pos)
{
	glm::vec2 gui = cameraGUI.toWorld(pos);
	for (int x = 0; x < 3; x++) for (int y = 0; y < 3; y++) {
		if (button[x][y].isInside(gui)) {
			button[x][y].setPressed(true);
		}
	}
}

void GameScreen::onRelease(glm::vec2 pos)
{
	(void) pos;
	for (int x = 0; x < 3; x++) for (int y = 0; y < 3; y++) {
		button[x][y].setPressed(false);
	}
}

void GameScreen::onRender()
{
	timer.restart();
	
	// Clear and bind screen
	bind(true);
	
	// Render FPS counter
	textFPS.setText(std::string("FPS: ") + timer.fpsString(3));
	textFPS.render(
		cameraGUI,
		resources.ambient.get(),
		resources.quad.get(),
		1
	);
	
	// Render buttons
	for (int x = 0; x < 3; x++) for (int y = 0; y < 3; y++) {
		button[x][y].render(
			cameraGUI,
			resources.ambient.get(),
			resources.quad.get(),
			2
		);
	}
	
}
