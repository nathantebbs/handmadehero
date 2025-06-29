#include <SDL3/SDL.h>
#include <SDL3/SDL_messagebox.h>
#include <stdio.h>

auto main(int argc, char *argv[]) -> int {

    printf("Hello, World\n");

    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Handmade Hero",
                             "Handmade Hello!", 0);

    return 0;
}
