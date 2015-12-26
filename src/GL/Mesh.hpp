#ifndef _MESH_
#define _MESH_

#include <cstddef>

namespace GL {
	
	class Mesh {
	public:
		
		enum Type {
			POINTS         = 0,
			LINE_STRIP     = 1,
			LINE_LOOP      = 2,
			LINES          = 3,
			TRIANGLE_STRIP = 4,
			TRIANGLE_FAN   = 5,
			TRIANGLES      = 6,
		};
		
		Mesh(
			Type type,
			std::size_t count,
			std::size_t start = 0
		);
		
		const unsigned int type;
		const int count, start;
		
		// Type is one of
		// - GL_POINTS
		// - GL_LINE_STRIP
		// - GL_LINE_LOOP
		// - GL_LINES
		// - GL_TRIANGLE_STRIP
		// - GL_TRIANGLE_FAN
		// - GL_TRIANGLES
		
	};
	
}

#endif
