#ifndef ENTT_RUNNER_RENDER_HPP
#define ENTT_RUNNER_RENDER_HPP

#include <SDL.h>

struct sprite_loader {
    const char *filename;
};

struct sprite {
    SDL_Texture *texture;
    SDL_Rect source_rect;
};

#endif //ENTT_RUNNER_RENDER_HPP
