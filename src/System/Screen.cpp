#include "Screen.hpp"
#include "../SDL/SDL.h"

using namespace System;

Screen::Screen(const Window& window)
: window(window)
, loop(false)
{}

void Screen::onPress(glm::vec2) {}
void Screen::onRelease(glm::vec2) {}
void Screen::onSlide(glm::vec2, glm::vec2) {}
void Screen::onInit() {}
void Screen::onExit() {}

void Screen::quit()
{
	loop = false;
}

static bool global_loop = true;

void Screen::run()
{
	loop = true;
	onInit();
	while (loop && global_loop) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				loop = false;
				global_loop = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT) {
					onPress(window.normalize(
						event.button.x,
						event.button.y
					));
				}
				break;
			case SDL_MOUSEBUTTONUP:
				if (event.button.button == SDL_BUTTON_LEFT) {
					onRelease(window.normalize(
						event.button.x,
						event.button.y
					));
				}
				break;
			case SDL_MOUSEMOTION:
				if (event.motion.state & SDL_BUTTON_LEFT) {
					onSlide(
						window.normalize(
							event.motion.x - event.motion.xrel,
							event.motion.y - event.motion.yrel
						),
						window.normalize(
							event.motion.x,
							event.motion.y
						)
					);
				}
				break;
			case SDL_FINGERDOWN:
				onPress(glm::vec2(event.tfinger.x, event.tfinger.y));
				break;
			case SDL_FINGERUP:
				onRelease(glm::vec2(event.tfinger.x, event.tfinger.y));
				break;
			case SDL_FINGERMOTION:
				onSlide(
					glm::vec2(
						event.tfinger.x - event.tfinger.dx,
						event.tfinger.y - event.tfinger.dy
					),
					glm::vec2(
						event.tfinger.x,
						event.tfinger.y
					)
				);
				break;
			};
		}
		onRender();
		window.display();
	}
	onExit();
}
