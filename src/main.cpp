#include "SDL/SDL.h"
#include <exception>

#include "GL/GL.hpp"
#include "System/System.hpp"

int main(int, char**) {
	
	try {
		
		// TODO
		
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
