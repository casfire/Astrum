#include "GuiRenderer.hpp"

using namespace gui;

GuiRenderer::GuiRenderer(
	const AmbientRender& ambient,
	const Quad&          quad,
	const unsigned&      font,
	const unsigned&      gui
)
: ambient(ambient)
, quad(quad)
, font(font)
, gui(gui)
{}

void GuiRenderer::setFontUnit(unsigned font)
{
	this->font = font;
}

void GuiRenderer::setGuiUnit(unsigned gui)
{
	this->gui = gui;
}

void GuiRenderer::render(
	const Camera2D& camera,
	const Label&    label
) const {
	label.render(
		camera,
		ambient,
		quad,
		font
	);
}

void GuiRenderer::render(
	const Camera2D& camera,
	const Button&   button
) const {
	button.render(
		camera,
		ambient,
		quad,
		gui,
		font
	);
}
