#include <stdexcept>
#include <string>

#define Exception(msg) std::runtime_error( \
	std::string(__FILE__) +                \
	std::string(":") +                     \
	std::to_string(__LINE__) +             \
	std::string("\n") +                    \
	msg                                    \
)
