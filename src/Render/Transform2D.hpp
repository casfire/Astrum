#ifndef _TRANSFORM2D_
#define _TRANSFORM2D_

#include "../glm/vec2.hpp"
#include "../glm/mat3x3.hpp"

namespace Render {
	
	class Transform2D {
	public:
		
		Transform2D(const Transform2D& t);
		Transform2D(
			glm::vec2 position = glm::vec2(0),
			glm::vec2 origin   = glm::vec2(1),
			glm::vec2 size     = glm::vec2(2),
			float rotation     = 0
		);
		
		// Getters
		glm::vec2 getPosition() const;
		glm::vec2 getOrigin() const;
		glm::vec2 getSize() const;
		float getRotation() const;
		
		// Setters
		void setRotation (float rot);
		void setPosition (glm::vec2 pos);
		void setSize     (glm::vec2 size);
		void setOrigin   (glm::vec2 origin);
		void setOriginN  (glm::vec2 origin);
		void setPosition (float x, float y);
		void setSize     (float x, float y);
		void setOrigin   (float x, float y);
		void setOriginN  (float x, float y);
		
		bool isInside(glm::vec2 point) const;
		
		const glm::mat3& getMatrix() const;
		
	private:
		
		glm::vec2 position, origin, size;
		float rotation;
		
		mutable glm::mat3 matrix;
		mutable bool valid;
		
	};
	
}

#endif
