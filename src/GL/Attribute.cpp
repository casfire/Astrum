#include "Attribute.hpp"
#include "Exception.hpp"

using namespace GL;

Attribute::Attribute(
	const VertexBuffer& buffer,
	std::size_t size,
	std::size_t offset
)
: buffer(buffer.ID)
, size(size)
, stride(buffer.size * sizeof(float))
, pointer(reinterpret_cast<const void*>(offset * sizeof(float)))
{
	if (size <= 0 || size > 4) {
		throw GL_EXCEPTION(
			std::string("Invalid attribute size\n") +
			std::to_string(size)
		);
	} else if (offset >= buffer.count) {
		throw GL_EXCEPTION(
			std::string("Invalid attribute offset\n") +
			std::to_string(offset) +
			std::string(" >= ") +
			std::to_string(buffer.size)
		);
	}
}
