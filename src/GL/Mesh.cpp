#include "Mesh.hpp"
#include "gles2.hpp"

using namespace GL;

static const GLenum types[] = {
	GL_POINTS,
	GL_LINE_STRIP,
	GL_LINE_LOOP,
	GL_LINES,
	GL_TRIANGLE_STRIP,
	GL_TRIANGLE_FAN,
	GL_TRIANGLES,
};

Mesh::Mesh(
	Type type,
	std::size_t count,
	std::size_t start
)
: type(types[static_cast<std::size_t>(type)])
, count(count)
, start(start)
{}

