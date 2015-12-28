#ifndef _AMBIENT_OBJECT_
#define _AMBIENT_OBJECT_

#include "../GL/GL.hpp"
#include "../glm/vec4.hpp"
#include "../glm/mat3x3.hpp"
#include "Transform2D.hpp"

namespace Render {
	
	struct AmbientObject : public Transform2D {
		
		Mesh      mesh;
		Attribute position;
		Attribute texcoord;
		unsigned  texture;
		glm::vec4 color;
		glm::vec4 rect;
		
		AmbientObject(
			const Mesh&      mesh,
			const Attribute& position,
			const Attribute& texcoord,
			const unsigned&  texture,
			const glm::vec4& color  = glm::vec4(1),
			const glm::vec4& rect   = glm::vec4(0, 0, 1, 1)
		);
		
		AmbientObject(
			const Quad&      quad,
			const unsigned&  texture,
			const glm::vec4& color  = glm::vec4(1),
			const glm::vec4& rect   = glm::vec4(0, 0, 1, 1)
		);
		
	};
	
}

#endif

