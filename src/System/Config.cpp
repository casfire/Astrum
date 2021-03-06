#include "Config.hpp"
#include "Exception.hpp"
#include <fstream>
#include <cstddef>

using namespace System;

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
	for (std::size_t s = 0; (s = str.find(from, s)) != std::string::npos; s += to.length())
		str.replace(s, from.length(), to);
}

void Config::load(const std::string& file)
{
	std::ifstream stream(file);
	if (!stream.good()) throw Exception(std::string("Failed to open config ") + file);
	config.clear();
	for (std::string line; std::getline(stream, line);) {
		std::size_t i = 1;
		for (;i < line.length(); i++) if (line[i] == '=' && line[i-1] != '\\') break;
		if (i >= line.length()) continue;
		std::string key = line.substr(0, i);
		std::string obj = line.substr(i+1);
		replaceAll(key, "\\n" , "\n");
		replaceAll(key, "\\=" , "=" );
		replaceAll(key, "\\\\", "\\");
		replaceAll(obj, "\\n" , "\n");
		replaceAll(obj, "\\=" , "=" );
		replaceAll(obj, "\\\\", "\\");
		config[key] = std::stringstream(obj);
	}
}

void Config::save(const std::string& file) const
{
	std::ofstream stream(file);
	if (!stream.good()) throw Exception(std::string("Failed to open config ") + file);
	for (const auto& p : config) {
		std::string key = p.first;
		std::string obj = p.second.str();
		if (obj.empty()) continue;
		replaceAll(key, "\\", "\\\\");
		replaceAll(key, "=" , "\\=" );
		replaceAll(key, "\n", "\\n" );
		replaceAll(obj, "\\", "\\\\");
		replaceAll(obj, "=" , "\\=" );
		replaceAll(obj, "\n", "\\n" );
		stream << key << "=" << obj << std::endl;
	}
	if (!stream.good()) throw Exception(std::string("Failed to write config ") + file);
}

void Config::clear()
{
	config.clear();
}

std::stringstream& Config::operator[](const std::string& key)
{
	return config[key];
}

const std::stringstream& Config::operator[](const std::string& key) const
{
	return config.find(key)->second;
}
