#ifndef _STENCIL_BUFFER_
#define _STENCIL_BUFFER_

#include <cstddef>

namespace GL {
	
	class StencilBuffer {
	public:
		
		StencilBuffer(
			std::size_t width,
			std::size_t height
		);
		
		~StencilBuffer();
		
		const unsigned int ID;
		const std::size_t width;
		const std::size_t height;
		
	private:
		
		StencilBuffer(const StencilBuffer&) = delete;
		StencilBuffer& operator=(const StencilBuffer&) = delete;
		
	};
	
}

#endif
