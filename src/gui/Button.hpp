#ifndef _BUTTON_
#define _BUTTON_

#include "../Render/Render.hpp"
#include "Label.hpp"
#include <string>

namespace gui {
	
	class Button : public Label {
	public:
		
		enum Style {
			FLAT = 0,
			HALF = 1,
			GRAD = 2,
		};
		
		Button(
			const std::string& text    = "",
			const glm::vec4&   color   = glm::vec4(1),
			const Style&       style   = GRAD,
			const bool&        pressed = false
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
			const unsigned&      gui,
			const unsigned&      font
		) const;
		
	private:
		
		glm::vec4 color;
		Style style;
		bool pressed;
		
	};
	
}

#endif
