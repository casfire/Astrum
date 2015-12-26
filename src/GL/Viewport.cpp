#include "Viewport.hpp"
#include "gles2.hpp"

using namespace GL;

Viewport::Viewport(
	std::size_t width,
	std::size_t height,
	std::size_t x,
	std::size_t y
)
: FB(0)
, bits(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT)
, x(x)
, y(y)
, width(width)
, height(height)
{}

Viewport::Viewport(
	const FrameBuffer& frame,
	std::size_t width,
	std::size_t height,
	std::size_t x,
	std::size_t y
)
: FB(frame.ID)
, bits(0)
, x(x)
, y(y)
, width(width)
, height(height)
{
	if (frame.texture != nullptr) bits |= GL_COLOR_BUFFER_BIT;
	if (frame.stencil != nullptr) bits |= GL_STENCIL_BUFFER_BIT;
	if (frame.depth   != nullptr) bits |= GL_DEPTH_BUFFER_BIT;
}

void Viewport::bind(bool clear) const
{
	glBindFramebuffer(GL_FRAMEBUFFER, FB);
	glViewport(x, y, width, height);
	if (clear) glClear(bits);
}
