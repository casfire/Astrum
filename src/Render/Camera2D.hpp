#ifndef _CAMERA2D_
#define _CAMERA2D_

#include "../glm/vec2.hpp"
#include "../glm/mat3x3.hpp"

namespace Render {
	
	class Camera2D {
	public:
		
		typedef glm::vec2 vec2;
		typedef glm::mat3 mat3;
		
		Camera2D(const Camera2D& camera);
		Camera2D(
			vec2  center   = vec2(0),
			vec2  size     = vec2(2),
			float rotation = 0
		);
		
		// Center
		vec2  getCenter () const;
		float getCenterX() const;
		float getCenterY() const;
		void setCenter (vec2 center);
		void setCenter (float x, float y);
		void setCenterX(float x);
		void setCenterY(float y);
		
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
		void setRotation(float rotation);
		
		// Point translation
		vec2 toWorld (vec2 screen) const;
		vec2 toScreen(vec2 world ) const;
		
		// Miscellaneous
		const mat3& getMatrix() const;
		void setCamera(const Camera2D& camera);
		
	private:
		
		vec2 center, size;
		float rotation;
		
		mutable mat3 matrix;
		mutable bool valid;
		
	};
	
}

#endif
