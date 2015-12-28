#ifndef _BUTTON_
#define _BUTTON_

#include "../Render/Render.hpp"

namespace gui {
	
	class Button : public Transform2D {
	public:
		
		enum Style {
			FLAT = 0,
			HALF = 1,
			GRAD = 2,
		};
		
		Button(
			const glm::vec4& color = glm::vec4(1),
			Style style            = GRAD,
			bool pressed           = false
		);
		
		void setStyle  (Style style);
		void setPressed(bool pressed);
		void setColor  (const glm::vec4& color);
		
		Style getStyle() const;
		bool isPressed() const;
		glm::vec4 getColor() const;
		
		void render(
			const Camera2D&      camera,
			const AmbientRender& ambient,
			const Quad&          quad,
			const unsigned&      texture
		) const;
		
	private:
		
		glm::vec4 color;
		Style style;
		bool pressed;
		
	};
	
}

#endif
