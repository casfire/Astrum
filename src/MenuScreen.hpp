#ifndef _MENU_SCREEN_
#define _MENU_SCREEN_

#include "GL/GL.hpp"
#include "System/System.hpp"
#include "Resources.hpp"
#include "gui/gui.hpp"

class MenuScreen : public Screen {
public:
	
	MenuScreen(
		const Window& window,
		Resources& resources
	);
	
	void onInit() override;
	void onRender() override;
	
	void onPress(glm::vec2 pos) override;
	void onRelease(glm::vec2 pos) override;
	
private:
	
	Resources& resources;
	
	Camera2D cameraGUI;
	Resource<GuiRenderer> gui;
	
	Label  title;
	Button start;
	Button settings;
	Button about;
	Button exit;
	
};

#endif
