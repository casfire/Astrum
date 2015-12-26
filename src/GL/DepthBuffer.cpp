#include "DepthBuffer.hpp"
#include "Exception.hpp"
#include "gles2.hpp"

using namespace GL;

DepthBuffer::DepthBuffer(
	std::size_t width,
	std::size_t height
)
: ID(0)
, width(width)
, height(height)
{
	glGenRenderbuffers(1, const_cast<unsigned int*>(&ID));
	if (ID <= 0) throw GL_EXCEPTION("Failed to generate depth buffer");
	
	glBindRenderbuffer(GL_RENDERBUFFER, ID);
	glRenderbufferStorage(
		GL_RENDERBUFFER,
		GL_DEPTH_COMPONENT16,
		width,
		height
	);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
	
	GL_THROW_IF_ERROR("Failed to create depth buffer");
}

DepthBuffer::~DepthBuffer()
{
	glDeleteRenderbuffers(1, &ID);
}
