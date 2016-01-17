#include <stdexcept>
#include <string>

#define Exception(msg) std::runtime_error( \
	std::string(__FILE__) +                \
	std::string(":") +                     \
	std::to_string(__LINE__) +             \
	std::string("\n") +                    \
	msg                                    \
)

#define GL_EXCEPTION Exception

#define GL_THROW_IF_ERROR(x) {            \
	GLenum e = glGetError();              \
	if (e != GL_NO_ERROR) {               \
		throw Exception(               \
			std::string(x) +              \
			std::string(": ") +           \
			std::string(glErrorString(e)) \
		);                                \
	}                                     \
}
