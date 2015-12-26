#include "StencilState.hpp"
#include "../gles2.hpp"
#include <cstddef>

using namespace GL;

static const GLenum op[] = {
	GL_KEEP,
	GL_ZERO,
	GL_REPLACE,
	GL_INCR,
	GL_INCR_WRAP,
	GL_DECR,
	GL_DECR_WRAP,
	GL_INVERT,
};

static const GLenum func[] = {
	GL_ALWAYS,
	GL_NEVER,
	GL_LESS,
	GL_LEQUAL,
	GL_EQUAL,
	GL_NOTEQUAL,
	GL_GEQUAL, 
	GL_GREATER,
};

static const GLenum faces[] = {
	GL_FRONT_AND_BACK,
	GL_FRONT,
	GL_BACK,
};

StencilState::StencilState(
	Compare test,
	Action stencilFail,
	Action stencilPassDepthFail,
	Action stencilPassDepthPass,
	std::uint8_t reference,
	std::uint8_t maskRead,
	std::uint8_t maskWrite,
	Face face
)
: face(face)
, test(test)
, stencilFail(stencilFail)
, stencilPassDepthFail(stencilPassDepthFail)
, stencilPassDepthPass(stencilPassDepthPass)
, reference(reference)
, maskRead(maskRead)
, maskWrite(maskWrite)
{}

void StencilState::enable() const
{
	GLenum f = faces[static_cast<std::size_t>(face)];
	glEnable(GL_STENCIL_TEST);
	glStencilMaskSeparate(f, maskWrite);
	glStencilOpSeparate(
		f,
		op[static_cast<std::size_t>(stencilFail)],
		op[static_cast<std::size_t>(stencilPassDepthFail)],
		op[static_cast<std::size_t>(stencilPassDepthPass)]
	);
	glStencilFuncSeparate(
		f,
		func[static_cast<std::size_t>(test)],
		reference,
		maskRead
	);
}

void StencilState::disable()
{
	glDisable(GL_STENCIL_TEST);
}

bool StencilState::operator==(const StencilState& obj) const
{
	return
		face == obj.face &&
		test == obj.test &&
		stencilFail == obj.stencilFail &&
		stencilPassDepthFail == obj.stencilPassDepthFail &&
		stencilPassDepthPass == obj.stencilPassDepthPass &&
		reference == obj.reference &&
		maskRead  == obj.maskRead  &&
		maskWrite == obj.maskWrite;
}
