#ifndef _LABEL_
#define _LABEL_

#include "../Render/Render.hpp"
#include <string>

namespace gui {
	
	class Label : public Transform2D {
	public:
		
		enum Align {
			ALIGN_MIN = 0,
			ALIGN_MID = 1,
			ALIGN_MAX = 2,
		};
		
		Label(
			const std::string& text   = "",
			const float&       size   = 45,
			const glm::vec4&   color  = glm::vec4(1),
			const Align&       alignX = ALIGN_MID,
			const Align&       alignY = ALIGN_MID
		);
		
		void setText      (const std::string& text);
		void setTextColor (const glm::vec4& color);
		void setTextSize  (float size);
		void setTextAlign (Align x, Align y);
		void setTextAlignX(Align x);
		void setTextAlignY(Align y);
		
		const std::string& getText() const;
		glm::vec4 getTextColor() const;
		float getTextSize() const;
		
		void render(
			const Camera2D&      camera,
			const AmbientRender& ambient,
			const Quad&          quad,
			const unsigned&      font
		) const;
		
	private:
		
		std::string text;
		glm::vec4 color;
		glm::vec2 align;
		float size;
		
	};
	
}

#endif
