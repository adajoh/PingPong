
#include <SDL.h>
#include "PingPong.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* window;
SDL_Renderer* renderer;

void quit() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main(int argc, char* args[]) {
	
	PingPong pingPong;

	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;

	//SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		return -1;
	}

	//window
	window = SDL_CreateWindow("Retro", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
	if (window == NULL)
	{
		return -1;
	}

	//renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		return -1;
	}
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

	//Hide cursor
	SDL_ShowCursor(SDL_DISABLE);

	//Gameloop
	SDL_Event event;
	while (true)
	{
		//Events
		if (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				quit();
				return 0;
			}
		}
		const Uint8 *state = SDL_GetKeyboardState(NULL);
		if (state[SDL_SCANCODE_ESCAPE]) {
			quit();
			return 0;
		}

		//Delta
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		deltaTime = (double)((NOW - LAST) * 1000 / SDL_GetPerformanceFrequency());
		deltaTime *= 0.001;

		//Update screen
		pingPong.update(deltaTime);

		//Render current frame
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);
		pingPong.render(renderer);
		SDL_RenderPresent(renderer);

		//Delay?
		SDL_Delay(16);
	}

	return 0;
}