#ifndef _EXCEPTION_
#define _EXCEPTION_

#include <exception>
#include <string>

namespace GL {
	
	struct Exception : public std::exception {
		
		Exception(
			const char* msg,
			const char* file,
			long int line
		);
		
		Exception(
			const std::string& msg,
			const char* file,
			long int line
		);
		
		Exception(
			std::string&& msg,
			const char* file,
			long int line
		);
		
		const char* what() const throw();
		
		const std::string msg;
		const std::string full;
		const char* file;
		const long int line;
		
	};
	
	#define GL_EXCEPTION(x) Exception(x, __FILE__, __LINE__)
	#define GL_THROW_IF_ERROR(x) {            \
		GLenum e = glGetError();              \
		if (e != GL_NO_ERROR) {               \
			throw GL_EXCEPTION(               \
				std::string(x) +              \
				std::string(": ") +           \
				std::string(glErrorString(e)) \
			);                                \
		}                                     \
	}
	
}

#endif
