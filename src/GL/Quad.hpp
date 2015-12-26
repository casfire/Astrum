#ifndef _QUAD_
#define _QUAD_

#include "Mesh.hpp"
#include "VertexBuffer.hpp"
#include "Attribute.hpp"

namespace GL {
	
	class Quad {
	public:
		
		Quad();
		
		const VertexBuffer buffer;
		const Attribute position;
		const Attribute texcoord;
		const Mesh mesh;
		
	private:
		
		Quad(const Quad&) = delete;
		Quad& operator=(const Quad&) = delete;
		
	};
	
}

#endif
