#ifndef _FRAME_BUFFER_
#define _FRAME_BUFFER_

#include "Texture.hpp"
#include "StencilBuffer.hpp"
#include "DepthBuffer.hpp"

namespace GL {
	
	class FrameBuffer {
	public:
		
		FrameBuffer(
			const Texture*       texture,
			const StencilBuffer* stencil,
			const DepthBuffer*   depth
		);
		
		~FrameBuffer();
		
		const unsigned int ID;
		const Texture* texture;
		const StencilBuffer* stencil;
		const DepthBuffer* depth;
		
	private:
		
		FrameBuffer(const FrameBuffer&) = delete;
		FrameBuffer& operator=(const FrameBuffer&) = delete;
		
	};
	
}

#endif
