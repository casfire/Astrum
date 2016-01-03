#ifndef _GUI_RENDERER_
#define _GUI_RENDERER_

#include "../Render/Render.hpp"
#include "Label.hpp"
#include "Button.hpp"

namespace gui {
	
	class GuiRenderer {
	public:
		
		GuiRenderer(
			const AmbientRender& ambient,
			const Quad&          quad,
			const unsigned&      font,
			const unsigned&      gui
		);
		
		void setFontUnit(unsigned font);
		void setGuiUnit (unsigned gui);
		
		void render(
			const Camera2D& camera,
			const Label&    label
		) const;
		
		void render(
			const Camera2D& camera,
			const Button&   button
		) const;
		
	private:
		
		const AmbientRender& ambient;
		const Quad& quad;
		unsigned font, gui;
		
	};
	
}

#endif
