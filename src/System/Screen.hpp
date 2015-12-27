#ifndef _SCREEN_
#define _SCREEN_

#include "Window.hpp"
#include "../glm/vec2.hpp"
#include "../GL/Viewport.hpp"

namespace System {
	
	class Screen : public GL::Viewport {
	public:
		
		Screen(const Window& window);
		void run();
		
	protected:
		
		void quit();
		
		virtual void onPress  (glm::vec2 pos);
		virtual void onRelease(glm::vec2 pos);
		virtual void onSlide  (glm::vec2 from, glm::vec2 to);
		
		virtual void onInit();
		virtual void onRender() = 0;
		virtual void onExit();
		
	protected:
		
		const Window& window;
		
	private:
		
		bool loop;
		
	};
	
}

#endif
