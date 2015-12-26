#include "ClearState.hpp"
#include "../gles2.hpp"
#include <cstddef>

using namespace GL;

ClearState::ClearState(
	float r,
	float g,
	float b,
	float a,
	float depth,
	std::uint8_t stencil
)
: r(r)
, g(g)
, b(b)
, a(a)
, depth(depth)
, stencil(stencil)
{}

void ClearState::enable() const
{
	glClearColor(r, g, b, a);
	glClearDepthf(depth);
	glClearStencil(stencil);
}
