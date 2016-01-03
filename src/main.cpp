#include "SDL/SDL.h"
#include <exception>

#include "GL/GL.hpp"
#include "System/System.hpp"
#include "Render/Render.hpp"

#include "Resources.hpp"
#include "SplashScreen.hpp"
#include "MenuScreen.hpp"

int main(int, char**) {
	
	try {
		
		Window window("Astrum", false, 8);
		Resources resources;
		
		SplashScreen(window, resources).run();
		MenuScreen(window, resources).run();
		
		return 0;
		
	} catch (std::exception& e) {
		
		SDL_ShowSimpleMessageBox(
			SDL_MESSAGEBOX_ERROR,
			"Error", e.what(), nullptr
		);
		return 1;
		
	} catch (...) {
		
		SDL_ShowSimpleMessageBox(
			SDL_MESSAGEBOX_ERROR,
			"Error", "Unknown error", nullptr
		);
		return 1;
		
	}
	
}
