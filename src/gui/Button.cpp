#include "Button.hpp"
#define _USE_MATH_DEFINES
#include <cmath>

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
	
	if (pressed) {
		glm::vec2 size = getSize();
		float rotation = getRotation() + M_PI_2;
		float length = size.y * (4.f / 49.f);
		matrix.setPosition(
			getPosition() + glm::vec2(
				std::cos(rotation) * length,
				std::sin(rotation) * length
			)
		);
		matrix.setSize(size - glm::vec2(0, length));
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