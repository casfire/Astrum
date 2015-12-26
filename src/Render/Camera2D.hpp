#ifndef _CAMERA2D_
#define _CAMERA2D_

#include "../glm/vec2.hpp"
#include "../glm/mat3x3.hpp"

namespace Render {
	
	class Camera2D {
	public:
		
		Camera2D(const Camera2D& camera);
		Camera2D(
			glm::vec2 center = glm::vec2(0, 0),
			glm::vec2 size   = glm::vec2(2, 2),
			float rotation   = 0
		);
		
		glm::vec2 getCenter() const;
		glm::vec2 getSize() const;
		float getRotation() const;
		
		void setRotation(float rot);
		void setCenter  (glm::vec2 center);
		void setSize    (glm::vec2 size);
		void setCenter  (float x, float y);
		void setSize    (float x, float y);
		
		const glm::mat3& getMatrix() const;
		
	private:
		
		glm::vec2 center, size;
		float rotation;
		
		mutable glm::mat3 matrix;
		mutable bool changed;
		
	};
	
}

#endif
