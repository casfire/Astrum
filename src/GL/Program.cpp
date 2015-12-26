#include "Program.hpp"
#include "Exception.hpp"
#include "gles2.hpp"
#include <vector>
#include <fstream>

using namespace GL;

Program::Program(
	const std::string& file
)
: ID(0)
, file(file)
{
	*const_cast<unsigned int*>(&ID) = glCreateProgram();
	if (ID <= 0) throw GL_EXCEPTION("Failed to generate program");
	
	std::ifstream streamV(file + ".vert", std::ios::binary);
	std::ifstream streamF(file + ".frag", std::ios::binary);
	
	bool failV = !streamV.is_open();
	bool failF = !streamF.is_open();
	
	if (failV || failF) {
		glDeleteProgram(ID);
		throw GL_EXCEPTION(
			(failV ? std::string("Shader ") + file + std::string(".vert doesn't exist") : std::string()) +
			(failV && failF ? std::string("\n") : std::string()) +
			(failF ? std::string("Shader ") + file + std::string(".frag doesn't exist") : std::string())
		);
	}
	
	streamV.seekg(0, std::ios_base::end);
	streamF.seekg(0, std::ios_base::end);
	
	std::streamsize sizeV = streamV.tellg();
	std::streamsize sizeF = streamF.tellg();
	
	streamV.seekg(0, std::ios_base::beg);
	streamF.seekg(0, std::ios_base::beg);
	
	std::vector<char> sourceV(sizeV + 1, '\0');
	std::vector<char> sourceF(sizeF + 1, '\0');
	
	streamV.read(sourceV.data(), sizeV);
	streamF.read(sourceF.data(), sizeF);
	
	failV = streamV.fail() || streamV.gcount() != sizeV;
	failF = streamF.fail() || streamF.gcount() != sizeF;
	
	if (failV || failF) {
		glDeleteProgram(ID);
		throw GL_EXCEPTION(
			(failV ? std::string("Failed to read ") + file + std::string(".vert") : std::string()) +
			(failV && failF ? std::string("\n") : std::string()) +
			(failF ? std::string("Failed to read ") + file + std::string(".frag") : std::string())
		);
	}
	
	GLuint v = glCreateShader(GL_VERTEX_SHADER);
	GLuint f = glCreateShader(GL_FRAGMENT_SHADER);
	
	if (v <= 0 || f <= 0) {
		glDeleteProgram(ID);
		throw GL_EXCEPTION("Failed to generate shaders");
	}
	
	const char* srcV = sourceV.data();
	const char* srcF = sourceF.data();
	
	GLint statusV = GL_FALSE;
	GLint statusF = GL_FALSE;
	
	glShaderSource(v, 1, &srcV, nullptr);
	glShaderSource(f, 1, &srcF, nullptr);
	
	glCompileShader(v);
	glCompileShader(f);
	
	glGetShaderiv(v, GL_COMPILE_STATUS, &statusV);
	glGetShaderiv(f, GL_COMPILE_STATUS, &statusF);
	
	failV = statusV != GL_TRUE;
	failF = statusF != GL_TRUE;
	
	if (failV || failF) {
		
		GLint sizeV = 0;
		GLint sizeF = 0;
		
		glGetShaderiv(v, GL_INFO_LOG_LENGTH, &sizeV);
		glGetShaderiv(f, GL_INFO_LOG_LENGTH, &sizeF);
		
		std::vector<char> bufV(sizeV, '\0');
		std::vector<char> bufF(sizeF, '\0');
		
		glGetShaderInfoLog(v, sizeV, nullptr, &bufV[0]);
		glGetShaderInfoLog(f, sizeF, nullptr, &bufF[0]);
		
		if (bufV.back() == '\0') bufV.pop_back();
		if (bufF.back() == '\0') bufF.pop_back();
		
		std::string logV(bufV.begin(), bufV.end());
		std::string logF(bufF.begin(), bufF.end());
		
		glDeleteProgram(ID);
		glDeleteShader(v);
		glDeleteShader(f);
		
		throw GL_EXCEPTION(
			(failV ? std::string("Failed to compile ") + file + std::string(".vert\n") + logV : std::string()) +
			(failV && failF ? std::string("\n") : std::string()) +
			(failF ? std::string("Failed to compile ") + file + std::string(".frag\n") + logF : std::string())
		);
		
	}
	
	glAttachShader(ID, v);
	glAttachShader(ID, f);
	
	glLinkProgram(ID);
	
	glDetachShader(ID, f);
	glDetachShader(ID, v);
	
	GLint status = GL_FALSE;
	glGetProgramiv(ID, GL_LINK_STATUS, &status);
	
	if (status != GL_TRUE) {
		
		std::string log = getProgramLog();
		
		glDeleteProgram(ID);
		glDeleteShader(v);
		glDeleteShader(f);
		
		if (log.empty()) {
			throw GL_EXCEPTION(
				std::string("Failed to link program ") +
				file
			);
		} else {
			throw GL_EXCEPTION(
				std::string("Failed to link program ") +
				file +
				std::string("\n") +
				log
			);
		}
		
	}
	
	GL_THROW_IF_ERROR(std::string("Failed to create program ") + file);
}

Program::~Program()
{
	glDeleteProgram(ID);
}

std::string Program::getProgramLog() const
{
	GLint size = 0;
	glGetProgramiv(ID, GL_INFO_LOG_LENGTH, &size);
	if (size > 0) {
		std::vector<char> buffer(size, '\0');
		glGetProgramInfoLog(ID, size, nullptr, &buffer[0]);
		if (buffer.back() == '\0') buffer.pop_back();
		return std::string(buffer.begin(), buffer.end());
	} else {
		return std::string();
	}
}

int Program::getUniform(const std::string& name)
{
	int loc = glGetUniformLocation(ID, name.c_str());
	if (loc < 0) {
		throw GL_EXCEPTION(
			"Uniform " + name + " doesn't exist in program " + file
		);
	}
	return loc;
}

int Program::getAttribute(const std::string& name)
{
	int loc = glGetAttribLocation(ID, name.c_str());
	if (loc < 0) {
		throw GL_EXCEPTION(
			"Attribute " + name + " doesn't exist in program " + file
		);
	}
	return loc;
}
