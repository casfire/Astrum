#ifndef _AMBIENT_OBJECT_
#define _AMBIENT_OBJECT_

#include "../GL/GL.hpp"
#include "../glm/vec4.hpp"
#include "../glm/mat3x3.hpp"

namespace Render {
	
	struct AmbientObject {
		
		Mesh      mesh;
		Attribute position;
		Attribute texcoord;
		unsigned  texture;
		glm::mat3 matrix;
		glm::vec4 color;
		glm::vec4 rect;
		
		AmbientObject(
			const Mesh&      mesh,
			const Attribute& position,
			const Attribute& texcoord,
			const unsigned&  texture,
			const glm::mat3& matrix = glm::mat3(1),
			const glm::vec4& color  = glm::vec4(1),
			const glm::vec4& rect   = glm::vec4(0, 0, 1, 1)
		);
		
		AmbientObject(
			const Quad&      quad,
			const unsigned&  texture,
			const glm::mat3& matrix = glm::mat3(1),
			const glm::vec4& color  = glm::vec4(1),
			const glm::vec4& rect   = glm::vec4(0, 0, 1, 1)
		);
		
	};
	
}

#endif

