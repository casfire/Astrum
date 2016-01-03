#ifndef _ABOUT_SCREEN_
#define _ABOUT_SCREEN_

#include "GL/GL.hpp"
#include "System/System.hpp"
#include "Resources.hpp"
#include "gui/gui.hpp"

class AboutScreen : public Screen {
public:
	
	AboutScreen(
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
	Label  about;
	Button ok;
	
};

#endif
