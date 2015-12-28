#ifndef _AMBIENT_RENDER_
#define _AMBIENT_RENDER_

#include "../GL/GL.hpp"
#include "../glm/vec4.hpp"
#include "../glm/mat3x3.hpp"
#include "Camera2D.hpp"
#include "Transform2D.hpp"
#include "AmbientObject.hpp"

namespace Render {
	
	class AmbientRender {
	public:
		
		AmbientRender();
		
		void render(
			const Camera2D&    camera,
			const Mesh&        mesh,
			const Attribute&   position,
			const Attribute&   texcoord,
			const unsigned&    texture,
			const Transform2D& object,
			const glm::vec4&   color = glm::vec4(1),
			const glm::vec4&   rect  = glm::vec4(0, 0, 1, 1)
		) const;
		
		void render(
			const Camera2D&    camera,
			const Quad&        quad,
			const unsigned&    texture,
			const Transform2D& object,
			const glm::vec4&   color  = glm::vec4(1),
			const glm::vec4&   rect   = glm::vec4(0, 0, 1, 1)
		) const;
		
		void render(
			const Camera2D&      camera,
			const AmbientObject& object
		) const;
		
	private:
		
		Program program;
		
		int aPosition;
		int aTexCoord;
		
		int uTextureDiffuse;
		int uAmbientColor;
		int uTextureRect;
		int uMatrix;
		
	};
	
}

#endif
