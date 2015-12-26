#include "ScissorState.hpp"
#include "../gles2.hpp"

using namespace GL;

ScissorState::ScissorState(
	std::size_t width,
	std::size_t height,
	std::size_t x,
	std::size_t y
)
: x(x)
, y(y)
, width(width)
, height(height)
{}

void ScissorState::enable() const
{
	glEnable(GL_SCISSOR_TEST);
	glScissor(x, y, width, height);
}

void ScissorState::disable()
{
	glDisable(GL_SCISSOR_TEST);
}

bool ScissorState::operator==(const ScissorState& obj) const
{
	return
		x == obj.x &&
		y == obj.y &&
		width == obj.width &&
		height == obj.height;
}
