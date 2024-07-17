#pragma once

#include <iostream>
#include <SDL.h>
using namespace std;

class ErrorInfo
{
public:
	void CheckSDL();
	void CheckWindow(SDL_Window* window);
	void CheckRenderer(SDL_Window* window, SDL_Renderer* renderer);
	void CheckTexture(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture);
};

