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
, valid(false)
{}

Transform2D::Transform2D(
	const Transform2D& t
)
: position(t.position)
, origin(t.origin)
, size(t.size)
, rotation(t.rotation)
, matrix(t.matrix)
, valid(t.valid)
{}

// Position

glm::vec2 Transform2D::getPosition() const
{
	return position;
}

float Transform2D::getPositionX() const
{
	return position.x;
}

float Transform2D::getPositionY() const
{
	return position.y;
}

void Transform2D::setPosition(glm::vec2 position)
{
	this->position = position;
	valid = false;
}

void Transform2D::setPosition(float x, float y)
{
	position = glm::vec2(x, y);
	valid = false;
}

void Transform2D::setPositionX(float x)
{
	position.x = x;
	valid = false;
}

void Transform2D::setPositionY(float y)
{
	position.y = y;
	valid = false;
}

// Origin

glm::vec2 Transform2D::getOrigin() const
{
	return origin;
}

float Transform2D::getOriginX() const
{
	return origin.x;
}

float Transform2D::getOriginY() const
{
	return origin.y;
}

void Transform2D::setOrigin(glm::vec2 origin)
{
	this->origin = origin;
	valid = false;
}

void Transform2D::setOrigin(float x, float y)
{
	this->origin = glm::vec2(x, y);
	valid = false;
}

void Transform2D::setOriginX(float x)
{
	origin.x = x;
	valid = false;
}

void Transform2D::setOriginY(float y)
{
	origin.y = y;
	valid = false;
}

// Size

glm::vec2 Transform2D::getSize() const
{
	return size;
}

float Transform2D::getSizeX() const
{
	return size.x;
}

float Transform2D::getSizeY() const
{
	return size.y;
}

void Transform2D::setSize(glm::vec2 size)
{
	this->size = size;
	valid = false;
}

void Transform2D::setSize(float x, float y)
{
	size = glm::vec2(x, y);
	valid = false;
}

void Transform2D::setSizeX(float x)
{
	size.x = x;
	valid = false;
}

void Transform2D::setSizeY(float y)
{
	size.y = y;
	valid = false;
}

// Rotation

float Transform2D::getRotation() const
{
	return rotation;
}

void Transform2D::setRotation(float rotation)
{
	this->rotation = rotation;
	valid = false;
}

// Miscellaneous

const glm::mat3& Transform2D::getMatrix() const
{
	/*
	if (valid) return matrix;
	valid = true;
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
	*/
	if (valid) return matrix;
	valid = true;
	float c = 0.5 * std::cos(rotation);
	float s = 0.5 * std::sin(rotation);
	glm::vec2 p = size - origin * glm::vec2(2.0);
	return matrix = glm::mat3(
		+ size.x * c, size.x * s, 0,
		- size.y * s, size.y * c, 0,
		c * p.x - s * p.y + position.x,
		s * p.x + c * p.y + position.y,
		1
	);
}

bool Transform2D::isInside(glm::vec2 point) const
{
	/*
	glm::vec3 a = getMatrix() * glm::vec3(-1, +1, 1);
	glm::vec3 b = getMatrix() * glm::vec3(+1, +1, 1);
	glm::vec3 d = getMatrix() * glm::vec3(-1, -1, 1);
	glm::vec2 AM = glm::vec2(a.x - point.x, a.y - point.y);
	glm::vec2 AB = glm::vec2(a.x - b.x, a.y - b.y);
	glm::vec2 AD = glm::vec2(a.x - d.x, a.y - d.y);
	float AMAB = AM.x * AB.x + AM.y * AB.y;
	float AMAD = AM.x * AD.x + AM.y * AD.y;
	float ABAB = AB.x * AB.x + AB.y * AB.y;
	float ADAD = AD.x * AD.x + AD.y * AD.y;
	if (AMAB < 0 || AMAB > ABAB) return false;
	if (AMAD < 0 || AMAD > ADAD) return false;
	return true;
	*/
	float c = std::cos(rotation);
	float s = std::sin(rotation);
	float e = c*c + s*s, t;
	point -= position;
	t = origin.x * e + c * point.x + s * point.y;
	if (t < 0 || t > size.x * e) return false;
	t = (size.y - origin.y) * e + c * (origin.x - origin.x * s - point.y) + s * point.x;
	if (t < 0 || t > size.y * e) return false;
	return true;
}

void Transform2D::setTransform(const Transform2D& t)
{
	position = t.position;
	origin = t.origin;
	size = t.size;
	rotation = t.rotation;
	matrix = t.matrix;
	valid = t.valid;
}
