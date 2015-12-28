#ifndef _TRANSFORM2D_
#define _TRANSFORM2D_

#include "../glm/vec2.hpp"
#include "../glm/mat3x3.hpp"

namespace Render {
	
	class Transform2D {
	public:
		
		typedef glm::vec2 vec2;
		typedef glm::mat3 mat3;
		
		Transform2D(const Transform2D& t);
		Transform2D(
			vec2  position = vec2(0),
			vec2  origin   = vec2(1),
			vec2  size     = vec2(2),
			float rotation = 0
		);
		
		// Position
		vec2  getPosition () const;
		float getPositionX() const;
		float getPositionY() const;
		void setPosition (vec2 position);
		void setPosition (float x, float y);
		void setPositionX(float x);
		void setPositionY(float y);
		
		// Origin
		vec2  getOrigin () const;
		float getOriginX() const;
		float getOriginY() const;
		void setOrigin (vec2 origin);
		void setOrigin (float x, float y);
		void setOriginX(float x);
		void setOriginY(float y);
		
		// Size
		vec2  getSize () const;
		float getSizeX() const;
		float getSizeY() const;
		void setSize (vec2 size);
		void setSize (float x, float y);
		void setSizeX(float x);
		void setSizeY(float y);
		
		// Rotation
		float getRotation() const;
		void  setRotation(float rotation);
		
		// Miscellaneous
		const mat3& getMatrix() const;
		bool isInside(vec2 point) const;
		void setTransform(const Transform2D& t);
		
	private:
		
		vec2 position, origin, size;
		float rotation;
		
		mutable mat3 matrix;
		mutable bool valid;
		
	};
	
}

#endif
