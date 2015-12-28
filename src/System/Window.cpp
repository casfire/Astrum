#include "Window.hpp"
#include "../GL/gles2.hpp"
#include "../GL/Exception.hpp"
#include "../GL/stb_image.h"

using namespace System;
using namespace GL;

Window::Window(
	const char* title,
	bool fullscreen,
	int samples
) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		throw GL_EXCEPTION(SDL_GetError());
	}
	
	SDL_GL_SetAttribute(
		SDL_GL_CONTEXT_PROFILE_MASK,
		SDL_GL_CONTEXT_PROFILE_ES
	);
	
	SDL_GL_SetAttribute(
		SDL_GL_CONTEXT_MAJOR_VERSION,
		2
	);
	
	SDL_GL_SetAttribute(
		SDL_GL_CONTEXT_MINOR_VERSION,
		0
	);
	
	SDL_GL_SetAttribute(
		SDL_GL_MULTISAMPLEBUFFERS,
		samples <= 0 ? 0 : 1
	);
	
	SDL_GL_SetAttribute(
		SDL_GL_MULTISAMPLESAMPLES,
		samples <= 0 ? 0 : samples
	);
	
	if (fullscreen) {
		window = SDL_CreateWindow(
			title,
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			0, 0,
			SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN_DESKTOP
		);
	} else {
		window = SDL_CreateWindow(
			title,
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			1136, 640,
			SDL_WINDOW_OPENGL
		);
	}
	
	if (!window) throw GL_EXCEPTION(SDL_GetError());
	SDL_GetWindowSize(window, &w, &h);
	context = SDL_GL_CreateContext(window);
	if (!context) throw GL_EXCEPTION(SDL_GetError());
	SDL_GL_MakeCurrent(window, context);
	glLoadFunctions(SDL_GL_GetProcAddress);
	
	int iconW, iconH, iconC;
	unsigned char* data = stbi_load("assets/icon.png", &iconW, &iconH, &iconC, 0);
	if (data == nullptr) return;
	SDL_Surface *icon = SDL_CreateRGBSurfaceFrom(
		data,
		iconW,
		iconH,
		iconC * 8,
		iconW * iconC,
		0x000000ff,
		0x0000ff00,
		0x00ff0000,
		0xff000000
	);
	if (icon == nullptr) {
		stbi_image_free(data);
		throw GL_EXCEPTION(SDL_GetError());
	}
	SDL_SetWindowIcon(window, icon);
	SDL_FreeSurface(icon);
	stbi_image_free(data);
}

Window::~Window()
{
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int Window::getHeight() const
{
	return h;
}

int Window::getWidth() const
{
	return w;
}

glm::ivec2 Window::getSize() const
{
	return glm::ivec2(w, h);
}

glm::vec2 Window::normalize(glm::ivec2 pos) const
{
	return glm::vec2(pos) / glm::vec2(w, h);
}

glm::vec2 Window::normalize(int x, int y) const
{
	return glm::vec2(x, y) / glm::vec2(w, h);
}

void Window::display() const
{
	SDL_GL_SwapWindow(const_cast<SDL_Window*>(window));
}

void Window::setVsync(float enabled) const
{
	SDL_GL_SetSwapInterval(enabled ? 1 : 0);
}
