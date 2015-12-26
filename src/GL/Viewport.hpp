#ifndef _VIEWPORT_
#define _VIEWPORT_

#include "FrameBuffer.hpp"
#include <cstddef>

namespace GL {
	
	class Viewport {
	public:
		
		Viewport(
			std::size_t width,
			std::size_t height,
			std::size_t x = 0,
			std::size_t y = 0
		);
		
		Viewport(
			const FrameBuffer& frame,
			std::size_t width,
			std::size_t height,
			std::size_t x = 0,
			std::size_t y = 0
		);
		
		void bind(bool clear = false) const;
		
	private:
		
		unsigned int FB;
		unsigned int bits;
		int x, y, width, height;
		
	};
	
}

#endif
