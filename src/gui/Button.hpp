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
		
		void setButtonStyle(Style style);
		void setButtonColor(const glm::vec4& color);
		void setPressed    (bool pressed);
		
		Style getButtonStyle() const;
		glm::vec4 getButtonColor() const;
		bool isPressed() const;
		
		void render(
			const Camera2D&      camera,
			const AmbientRender& ambient,
			const Quad&          quad,
			const unsigned&      gui
		) const;
		
	private:
		
		glm::vec4 color;
		Style style;
		bool pressed;
		
	};
	
}

#endif
