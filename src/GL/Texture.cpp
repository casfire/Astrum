#include "Texture.hpp"
#include "Exception.hpp"
#include "stb_image.h"
#include "gles2.hpp"

using namespace GL;

static const GLenum format[] = {
	GL_LUMINANCE,
	GL_LUMINANCE_ALPHA,
	GL_RGB,
	GL_RGBA,
};

static const GLenum wrap[] = {
	GL_REPEAT,
	GL_MIRRORED_REPEAT,
	GL_CLAMP_TO_EDGE,
};

static const GLenum minFilter[] = {
	GL_NEAREST,
	GL_LINEAR,
	GL_LINEAR_MIPMAP_LINEAR,
};

static const GLenum magFilter[] = {
	GL_NEAREST,
	GL_LINEAR,
	GL_LINEAR,
};

Texture::Texture(
	const std::string& file,
	Filter filter,
	Edge edge
)
: ID(0)
, width(0)
, height(0)
, channels(0)
{
	glGenTextures(1, const_cast<unsigned int*>(&ID));
	if (ID <= 0) throw GL_EXCEPTION("Failed to generate texture");
	
	int w, h, c;
	unsigned char* data = stbi_load(file.c_str(), &w, &h, &c, 0);
	if (data == nullptr) {
		glDeleteTextures(1, &ID);
		const char *error = stbi_failure_reason();
		throw GL_EXCEPTION(
			std::string("Failed to load ")
			+ file
			+ std::string("\n")
			+ std::string(error == nullptr ? "" : error)
		);
	}
	
	*const_cast<std::size_t*>(&width) = w;
	*const_cast<std::size_t*>(&height) = h;
	*const_cast<std::size_t*>(&channels) = c;
	
	GLint previous = 0;
	glGetIntegerv(GL_TEXTURE_BINDING_2D, &previous);
	glBindTexture(GL_TEXTURE_2D, ID);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(
		GL_TEXTURE_2D, 0, format[c - 1], w, h,
		0, format[c - 1], GL_UNSIGNED_BYTE, data
	);
	std::size_t f = static_cast<std::size_t>(filter);
	std::size_t e = static_cast<std::size_t>(edge);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap[e]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap[e]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter[f]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter[f]);
	if (f >= 2) glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, previous);
	
	stbi_image_free(data);
	
	GL_THROW_IF_ERROR(std::string("Failed to load ") + file);
}

Texture::Texture(
	std::size_t width,
	std::size_t height,
	std::size_t channels,
	Filter filter,
	Edge edge
)
: ID(0)
, width(width)
, height(height)
, channels(channels)
{
	glGenTextures(1, const_cast<unsigned int*>(&ID));
	if (ID <= 0) throw GL_EXCEPTION("Failed to generate texture");
	if (channels <= 0 || channels > 4) {
		glDeleteTextures(1, &ID);
		throw GL_EXCEPTION("Invalid number of channels");
	}
	
	GLint previous = 0;
	glGetIntegerv(GL_TEXTURE_BINDING_2D, &previous);
	glBindTexture(GL_TEXTURE_2D, ID);
	glTexImage2D(
		GL_TEXTURE_2D, 0, format[channels - 1], width, height,
		0, format[channels - 1], GL_UNSIGNED_BYTE, nullptr
	);
	std::size_t f = static_cast<std::size_t>(filter);
	std::size_t e = static_cast<std::size_t>(edge);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap[e]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap[e]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter[f]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter[f]);
	if (f > 2) glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, previous);
	
	GL_THROW_IF_ERROR("Failed to create texture");
}

Texture::~Texture()
{
	glDeleteTextures(1, &ID);
}

void Texture::bind(unsigned unit) const
{
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, ID);
}

unsigned Texture::MaxUnits()
{
	GLint max = 0;
	glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &max);
	return max;
}
