#ifndef ENTT_RUNNER_SPRITE_LOAD_HPP
#define ENTT_RUNNER_SPRITE_LOAD_HPP

#include <entt/entt.hpp>
#include <SDL.h>
#include "../components/render.hpp"

void sprite_load(entt::registry &registry, SDL_Renderer *renderer);

sprite create_sprite(SDL_Renderer *renderer, const char *filename);

#endif //ENTT_RUNNER_SPRITE_LOAD_HPP
