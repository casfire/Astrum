#include "CullState.hpp"
#include "../gles2.hpp"
#include <cstddef>

using namespace GL;

static const GLenum faces[] = {
	GL_FRONT_AND_BACK,
	GL_FRONT,
	GL_BACK,
};

static const GLenum fronts[] = {
	GL_CW,
	GL_CCW,
};

CullState::CullState(Face front, Cull which)
: front(front)
, which(which)
{}

void CullState::enable() const
{
	glEnable(GL_CULL_FACE);
	glCullFace(faces[static_cast<std::size_t>(which)]);
	glFrontFace(fronts[static_cast<std::size_t>(front)]);
}

void CullState::disable()
{
	glDisable(GL_CULL_FACE);
}

bool CullState::operator==(const CullState& obj) const
{
	return front == obj.front && which == obj.which;
}
