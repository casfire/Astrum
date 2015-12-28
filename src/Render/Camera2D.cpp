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
, valid(false)
{}

Camera2D::Camera2D(const Camera2D& camera)
: center(camera.center)
, size(camera.size)
, rotation(camera.rotation)
, matrix(camera.matrix)
, valid(camera.valid)
{}

// Center

glm::vec2 Camera2D::getCenter() const
{
	return center;
}

float Camera2D::getCenterX() const
{
	return center.x;
}

float Camera2D::getCenterY() const
{
	return center.y;
}

void Camera2D::setCenter(glm::vec2 center)
{
	this->center = center;
}

void Camera2D::setCenter(float x, float y)
{
	this->center = glm::vec2(x, y);
}

void Camera2D::setCenterX(float x)
{
	center.x = x;
}

void Camera2D::setCenterY(float y)
{
	center.y = y;
}

// Size

glm::vec2 Camera2D::getSize() const
{
	return size;
}

float Camera2D::getSizeX() const
{
	return size.x;
}

float Camera2D::getSizeY() const
{
	return size.y;
}

void Camera2D::setSize(glm::vec2 size)
{
	this->size = size;
}

void Camera2D::setSize(float x, float y)
{
	size = glm::vec2(x, y);
}

void Camera2D::setSizeX(float x)
{
	size.x = x;
}

void Camera2D::setSizeY(float y)
{
	size.y = y;
}

// Rotation

float Camera2D::getRotation() const
{
	return rotation;
}

void Camera2D::setRotation(float rotation)
{
	this->rotation = rotation;
}

// Point translation

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

glm::vec2 Camera2D::toScreen(glm::vec2 world) const
{
	float c = std::cos(-rotation);
	float s = std::sin(-rotation);
	world = glm::vec2(
		world.x * c - world.y * s,
		world.y * c + world.x * s
	);
	return glm::vec2(0.5) * ((size + world - center) / size);
}

// Miscellaneous

const glm::mat3& Camera2D::getMatrix() const
{
	/*
	if (valid) return matrix;
	valid = true;
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
	*/
	if (valid) return matrix;
	valid = true;
	float c = 2.0 * std::cos(-rotation);
	float s = 2.0 * std::sin(-rotation);
	return matrix = glm::mat3(
		+ c / size.x, - s / size.y, 0,
		- s / size.x, - c / size.y, 0,
		(s * center.y - c * center.x) / size.x,
		(c * center.y + s * center.x) / size.y,
		1
	);
}

void Camera2D::setCamera(const Camera2D& camera)
{
	center = camera.center;
	size = camera.size;
	rotation = camera.rotation;
	matrix = camera.matrix;
	valid = camera.valid;
}
