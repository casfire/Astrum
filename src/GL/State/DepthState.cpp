#include "DepthState.hpp"
#include "../gles2.hpp"
#include <cstddef>

using namespace GL;

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

DepthState::DepthState(
	Compare test,
	bool write
)
: test(test)
, write(write)
{}

void DepthState::enable() const
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(func[static_cast<std::size_t>(test)]);
	glDepthMask(write);
}

void DepthState::disable()
{
	glDisable(GL_DEPTH_TEST);
}

bool DepthState::operator==(const DepthState& obj) const
{
	return test == obj.test && write == obj.write;
}
