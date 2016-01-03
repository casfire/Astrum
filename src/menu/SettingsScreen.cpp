#include "SettingsScreen.hpp"

SettingsScreen::SettingsScreen(
	const Window& window,
	Resources& resources
)
: Screen(window)
, resources(resources)
{}

void SettingsScreen::onInit()
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
	
	// About
	about.setSize(bSize);
	about.setOrigin(bSize.x * 0.5f, 0);
	about.setPosition(bPosition.x, bPosition.y);
	about.setText("This is the settings screen");
	about.setTextSize(bTextSize);
	
	// Settings
	ok.setSize(bSize);
	ok.setOrigin(bSize.x * 0.5f, 0);
	ok.setPosition(bPosition.x, bPosition.y + bSize.y + bMargin);
	ok.setText("Ok");
	ok.setTextSize(bTextSize);
	ok.setButtonColor(bColor);
}

void SettingsScreen::onPress(glm::vec2 pos)
{
	pos = cameraGUI.toWorld(pos);
	if (ok.isInside(pos)) ok.setPressed(true);
}

void SettingsScreen::onRelease(glm::vec2 pos)
{
	pos = cameraGUI.toWorld(pos);
	if (ok.isPressed() && ok.isInside(pos)) quit();
	ok.setPressed(false);
}

void SettingsScreen::onRender()
{
	// Clear and bind screen
	bind(true);
	
	// Render menu
	gui->render(cameraGUI, title);
	gui->render(cameraGUI, about);
	gui->render(cameraGUI, ok);
	
}