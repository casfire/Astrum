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
		
		void setText  (const std::string& text);
		void setColor (const glm::vec4& color);
		void setAlign (Align x, Align y);
		void setAlignX(Align x);
		void setAlignY(Align y);
		
		const std::string& getText() const;
		glm::vec4 getColor() const;
		Align getAlignX() const;
		Align getAlignY() const;
		
		void render(
			const Camera2D&      camera,
			const AmbientRender& ambient,
			const Quad&          quad,
			const unsigned&      texture
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
