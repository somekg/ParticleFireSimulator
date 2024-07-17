#include "ErrorInfo.h"
#include <SDL.h>

void ErrorInfo::CheckSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDLInit failed..." << endl;
    }
    else { cout << "SDLInit succeeded..." << endl; }
}
void ErrorInfo::CheckWindow(SDL_Window* window) {
    if (window == NULL) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        cout << "Window creation failed..." << endl;
    }
    else { cout << "Window creation succeeded..." << endl; }
}
void ErrorInfo::CheckRenderer(SDL_Window* window, SDL_Renderer* renderer) {
    if (renderer == NULL) {
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        cout << "Could not create renderer..." << endl;
    }
    else { cout << "Renderer creation succeeded..." << endl; }
}
void ErrorInfo::CheckTexture(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture) {
    if (texture == NULL) {
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyTexture(texture);
        cout << "Could not create texture..." << endl;
    }
    else { cout << "Texture creation succeeded..." << endl; }
}
