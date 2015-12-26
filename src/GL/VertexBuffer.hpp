#ifndef _VERTEX_BUFFER_
#define _VERTEX_BUFFER_

#include <cstddef>

namespace GL {
	
	class VertexBuffer {
	public:
		
		// Size  - Number of floats per vertex
		// Count - Number of vertices
		
		VertexBuffer(
			const float* data,
			std::size_t size,
			std::size_t count
		);
		
		~VertexBuffer();
		
		const unsigned int ID;
		const std::size_t size, count;
		
	private:
		
		VertexBuffer(const VertexBuffer&) = delete;
		VertexBuffer& operator=(const VertexBuffer&) = delete;
		
	};
	
}

#endif
