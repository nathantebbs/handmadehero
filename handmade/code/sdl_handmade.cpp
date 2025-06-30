#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_video.h>
#include <cstdio>

/* Constants */
constexpr int screenWidth{600};
constexpr int screenHeight{800};

/* Function Prototypes */
bool init(); // Startup + Win creation

void close(); // Frees media + shutdown SDL

/* Globals */
SDL_Window *win{nullptr};
SDL_Renderer *ren{nullptr};

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
        win = SDL_CreateWindow("HandmadeHero", screenWidth, screenHeight,
                               SDL_WINDOW_RESIZABLE);
        if (win == nullptr) {
            SDL_Log("ERROR: SDL Window could not be created! SDL Error: %s\n",
                    SDL_GetError());
            success = false;
        } else {
            ren = SDL_CreateRenderer(win, "opengl");
            if (ren == nullptr) {
                SDL_Log(
                    "ERROR: SDL Renderer could not be created! SDL ERROR: %s\n",
                    SDL_GetError());
            }
        }
    }

    return success;
}

void close() {
    // Destroy Renderer
    SDL_DestroyRenderer(ren);
    ren = nullptr;

    // Destroy Win
    SDL_DestroyWindow(win);
    win = nullptr;

    SDL_Quit();
}

int main(int argc, char **argv) {
    int status{0};

    if (init() == false) {
        SDL_Log("ERROR: Unable to initialize program!\n");
        status = 1;
    } else {
        bool quit{false};
        SDL_Event e;
        SDL_zero(e);

        while (quit == false) {
            while (SDL_PollEvent(&e) == true) {
                switch (e.type) {
                case SDL_EVENT_QUIT:
                    quit = true;
                    break;
                case SDL_EVENT_WINDOW_RESIZED:
                    printf("SDL_WINDOWEVENT_RESIZED (%d, %d)\n", e.window.data1,
                           e.window.data2);
                    // TODO: this isn't really flashing white the way I want
                    // when the window is resized
                    SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
                    break;
                }
            }

            SDL_SetRenderDrawColor(ren, 0x18, 0x18, 0x18, 0x18);
            SDL_RenderClear(ren);
            SDL_RenderPresent(ren);
        }
    }

    close();

    return status;
}
