#include "Camera2D.hpp"
#include <cmath>

using namespace Render;

Camera2D::Camera2D(
	glm::vec2 center,
	glm::vec2 size,
	float rotation
)
: center(center)
, size(size)
, rotation(rotation)
, changed(true)
{}

Camera2D::Camera2D(const Camera2D& camera)
: center(camera.center)
, size(camera.size)
, rotation(camera.rotation)
, matrix(camera.matrix)
, changed(camera.changed)
{}

glm::vec2 Camera2D::getCenter() const
{
	return center;
}

glm::vec2 Camera2D::getSize() const
{
	return size;
}

float Camera2D::getRotation() const
{
	return rotation;
}

void Camera2D::setRotation(float rot)
{
	rotation = rot;
	changed = true;
}

void Camera2D::setCenter(glm::vec2 center)
{
	this->center = center;
	changed = true;
}

void Camera2D::setCenter(float x, float y)
{
	center = glm::vec2(x, y);
	changed = true;
}

void Camera2D::setSize(glm::vec2 size)
{
	this->size = size;
	changed = true;
}

void Camera2D::setSize(float x, float y)
{
	size = glm::vec2(x, y);
	changed = true;
}

glm::vec2 Camera2D::toWorld(glm::vec2 screen) const
{
	float c = std::cos(rotation);
	float s = std::sin(rotation);
	screen = center + size * (screen - glm::vec2(0.5));
	return glm::vec2(
		screen.x * c - screen.y * s,
		screen.y * c + screen.x * s
	);
}

/*glm::vec2 Camera2D::toScreen(glm::vec2 world) const
{
	
}*/

const glm::mat3& Camera2D::getMatrix() const
{
	if (!changed) return matrix;
	changed = false;
	float c = std::cos(-rotation);
	float s = std::sin(-rotation);
	float sx = + 1.0 / (0.5 * size.x);
	float sy = - 1.0 / (0.5 * size.y);
	float px = -center.x;
	float py = -center.y;
	glm::mat3 matScale(
		sx, 0,  0,
		0,  sy, 0,
		0,  0,  1
	);
	glm::mat3 matRotation(
		+c, +s, 0,
		-s, +c, 0,
		+0, +0, 1
	);
	glm::mat3 matTranslate(
		1,  0,  0,
		0,  1,  0,
		px, py, 1
	);
	return matrix = matScale * matRotation * matTranslate;
}
