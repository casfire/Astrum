#include "VertexBuffer.hpp"
#include "Exception.hpp"
#include "gles2.hpp"

using namespace GL;

VertexBuffer::VertexBuffer(
	const float* data,
	std::size_t size,
	std::size_t count
)
: ID(0)
, size(size)
, count(count)
{
	glGenBuffers(1, const_cast<unsigned int*>(&ID));
	if (ID <= 0) throw GL_EXCEPTION("Failed to generate vertex buffer");
	
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size * count * sizeof(float), data, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	GL_THROW_IF_ERROR("Failed to create vertex buffer");
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &ID);
}
