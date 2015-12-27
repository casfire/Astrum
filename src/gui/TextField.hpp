#ifndef _TEXTFIELD_
#define _TEXTFIELD_

#include "../Render/Render.hpp"
#include <string>

namespace gui {
	
	class TextField : public Transform2D {
	public:
		
		TextField(
			const std::string& txt = "",
			bool fill = false
		);
		
		void setText(const std::string& txt);
		const std::string& getText() const;
		
		void setFill(bool enabled);
		
		float getTextWidth() const;
		float getTextHeight() const;
		glm::vec2 getTextSize() const;
		
		void render(
			const Camera2D& camera,
			const AmbientRender& ambient,
			const Quad& quad,
			unsigned texture,
			glm::vec4 color = glm::vec4(1)
		) const;
		
	private:
		
		std::string text;
		float width;
		bool filled;
		
	};
	
}

#endif
