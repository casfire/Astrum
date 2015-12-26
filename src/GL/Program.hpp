#ifndef _PROGRAM_
#define _PROGRAM_

#include <string>

namespace GL {
	
	class Program {
	public:
		
		Program(const std::string& file);
		~Program();
		
		const unsigned int ID;
		const std::string file;
		
		std::string getProgramLog() const;
		int getUniform  (const std::string& name);
		int getAttribute(const std::string& name);
		
	private:
		
		Program(const Program&) = delete;
		Program& operator=(const Program&) = delete;
		
	};
	
}

#endif
