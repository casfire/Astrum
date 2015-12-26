#include "StencilBuffer.hpp"
#include "Exception.hpp"
#include "gles2.hpp"

using namespace GL;

StencilBuffer::StencilBuffer(
	std::size_t width,
	std::size_t height
)
: ID(0)
, width(width)
, height(height)
{
	glGenRenderbuffers(1, const_cast<unsigned int*>(&ID));
	if (ID <= 0) throw GL_EXCEPTION("Failed to generate stencil buffer");
	
	glBindRenderbuffer(GL_RENDERBUFFER, ID);
	glRenderbufferStorage(
		GL_RENDERBUFFER,
		GL_STENCIL_INDEX8,
		width,
		height
	);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
	
	GL_THROW_IF_ERROR("Failed to create stencil buffer");
}

StencilBuffer::~StencilBuffer()
{
	glDeleteRenderbuffers(1, &ID);
}
