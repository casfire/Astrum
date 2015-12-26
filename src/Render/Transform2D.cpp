#include "Transform2D.hpp"
#include <cmath>

using namespace Render;

Transform2D::Transform2D(
	glm::vec2 position,
	glm::vec2 origin,
	glm::vec2 size,
	float rotation
)
: position(position)
, origin(origin)
, size(size)
, rotation(rotation)
, changed(true)
{}

Transform2D::Transform2D(const Transform2D& t)
: position(t.position)
, origin(t.origin)
, size(t.size)
, rotation(t.rotation)
, matrix(t.matrix)
, changed(t.changed)
{}

glm::vec2 Transform2D::getPosition() const
{
	return position;
}

glm::vec2 Transform2D::getOrigin() const
{
	return origin;
}

glm::vec2 Transform2D::getSize() const
{
	return size;
}

float Transform2D::getRotation() const
{
	return rotation;
}

void Transform2D::setRotation(float rot)
{
	rotation = rot;
	changed = true;
}

void Transform2D::setPosition(glm::vec2 pos)
{
	position = pos;
	changed = true;
}

void Transform2D::setPosition(float x, float y)
{
	position = glm::vec2(x, y);
	changed = true;
}

void Transform2D::setSize(glm::vec2 size)
{
	this->size = size;
	changed = true;
}

void Transform2D::setSize(float x, float y)
{
	size = glm::vec2(x, y);
	changed = true;
}

void Transform2D::setOrigin(glm::vec2 origin)
{
	this->origin = origin;
	changed = true;
}

void Transform2D::setOrigin(float x, float y)
{
	origin = glm::vec2(x, y);
	changed = true;
}

void Transform2D::setOriginN(glm::vec2 origin)
{
	this->origin = origin * size;
	changed = true;
}

void Transform2D::setOriginN(float x, float y)
{
	origin = glm::vec2(x, y) * size;
	changed = true;
}

const glm::mat3& Transform2D::getMatrix() const
{
	if (!changed) return matrix;
	changed = false;
	float c = std::cos(rotation);
	float s = std::sin(rotation);
	float sx = 0.5 * size.x;
	float sy = 0.5 * size.y;
	float ox = sx - origin.x;
	float oy = sy - origin.y;
	float px = position.x;
	float py = position.y;
	glm::mat3 matRotation(
		+c, +s, 0,
		-s, +c, 0,
		+0, +0, 1
	);
	glm::mat3 matScale(
		sx, 0,  0,
		0,  sy, 0,
		0,  0,  1
	);
	glm::mat3 matTranslate(
		1,  0,  0,
		0,  1,  0,
		px, py, 1
	);
	glm::mat3 matOrigin(
		1,  0,  0,
		0,  1,  0,
		ox, oy, 1
	);
	return matrix = matTranslate * matRotation * matOrigin * matScale;
}
