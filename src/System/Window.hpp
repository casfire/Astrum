#ifndef _WINDOW_
#define _WINDOW_

#include "../SDL/SDL.h"
#include "../glm/vec2.hpp"

namespace System {
	
	class Window {
	public:
		
		Window(
			const char* title,
			bool fullscreen
		);
		
		int getHeight() const;
		int getWidth() const;
		glm::ivec2 getSize() const;
		
		glm::vec2 normalize(glm::ivec2 pos) const;
		glm::vec2 normalize(int x, int y) const;
		
		void display() const;
		void setVsync(float enabled) const;
		
		~Window();
		
	private:
		
		SDL_Window* window;
		SDL_GLContext context;
		int w, h;
		
		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;
		
	};
	
}

#endif
