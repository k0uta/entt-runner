#include <stb_image.h>
#include "sprite_load.hpp"

void sprite_load(entt::registry &registry, SDL_Renderer *renderer) {
    auto view = registry.view<sprite_loader>();
    for (auto entity : view) {
        if (registry.has<sprite>(entity)) {
            auto old_sprite = registry.get<sprite>(entity);
            SDL_DestroyTexture(old_sprite.texture);
            registry.remove<sprite>(entity);
        }

        sprite entity_sprite = create_sprite(renderer, registry.get<sprite_loader>(entity).filename);

        registry.remove<sprite_loader>(entity);
        registry.assign<sprite>(entity, entity_sprite);
    }
}

sprite create_sprite(SDL_Renderer *renderer, const char *filename) {
    int req_format = STBI_rgb_alpha;
    int width, height, orig_format;
    unsigned char *data = stbi_load(filename, &width, &height, &orig_format, req_format);
    if (data == nullptr) {
        SDL_Log("Loading image failed: %s", stbi_failure_reason());
        exit(1);
    }

    Uint32 rmask, gmask, bmask, amask;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    int shift = (req_format == STBI_rgb) ? 8 : 0;
    rmask = 0xff000000 >> shift;
    gmask = 0x00ff0000 >> shift;
    bmask = 0x0000ff00 >> shift;
    amask = 0x000000ff >> shift;
#else // little endian, like x86
    rmask = 0x000000ff;
    gmask = 0x0000ff00;
    bmask = 0x00ff0000;
    amask = 0xff000000;
#endif

    int depth = 32;
    int pitch = 4 * width;

    SDL_Surface *surface = SDL_CreateRGBSurfaceFrom((void *) data, width, height, depth, pitch,
                                                    rmask, gmask, bmask, amask);

    if (surface == nullptr) {
        SDL_Log("Creating surface failed: %s", SDL_GetError());
        stbi_image_free(data);
        exit(1);
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    // TODO: Use spritesheet and x, y, w, h from it
    SDL_Rect rect{0, 0, width, height};

    SDL_FreeSurface(surface);
    stbi_image_free(data);

    return sprite{texture, rect};
}
