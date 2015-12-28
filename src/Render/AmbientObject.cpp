#include "AmbientObject.hpp"

using namespace Render;

AmbientObject::AmbientObject(
	const Mesh&      mesh,
	const Attribute& position,
	const Attribute& texcoord,
	const unsigned&  texture,
	const glm::vec4& color,
	const glm::vec4& rect
)
: mesh(mesh)
, position(position)
, texcoord(texcoord)
, texture(texture)
, color(color)
, rect(rect)
{}

AmbientObject::AmbientObject(
	const Quad&      quad,
	const unsigned&  texture,
	const glm::vec4& color,
	const glm::vec4& rect
)
: mesh(quad.mesh)
, position(quad.position)
, texcoord(quad.texcoord)
, texture(texture)
, color(color)
, rect(rect)
{}
