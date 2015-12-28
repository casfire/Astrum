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
			Style style = GRAD,
			bool pressed = false
		);
		
		void setStyle(Style style);
		void setPressed(bool pressed);
		
		void render(
			const Camera2D& camera,
			const AmbientRender& ambient,
			const Quad& quad,
			unsigned texture,
			glm::vec4 color = glm::vec4(1)
		) const;
		
	private:
		
		Style style;
		bool pressed;
		
	};
	
}

#endif
