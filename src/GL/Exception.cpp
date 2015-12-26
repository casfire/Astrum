#include "Exception.hpp"

using namespace GL;

Exception::Exception(
	const char* msg,
	const char* file,
	long int line
)
: msg(msg)
, full(
	std::string(file) +
	std::string(":") +
	std::to_string(line) +
	std::string("\n") +
	this->msg
  )
, file(file)
, line(line)
{}

Exception::Exception(
	const std::string& msg,
	const char* file,
	long int line
)
: msg(msg)
, full(
	std::string(file) +
	std::string(":") +
	std::to_string(line) +
	std::string("\n") +
	this->msg
  )
, file(file)
, line(line)
{}

Exception::Exception(
	std::string&& msg,
	const char* file,
	long int line
)
: msg(msg)
, full(
	std::string(file) +
	std::string(":") +
	std::to_string(line) +
	std::string("\n") +
	this->msg
  )
, file(file)
, line(line)
{}

const char* Exception::what() const throw()
{
	return full.c_str();
}
