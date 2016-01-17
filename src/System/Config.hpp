#ifndef _CONFIG_
#define _CONFIG_

#include <sstream>
#include <string>
#include <map>

namespace System {
	
	class Config {
	public:
		
		void load(const std::string& file);
		void save(const std::string& file) const;
		void clear();
		
		std::stringstream& operator[](const std::string& key);
		const std::stringstream& operator[](const std::string& key) const;
		
	private:
		
		std::map<std::string, std::stringstream> config;
		
	};
	
}

#endif
