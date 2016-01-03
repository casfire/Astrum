#include "Button.hpp"
#define _USE_MATH_DEFINES
#include <cmath>

using namespace gui;

static glm::vec2 GUITextureSize = glm::vec2(512, 512);
static glm::ivec4 BPressed[] = {
	glm::ivec4(0, 98,  190, 45),
	glm::ivec4(0, 143, 190, 45),
	glm::ivec4(0, 286, 190, 45),
};
static glm::ivec4 BReleased[] = {
	glm::ivec4(0, 188, 190, 49),
	glm::ivec4(0, 237, 190, 49),
	glm::ivec4(0, 331, 190, 49),
};

Button::Button(
	const glm::vec4& color,
	Style style,
	bool pressed
)
: color(color)
, style(style)
, pressed(pressed)
{}

void Button::setButtonStyle(Style style)
{
	this->style = style;
}

void Button::setButtonColor(const glm::vec4& color)
{
	this->color = color;
}

void Button::setPressed(bool pressed)
{
	this->pressed = pressed;
}

Button::Style Button::getButtonStyle() const
{
	return style;
}

glm::vec4 Button::getButtonColor() const
{
	return color;
}

bool Button::isPressed() const
{
	return pressed;
}

void Button::render(
	const Camera2D&      camera,
	const AmbientRender& ambient,
	const Quad&          quad,
	const unsigned&      gui
) const {
	
	std::size_t s = static_cast<std::size_t>(style);
	glm::ivec4 irect = pressed ? BPressed[s] : BReleased[s];
	
	Transform2D object(*this);
	
	if (pressed) {
		float sizeY = getSizeY();
		float rotation = getRotation() + M_PI_2;
		float length = sizeY * (4.f / 49.f);
		object.setPosition(
			getPosition() + glm::vec2(
				std::cos(rotation) * length,
				std::sin(rotation) * length
			)
		);
		object.setSizeY(sizeY - length);
	}
	
	ambient.render(
		camera,
		quad,
		gui,
		object,
		color,
		glm::vec4(
			irect.x / GUITextureSize.x,
			irect.y / GUITextureSize.y,
			(irect.x + irect.z) / GUITextureSize.x,
			(irect.y + irect.w) / GUITextureSize.y
		)
	);
	
}