#ifndef _TEXTFIELD_
#define _TEXTFIELD_

#include "../Render/Render.hpp"
#include <string>

namespace gui {
	
	class TextField : public Transform2D {
	public:
		
		enum Align {
			MIN = 0,
			MID = 1,
			MAX = 2,
		};
		
		TextField(
			const std::string& text = "",
			const glm::vec4& color = glm::vec4(1),
			Align alignX = MID,
			Align alignY = MID
		);
		
		void setText      (const std::string& text);
		void setTextColor (const glm::vec4& color);
		void setTextAlign (Align x, Align y);
		void setTextAlignX(Align x);
		void setTextAlignY(Align y);
		
		const std::string& getText() const;
		glm::vec4 getTextColor() const;
		Align getTextAlignX() const;
		Align getTextAlignY() const;
		
		void render(
			const Camera2D&      camera,
			const AmbientRender& ambient,
			const Quad&          quad,
			const unsigned&      font
		) const;
		
	private:
		
		std::string text;
		glm::vec4 color;
		float width;
		Align alignX;
		Align alignY;
		
	};
	
}

#endif
