#include "FrameBuffer.hpp"
#include "Exception.hpp"
#include "gles2.hpp"

using namespace GL;

FrameBuffer::FrameBuffer(
	const Texture* texture,
	const StencilBuffer* stencil,
	const DepthBuffer* depth
)
: ID(0)
, texture(texture)
, stencil(stencil)
, depth(depth)
{
	glGenFramebuffers(1, const_cast<unsigned int*>(&ID));
	if (ID <= 0) throw GL_EXCEPTION("Failed to generate frame buffer");
	
	glBindFramebuffer(GL_FRAMEBUFFER, ID);
	
	if (texture != nullptr) {
		glFramebufferTexture2D(
			GL_FRAMEBUFFER,
			GL_COLOR_ATTACHMENT0,
			GL_TEXTURE_2D,
			texture->ID,
			0
		);
	}
	
	if (stencil != nullptr) {
		glFramebufferRenderbuffer(
			GL_FRAMEBUFFER,
			GL_STENCIL_ATTACHMENT,
			GL_RENDERBUFFER,
			stencil->ID
		);
	}
	
	if (depth != nullptr) {
		glFramebufferRenderbuffer(
			GL_FRAMEBUFFER,
			GL_DEPTH_ATTACHMENT,
			GL_RENDERBUFFER,
			depth->ID
		);
	}
	
	GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
	if (status != GL_FRAMEBUFFER_COMPLETE) {
		std::string error;
		switch (status) {
		case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
			error = "Incomplete attachment";
			break;
		case GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS:
			error = "Invalid dimensions";
			break;
		case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
			error = "Missing attachment";
			break;
		case GL_FRAMEBUFFER_UNSUPPORTED:
			error = "Unsupported";
			break;
		default:
			error = std::to_string(status);
			break;
		}
		glDeleteFramebuffers(1, &ID);
		throw GL_EXCEPTION(std::string("Invalid frame buffer\n") + error);
	}
	
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	
	GL_THROW_IF_ERROR("Failed to create frame buffer");
}

FrameBuffer::~FrameBuffer()
{
	glDeleteFramebuffers(1, &ID);
}
