#ifndef _ATTRIBUTE_
#define _ATTRIBUTE_

#include "VertexBuffer.hpp"
#include <cstddef>

namespace GL {
	
	class Attribute {
	public:
		
		// Size   - Must be 1, 2, 3 or 4
		// Offset - Starting float in vertex buffer
		
		Attribute(
			const VertexBuffer& buffer,
			std::size_t size,
			std::size_t offset
		);
		
		const unsigned int buffer;
		const int size;
		const int stride;
		const void* pointer;
		
	};
	
}

#endif
