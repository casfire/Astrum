#include "MenuScreen.hpp"
#include "AboutScreen.hpp"
#include "SettingsScreen.hpp"
#include "../GameScreen.hpp"

MenuScreen::MenuScreen(
	const Window& window,
	Resources& resources
)
: Screen(window)
, resources(resources)
{}

void MenuScreen::onInit()
{
	// Set states
	CullState::disable();
	DepthState::disable();
	ScissorState::disable();
	StencilState::disable();
	ClearState(0.02, 0.1, 0.3, 1).enable();
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
	
	// Title
	title.setSize(size.x, 60);
	title.setPosition(0, title.getSizeY());
	title.setTextSize(title.getSizeY());
	title.setTextColor(glm::vec4(1, 1, 1, 1));
	title.setText("Astrum");
	
	// Button settings
	glm::vec2 bPosition(size.x * 0.5f, 2 * title.getSizeY() + title.getPositionY());
	glm::vec2 bSize(190, 49);
	glm::vec4 bColor = glm::vec4(0.5, 0.5, 1.0, 1);
	float     bTextSize = 12;
	float     bMargin = 10;
	
	// Start
	start.setSize(bSize);
	start.setOrigin(bSize.x * 0.5f, 0);
	start.setPosition(bPosition.x, bPosition.y);
	start.setText("Start game");
	start.setTextSize(bTextSize);
	start.setButtonColor(bColor);
	
	// Settings
	settings.setSize(bSize);
	settings.setOrigin(bSize.x * 0.5f, 0);
	settings.setPosition(bPosition.x, bPosition.y + bSize.y + bMargin);
	settings.setText("Settings");
	settings.setTextSize(bTextSize);
	settings.setButtonColor(bColor);
	
	// About
	about.setSize(bSize);
	about.setOrigin(bSize.x * 0.5f, 0);
	about.setPosition(bPosition.x, bPosition.y + 2 * (bSize.y + bMargin));
	about.setText("About");
	about.setTextSize(bTextSize);
	about.setButtonColor(bColor);
	
	// Exit
	exit.setSize(bSize);
	exit.setOrigin(bSize.x * 0.5f, 0);
	exit.setPosition(bPosition.x, bPosition.y + 3 * (bSize.y + bMargin));
	exit.setText("Exit");
	exit.setTextSize(bTextSize);
	exit.setButtonColor(bColor);
}

void MenuScreen::onPress(glm::vec2 pos)
{
	pos = cameraGUI.toWorld(pos);
	if (start.isInside(pos)) start.setPressed(true);
	if (settings.isInside(pos)) settings.setPressed(true);
	if (about.isInside(pos)) about.setPressed(true);
	if (exit.isInside(pos)) exit.setPressed(true);
}

void MenuScreen::onRelease(glm::vec2 pos)
{
	pos = cameraGUI.toWorld(pos);
	
	if (start.isPressed() && start.isInside(pos)) {
		GameScreen(window, resources).run();
		onInit();
	}
	
	if (settings.isPressed() && settings.isInside(pos)) {
		SettingsScreen(window, resources).run();
		onInit();
	}
	
	if (about.isPressed() && about.isInside(pos)) {
		AboutScreen(window, resources).run();
		onInit();
	}
	
	if (exit.isPressed() && exit.isInside(pos)) {
		quit();
	}
	
	start.setPressed(false);
	settings.setPressed(false);
	about.setPressed(false);
	exit.setPressed(false);
}

void MenuScreen::onRender()
{
	// Clear and bind screen
	bind(true);
	
	// Render menu
	gui->render(cameraGUI, title);
	gui->render(cameraGUI, start);
	gui->render(cameraGUI, settings);
	gui->render(cameraGUI, about);
	gui->render(cameraGUI, exit);
	
}