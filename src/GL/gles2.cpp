#include "gles2.hpp"
#include <stdexcept>

#ifdef _WIN32
	#define WIN32_LEAN_AND_MEAN 1
	#include <windows.h>
#else
	#include <dlfcn.h>
	#define HMODULE void*
	#define GetProcAddress dlsym
	#define FreeLibrary dlclose
#endif

namespace GL {
	
	void (*glActiveTexture)(GLenum texture) = nullptr;
	void (*glAttachShader)(GLuint program, GLuint shader) = nullptr;
	void (*glBindAttribLocation)(GLuint program, GLuint index, const GLchar *name) = nullptr;
	void (*glBindBuffer)(GLenum target, GLuint buffer) = nullptr;
	void (*glBindFramebuffer)(GLenum target, GLuint framebuffer) = nullptr;
	void (*glBindRenderbuffer)(GLenum target, GLuint renderbuffer) = nullptr;
	void (*glBindTexture)(GLenum target, GLuint texture) = nullptr;
	void (*glBlendColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) = nullptr;
	void (*glBlendEquation)(GLenum mode) = nullptr;
	void (*glBlendEquationSeparate)(GLenum modeRGB, GLenum modeAlpha) = nullptr;
	void (*glBlendFunc)(GLenum sfactor, GLenum dfactor) = nullptr;
	void (*glBlendFuncSeparate)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) = nullptr;
	void (*glBufferData)(GLenum target, GLsizeiptr size, const void *data, GLenum usage) = nullptr;
	void (*glBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, const void *data) = nullptr;
	GLenum (*glCheckFramebufferStatus)(GLenum target) = nullptr;
	void (*glClear)(GLbitfield mask) = nullptr;
	void (*glClearColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) = nullptr;
	void (*glClearDepthf)(GLfloat d) = nullptr;
	void (*glClearStencil)(GLint s) = nullptr;
	void (*glColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) = nullptr;
	void (*glCompileShader)(GLuint shader) = nullptr;
	void (*glCompressedTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data) = nullptr;
	void (*glCompressedTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) = nullptr;
	void (*glCopyTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) = nullptr;
	void (*glCopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) = nullptr;
	GLuint (*glCreateProgram)() = nullptr;
	GLuint (*glCreateShader)(GLenum type) = nullptr;
	void (*glCullFace)(GLenum mode) = nullptr;
	void (*glDeleteBuffers)(GLsizei n, const GLuint *buffers) = nullptr;
	void (*glDeleteFramebuffers)(GLsizei n, const GLuint *framebuffers) = nullptr;
	void (*glDeleteProgram)(GLuint program) = nullptr;
	void (*glDeleteRenderbuffers)(GLsizei n, const GLuint *renderbuffers) = nullptr;
	void (*glDeleteShader)(GLuint shader) = nullptr;
	void (*glDeleteTextures)(GLsizei n, const GLuint *textures) = nullptr;
	void (*glDepthFunc)(GLenum func) = nullptr;
	void (*glDepthMask)(GLboolean flag) = nullptr;
	void (*glDepthRangef)(GLfloat n, GLfloat f) = nullptr;
	void (*glDetachShader)(GLuint program, GLuint shader) = nullptr;
	void (*glDisable)(GLenum cap) = nullptr;
	void (*glDisableVertexAttribArray)(GLuint index) = nullptr;
	void (*glDrawArrays)(GLenum mode, GLint first, GLsizei count) = nullptr;
	void (*glDrawElements)(GLenum mode, GLsizei count, GLenum type, const void *indices) = nullptr;
	void (*glEnable)(GLenum cap) = nullptr;
	void (*glEnableVertexAttribArray)(GLuint index) = nullptr;
	void (*glFinish)() = nullptr;
	void (*glFlush)() = nullptr;
	void (*glFramebufferRenderbuffer)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) = nullptr;
	void (*glFramebufferTexture2D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) = nullptr;
	void (*glFrontFace)(GLenum mode) = nullptr;
	void (*glGenBuffers)(GLsizei n, GLuint *buffers) = nullptr;
	void (*glGenFramebuffers)(GLsizei n, GLuint *framebuffers) = nullptr;
	void (*glGenRenderbuffers)(GLsizei n, GLuint *renderbuffers) = nullptr;
	void (*glGenTextures)(GLsizei n, GLuint *textures) = nullptr;
	void (*glGenerateMipmap)(GLenum target) = nullptr;
	void (*glGetActiveAttrib)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) = nullptr;
	void (*glGetActiveUniform)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) = nullptr;
	void (*glGetAttachedShaders)(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders) = nullptr;
	GLint (*glGetAttribLocation)(GLuint program, const GLchar *name) = nullptr;
	void (*glGetBooleanv)(GLenum pname, GLboolean *data) = nullptr;
	void (*glGetBufferParameteriv)(GLenum target, GLenum pname, GLint *params) = nullptr;
	GLenum (*glGetError)() = nullptr;
	void (*glGetFloatv)(GLenum pname, GLfloat *data) = nullptr;
	void (*glGetFramebufferAttachmentParameteriv)(GLenum target, GLenum attachment, GLenum pname, GLint *params) = nullptr;
	void (*glGetIntegerv)(GLenum pname, GLint *data) = nullptr;
	void (*glGetProgramInfoLog)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog) = nullptr;
	void (*glGetProgramiv)(GLuint program, GLenum pname, GLint *params) = nullptr;
	void (*glGetRenderbufferParameteriv)(GLenum target, GLenum pname, GLint *params) = nullptr;
	void (*glGetShaderInfoLog)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog) = nullptr;
	void (*glGetShaderPrecisionFormat)(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision) = nullptr;
	void (*glGetShaderSource)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source) = nullptr;
	void (*glGetShaderiv)(GLuint shader, GLenum pname, GLint *params) = nullptr;
	const GLubyte *(*glGetString)(GLenum name) = nullptr;
	void (*glGetTexParameterfv)(GLenum target, GLenum pname, GLfloat *params) = nullptr;
	void (*glGetTexParameteriv)(GLenum target, GLenum pname, GLint *params) = nullptr;
	GLint (*glGetUniformLocation)(GLuint program, const GLchar *name) = nullptr;
	void (*glGetUniformfv)(GLuint program, GLint location, GLfloat *params) = nullptr;
	void (*glGetUniformiv)(GLuint program, GLint location, GLint *params) = nullptr;
	void (*glGetVertexAttribPointerv)(GLuint index, GLenum pname, void **pointer) = nullptr;
	void (*glGetVertexAttribfv)(GLuint index, GLenum pname, GLfloat *params) = nullptr;
	void (*glGetVertexAttribiv)(GLuint index, GLenum pname, GLint *params) = nullptr;
	void (*glHint)(GLenum target, GLenum mode) = nullptr;
	GLboolean (*glIsBuffer)(GLuint buffer) = nullptr;
	GLboolean (*glIsEnabled)(GLenum cap) = nullptr;
	GLboolean (*glIsFramebuffer)(GLuint framebuffer) = nullptr;
	GLboolean (*glIsProgram)(GLuint program) = nullptr;
	GLboolean (*glIsRenderbuffer)(GLuint renderbuffer) = nullptr;
	GLboolean (*glIsShader)(GLuint shader) = nullptr;
	GLboolean (*glIsTexture)(GLuint texture) = nullptr;
	void (*glLineWidth)(GLfloat width) = nullptr;
	void (*glLinkProgram)(GLuint program) = nullptr;
	void (*glPixelStorei)(GLenum pname, GLint param) = nullptr;
	void (*glPolygonOffset)(GLfloat factor, GLfloat units) = nullptr;
	void (*glReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels) = nullptr;
	void (*glReleaseShaderCompiler)() = nullptr;
	void (*glRenderbufferStorage)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) = nullptr;
	void (*glSampleCoverage)(GLfloat value, GLboolean invert) = nullptr;
	void (*glScissor)(GLint x, GLint y, GLsizei width, GLsizei height) = nullptr;
	void (*glShaderBinary)(GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length) = nullptr;
	void (*glShaderSource)(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length) = nullptr;
	void (*glStencilFunc)(GLenum func, GLint ref, GLuint mask) = nullptr;
	void (*glStencilFuncSeparate)(GLenum face, GLenum func, GLint ref, GLuint mask) = nullptr;
	void (*glStencilMask)(GLuint mask) = nullptr;
	void (*glStencilMaskSeparate)(GLenum face, GLuint mask) = nullptr;
	void (*glStencilOp)(GLenum fail, GLenum zfail, GLenum zpass) = nullptr;
	void (*glStencilOpSeparate)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) = nullptr;
	void (*glTexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels) = nullptr;
	void (*glTexParameterf)(GLenum target, GLenum pname, GLfloat param) = nullptr;
	void (*glTexParameterfv)(GLenum target, GLenum pname, const GLfloat *params) = nullptr;
	void (*glTexParameteri)(GLenum target, GLenum pname, GLint param) = nullptr;
	void (*glTexParameteriv)(GLenum target, GLenum pname, const GLint *params) = nullptr;
	void (*glTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) = nullptr;
	void (*glUniform1f)(GLint location, GLfloat v0) = nullptr;
	void (*glUniform1fv)(GLint location, GLsizei count, const GLfloat *value) = nullptr;
	void (*glUniform1i)(GLint location, GLint v0) = nullptr;
	void (*glUniform1iv)(GLint location, GLsizei count, const GLint *value) = nullptr;
	void (*glUniform2f)(GLint location, GLfloat v0, GLfloat v1) = nullptr;
	void (*glUniform2fv)(GLint location, GLsizei count, const GLfloat *value) = nullptr;
	void (*glUniform2i)(GLint location, GLint v0, GLint v1) = nullptr;
	void (*glUniform2iv)(GLint location, GLsizei count, const GLint *value) = nullptr;
	void (*glUniform3f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) = nullptr;
	void (*glUniform3fv)(GLint location, GLsizei count, const GLfloat *value) = nullptr;
	void (*glUniform3i)(GLint location, GLint v0, GLint v1, GLint v2) = nullptr;
	void (*glUniform3iv)(GLint location, GLsizei count, const GLint *value) = nullptr;
	void (*glUniform4f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) = nullptr;
	void (*glUniform4fv)(GLint location, GLsizei count, const GLfloat *value) = nullptr;
	void (*glUniform4i)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) = nullptr;
	void (*glUniform4iv)(GLint location, GLsizei count, const GLint *value) = nullptr;
	void (*glUniformMatrix2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
	void (*glUniformMatrix3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
	void (*glUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
	void (*glUseProgram)(GLuint program) = nullptr;
	void (*glValidateProgram)(GLuint program) = nullptr;
	void (*glVertexAttrib1f)(GLuint index, GLfloat x) = nullptr;
	void (*glVertexAttrib1fv)(GLuint index, const GLfloat *v) = nullptr;
	void (*glVertexAttrib2f)(GLuint index, GLfloat x, GLfloat y) = nullptr;
	void (*glVertexAttrib2fv)(GLuint index, const GLfloat *v) = nullptr;
	void (*glVertexAttrib3f)(GLuint index, GLfloat x, GLfloat y, GLfloat z) = nullptr;
	void (*glVertexAttrib3fv)(GLuint index, const GLfloat *v) = nullptr;
	void (*glVertexAttrib4f)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) = nullptr;
	void (*glVertexAttrib4fv)(GLuint index, const GLfloat *v) = nullptr;
	void (*glVertexAttribPointer)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) = nullptr;
	void (*glViewport)(GLint x, GLint y, GLsizei width, GLsizei height) = nullptr;
	
	HMODULE lib = nullptr;
	GLFunctionLoader wgl = nullptr;
	
	void* lGetProcAddress(const char* name) {
		void* ret = wgl == nullptr ? nullptr : wgl(name);
		return ret == nullptr ? reinterpret_cast<void*>(GetProcAddress(lib, name)) : ret;
	}
	
	void glLoadFunctions() {
		#if defined(_WIN32)
			lib = LoadLibraryA("opengl32.dll");
			if (lib == nullptr) throw std::runtime_error("OpenGL library not found");
			wgl = reinterpret_cast<GLFunctionLoader>(GetProcAddress(lib, "wglGetProcAddress"));
		#elif defined(__APPLE__)
			lib = dlopen("../Frameworks/OpenGL.framework/OpenGL", RTLD_NOW | RTLD_GLOBAL);
			if (lib == nullptr) lib = dlopen("/Library/Frameworks/OpenGL.framework/OpenGL", RTLD_NOW | RTLD_GLOBAL);
			if (lib == nullptr) lib = dlopen("/System/Library/Frameworks/OpenGL.framework/OpenGL", RTLD_NOW | RTLD_GLOBAL);
			if (lib == nullptr) lib = dlopen("/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL", RTLD_NOW | RTLD_GLOBAL);
			if (lib == nullptr) throw std::runtime_error("OpenGL library not found");
		#else
			lib = dlopen("libGL.so.1", RTLD_NOW | RTLD_GLOBAL);
			if (lib == nullptr) lib = dlopen("libGL.so", RTLD_NOW | RTLD_GLOBAL);
			if (lib == nullptr) throw std::runtime_error("OpenGL library not found");
			wgl = reinterpret_cast<GLFunctionLoader>(dlsym(lib, "glXGetProcAddressARB"));
		#endif
		try {
			glLoadFunctions(&lGetProcAddress);
		} catch (...) {
			FreeLibrary(lib);
			lib = nullptr;
			wgl = nullptr;
			throw;
		}
		FreeLibrary(lib);
		lib = nullptr;
		wgl = nullptr;
	}
	
	template <typename Fn>
	inline void Load(Fn &f, const GLFunctionLoader &load, const char* name) {
		f = reinterpret_cast<Fn>(load(name));
		if (!f) throw std::runtime_error(name);
	};
	
	void glLoadFunctions(const GLFunctionLoader &load) {
		Load(glActiveTexture, load, "glActiveTexture");
		Load(glAttachShader, load, "glAttachShader");
		Load(glBindAttribLocation, load, "glBindAttribLocation");
		Load(glBindBuffer, load, "glBindBuffer");
		Load(glBindFramebuffer, load, "glBindFramebuffer");
		Load(glBindRenderbuffer, load, "glBindRenderbuffer");
		Load(glBindTexture, load, "glBindTexture");
		Load(glBlendColor, load, "glBlendColor");
		Load(glBlendEquation, load, "glBlendEquation");
		Load(glBlendEquationSeparate, load, "glBlendEquationSeparate");
		Load(glBlendFunc, load, "glBlendFunc");
		Load(glBlendFuncSeparate, load, "glBlendFuncSeparate");
		Load(glBufferData, load, "glBufferData");
		Load(glBufferSubData, load, "glBufferSubData");
		Load(glCheckFramebufferStatus, load, "glCheckFramebufferStatus");
		Load(glClear, load, "glClear");
		Load(glClearColor, load, "glClearColor");
		Load(glClearDepthf, load, "glClearDepthf");
		Load(glClearStencil, load, "glClearStencil");
		Load(glColorMask, load, "glColorMask");
		Load(glCompileShader, load, "glCompileShader");
		Load(glCompressedTexImage2D, load, "glCompressedTexImage2D");
		Load(glCompressedTexSubImage2D, load, "glCompressedTexSubImage2D");
		Load(glCopyTexImage2D, load, "glCopyTexImage2D");
		Load(glCopyTexSubImage2D, load, "glCopyTexSubImage2D");
		Load(glCreateProgram, load, "glCreateProgram");
		Load(glCreateShader, load, "glCreateShader");
		Load(glCullFace, load, "glCullFace");
		Load(glDeleteBuffers, load, "glDeleteBuffers");
		Load(glDeleteFramebuffers, load, "glDeleteFramebuffers");
		Load(glDeleteProgram, load, "glDeleteProgram");
		Load(glDeleteRenderbuffers, load, "glDeleteRenderbuffers");
		Load(glDeleteShader, load, "glDeleteShader");
		Load(glDeleteTextures, load, "glDeleteTextures");
		Load(glDepthFunc, load, "glDepthFunc");
		Load(glDepthMask, load, "glDepthMask");
		Load(glDepthRangef, load, "glDepthRangef");
		Load(glDetachShader, load, "glDetachShader");
		Load(glDisable, load, "glDisable");
		Load(glDisableVertexAttribArray, load, "glDisableVertexAttribArray");
		Load(glDrawArrays, load, "glDrawArrays");
		Load(glDrawElements, load, "glDrawElements");
		Load(glEnable, load, "glEnable");
		Load(glEnableVertexAttribArray, load, "glEnableVertexAttribArray");
		Load(glFinish, load, "glFinish");
		Load(glFlush, load, "glFlush");
		Load(glFramebufferRenderbuffer, load, "glFramebufferRenderbuffer");
		Load(glFramebufferTexture2D, load, "glFramebufferTexture2D");
		Load(glFrontFace, load, "glFrontFace");
		Load(glGenBuffers, load, "glGenBuffers");
		Load(glGenFramebuffers, load, "glGenFramebuffers");
		Load(glGenRenderbuffers, load, "glGenRenderbuffers");
		Load(glGenTextures, load, "glGenTextures");
		Load(glGenerateMipmap, load, "glGenerateMipmap");
		Load(glGetActiveAttrib, load, "glGetActiveAttrib");
		Load(glGetActiveUniform, load, "glGetActiveUniform");
		Load(glGetAttachedShaders, load, "glGetAttachedShaders");
		Load(glGetAttribLocation, load, "glGetAttribLocation");
		Load(glGetBooleanv, load, "glGetBooleanv");
		Load(glGetBufferParameteriv, load, "glGetBufferParameteriv");
		Load(glGetError, load, "glGetError");
		Load(glGetFloatv, load, "glGetFloatv");
		Load(glGetFramebufferAttachmentParameteriv, load, "glGetFramebufferAttachmentParameteriv");
		Load(glGetIntegerv, load, "glGetIntegerv");
		Load(glGetProgramInfoLog, load, "glGetProgramInfoLog");
		Load(glGetProgramiv, load, "glGetProgramiv");
		Load(glGetRenderbufferParameteriv, load, "glGetRenderbufferParameteriv");
		Load(glGetShaderInfoLog, load, "glGetShaderInfoLog");
		Load(glGetShaderPrecisionFormat, load, "glGetShaderPrecisionFormat");
		Load(glGetShaderSource, load, "glGetShaderSource");
		Load(glGetShaderiv, load, "glGetShaderiv");
		Load(glGetString, load, "glGetString");
		Load(glGetTexParameterfv, load, "glGetTexParameterfv");
		Load(glGetTexParameteriv, load, "glGetTexParameteriv");
		Load(glGetUniformLocation, load, "glGetUniformLocation");
		Load(glGetUniformfv, load, "glGetUniformfv");
		Load(glGetUniformiv, load, "glGetUniformiv");
		Load(glGetVertexAttribPointerv, load, "glGetVertexAttribPointerv");
		Load(glGetVertexAttribfv, load, "glGetVertexAttribfv");
		Load(glGetVertexAttribiv, load, "glGetVertexAttribiv");
		Load(glHint, load, "glHint");
		Load(glIsBuffer, load, "glIsBuffer");
		Load(glIsEnabled, load, "glIsEnabled");
		Load(glIsFramebuffer, load, "glIsFramebuffer");
		Load(glIsProgram, load, "glIsProgram");
		Load(glIsRenderbuffer, load, "glIsRenderbuffer");
		Load(glIsShader, load, "glIsShader");
		Load(glIsTexture, load, "glIsTexture");
		Load(glLineWidth, load, "glLineWidth");
		Load(glLinkProgram, load, "glLinkProgram");
		Load(glPixelStorei, load, "glPixelStorei");
		Load(glPolygonOffset, load, "glPolygonOffset");
		Load(glReadPixels, load, "glReadPixels");
		Load(glReleaseShaderCompiler, load, "glReleaseShaderCompiler");
		Load(glRenderbufferStorage, load, "glRenderbufferStorage");
		Load(glSampleCoverage, load, "glSampleCoverage");
		Load(glScissor, load, "glScissor");
		Load(glShaderBinary, load, "glShaderBinary");
		Load(glShaderSource, load, "glShaderSource");
		Load(glStencilFunc, load, "glStencilFunc");
		Load(glStencilFuncSeparate, load, "glStencilFuncSeparate");
		Load(glStencilMask, load, "glStencilMask");
		Load(glStencilMaskSeparate, load, "glStencilMaskSeparate");
		Load(glStencilOp, load, "glStencilOp");
		Load(glStencilOpSeparate, load, "glStencilOpSeparate");
		Load(glTexImage2D, load, "glTexImage2D");
		Load(glTexParameterf, load, "glTexParameterf");
		Load(glTexParameterfv, load, "glTexParameterfv");
		Load(glTexParameteri, load, "glTexParameteri");
		Load(glTexParameteriv, load, "glTexParameteriv");
		Load(glTexSubImage2D, load, "glTexSubImage2D");
		Load(glUniform1f, load, "glUniform1f");
		Load(glUniform1fv, load, "glUniform1fv");
		Load(glUniform1i, load, "glUniform1i");
		Load(glUniform1iv, load, "glUniform1iv");
		Load(glUniform2f, load, "glUniform2f");
		Load(glUniform2fv, load, "glUniform2fv");
		Load(glUniform2i, load, "glUniform2i");
		Load(glUniform2iv, load, "glUniform2iv");
		Load(glUniform3f, load, "glUniform3f");
		Load(glUniform3fv, load, "glUniform3fv");
		Load(glUniform3i, load, "glUniform3i");
		Load(glUniform3iv, load, "glUniform3iv");
		Load(glUniform4f, load, "glUniform4f");
		Load(glUniform4fv, load, "glUniform4fv");
		Load(glUniform4i, load, "glUniform4i");
		Load(glUniform4iv, load, "glUniform4iv");
		Load(glUniformMatrix2fv, load, "glUniformMatrix2fv");
		Load(glUniformMatrix3fv, load, "glUniformMatrix3fv");
		Load(glUniformMatrix4fv, load, "glUniformMatrix4fv");
		Load(glUseProgram, load, "glUseProgram");
		Load(glValidateProgram, load, "glValidateProgram");
		Load(glVertexAttrib1f, load, "glVertexAttrib1f");
		Load(glVertexAttrib1fv, load, "glVertexAttrib1fv");
		Load(glVertexAttrib2f, load, "glVertexAttrib2f");
		Load(glVertexAttrib2fv, load, "glVertexAttrib2fv");
		Load(glVertexAttrib3f, load, "glVertexAttrib3f");
		Load(glVertexAttrib3fv, load, "glVertexAttrib3fv");
		Load(glVertexAttrib4f, load, "glVertexAttrib4f");
		Load(glVertexAttrib4fv, load, "glVertexAttrib4fv");
		Load(glVertexAttribPointer, load, "glVertexAttribPointer");
		Load(glViewport, load, "glViewport");
	}
	
	const char* glErrorString(GLuint error) {
		switch (error) {
		case GL_NO_ERROR:
			return "No error";
		case GL_INVALID_ENUM:
			return "Invalid enum";
		case GL_INVALID_VALUE:
			return "Invalid value";
		case GL_INVALID_OPERATION:
			return "Invalid operation";
		case GL_INVALID_FRAMEBUFFER_OPERATION:
			return "Invalid frame buffer operation";
		case GL_OUT_OF_MEMORY:
			return "Out of memory";
		default:
			return "Unknown error";
		}
	}
	
}
