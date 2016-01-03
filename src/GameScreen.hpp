#ifndef _GAME_SCREEN_
#define _GAME_SCREEN_

#include "GL/GL.hpp"
#include "System/System.hpp"
#include "Resources.hpp"
#include "gui/gui.hpp"

class GameScreen : public Screen {
public:
	
	GameScreen(
		const Window& window,
		Resources& resources
	);
	
	void onInit() override;
	void onRender() override;
	
	void onPress(glm::vec2 pos) override;
	void onRelease(glm::vec2 pos) override;
	
private:
	
	Resources& resources;
	
	Timer timer;
	Label textFPS;
	
	Camera2D cameraGUI;
	Resource<GuiRenderer> gui;
	Button button;
	
};

#endif
