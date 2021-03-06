#ifndef _SPLASH_SCREEN_
#define _SPLASH_SCREEN_

#include "GL/GL.hpp"
#include "System/System.hpp"
#include "Resources.hpp"

class SplashScreen : public Screen {
public:
	
	SplashScreen(
		const Window& window,
		Resources& resources
	);
	
	void onInit() override;
	void onRender() override;
	
private:
	
	Resources& resources;
	
	Resource<Texture> splash;
	Resource<AmbientObject> obj_background;
	Resource<AmbientObject> obj_border;
	Resource<AmbientObject> obj_bar;
	
	Camera2D camera;
	int count;
	
};

#endif
