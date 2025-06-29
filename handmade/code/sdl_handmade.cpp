#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_video.h>

/* Constants */
constexpr int screenWidth{600};
constexpr int screenHeight{800};

/* Function Prototypes */
bool init(); // Startup + Win creation

void close(); // Frees media + shutdown SDL

/* Globals */
SDL_Window *win{nullptr};
SDL_Surface *screenSurface{nullptr};

/* Function Implementations */
bool init() {
    bool success{true};

    // Init SDL
    if (SDL_Init(SDL_INIT_VIDEO) == false) {
        SDL_Log("ERROR: SDL could not initialize! SDL Error: %s\n",
                SDL_GetError());
        success = false;
    } else {
        // Create Window
        win = SDL_CreateWindow("HandmadeHero", screenWidth, screenHeight, 0);
        if (win == nullptr) {
            SDL_Log("ERROR: SDL Window could not be created! SDL Error: %s\n",
                    SDL_GetError());
            success = false;
        } else {
            screenSurface = SDL_GetWindowSurface(win);
        }
    }

    return success;
}

void close() {

    // Destroy Win
    SDL_DestroyWindow(win);
    win = nullptr;
    screenSurface = nullptr;

    SDL_Quit();
}

int main(int argc, char **argv) {
    int status{0};

    if (init() == false) {
        SDL_Log("ERROR: Unable to initialize program!\n");
        status = 1;
    } else {
        // TODO: Load media here?

        bool quit{false};
        SDL_Event e;
        SDL_zero(e);

        while (quit == false) {
            while (SDL_PollEvent(&e) == true) {
                if (e.type == SDL_EVENT_QUIT) {
                    quit = true;
                }
            }

            SDL_FillSurfaceRect(
                screenSurface, nullptr,
                SDL_MapSurfaceRGB(screenSurface, 0x18, 0x18, 0x18));

            SDL_UpdateWindowSurface(win);
        }
    }

    close();

    return status;
}
