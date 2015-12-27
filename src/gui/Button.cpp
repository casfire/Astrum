#include "Button.hpp"

using namespace gui;

/*static glm::ivec4 buttonRects[] = {
	glm::ivec4(0, 0,   195, 49),
	glm::ivec4(0, 49,  191, 49),
	glm::ivec4(0, 98,  190, 45),
	glm::ivec4(0, 143, 190, 45),
	glm::ivec4(0, 188, 190, 49),
	glm::ivec4(0, 237, 190, 49),
	glm::ivec4(0, 286, 190, 45),
	glm::ivec4(0, 331, 190, 49),
	glm::ivec4(0, 384, 190, 49),
};*/

static glm::vec2 guiSize = glm::vec2(512, 512);

static glm::ivec4 buttonPressed[] = {
	glm::ivec4(0, 98,  190, 45),
	glm::ivec4(0, 143, 190, 45),
	glm::ivec4(0, 286, 190, 45),
};

static glm::ivec4 buttonReleased[] = {
	glm::ivec4(0, 188, 190, 49),
	glm::ivec4(0, 237, 190, 49),
	glm::ivec4(0, 331, 190, 49),
};

Button::Button(Style style, bool pressed)
: style(style)
, pressed(pressed)
{}

void Button::setStyle(Style style)
{
	this->style = style;
}

void Button::setPressed(bool pressed)
{
	this->pressed = pressed;
}

bool Button::isInside(glm::vec2 point) const
{
	glm::vec2 a = getPosition();
	glm::vec2 b = a + getSize();
	if (point.x < a.x || point.x > b.x) return false;
	if (point.y < a.y || point.y > b.y) return false;
	return true;
}

void Button::render(
	const Camera2D& camera,
	const AmbientRender& ambient,
	const Quad& quad,
	unsigned texture,
	glm::vec4 color
) const {
	
	std::size_t s = static_cast<std::size_t>(style);
	glm::ivec4 irect = pressed ? buttonPressed[s] : buttonReleased[s];
	
	Transform2D matrix(*this);
	glm::vec2 position = getPosition();
	glm::vec2 size = getSize();
	
	if (pressed) {
		matrix.setPosition(position + glm::vec2(0, size.y * 4 / 45));
	} else {
		matrix.setSize(size + glm::vec2(0, size.y * 4 / 45));
	}
	
	ambient.render(
		camera,
		quad,
		texture,
		matrix.getMatrix(),
		color,
		glm::vec4(
			irect.x / guiSize.x,
			irect.y / guiSize.y,
			(irect.x + irect.z) / guiSize.x,
			(irect.y + irect.w) / guiSize.y
		)
	);
	
}