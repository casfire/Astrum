#ifndef _DEPTH_BUFFER_
#define _DEPTH_BUFFER_

#include <cstddef>

namespace GL {
	
	class DepthBuffer {
	public:
		
		DepthBuffer(
			std::size_t width,
			std::size_t height
		);
		
		~DepthBuffer();
		
		const unsigned int ID;
		const std::size_t width;
		const std::size_t height;
		
	private:
		
		DepthBuffer(const DepthBuffer&) = delete;
		DepthBuffer& operator=(const DepthBuffer&) = delete;
		
	};
	
}

#endif
