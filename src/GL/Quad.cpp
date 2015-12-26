#include "Quad.hpp"

using namespace GL;

static float vData[] = {
	-1, +1, 0, 1,
	+1, +1, 1, 1,
	+1, -1, 1, 0,
	-1, -1, 0, 0,
};

Quad::Quad()
: buffer(vData, 4, 4)
, position(buffer, 2, 0)
, texcoord(buffer, 2, 2)
, mesh(GL::Mesh::TRIANGLE_FAN, 4, 0)
{}
