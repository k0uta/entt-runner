#ifndef ENTT_RUNNER_SPRITE_RENDER_HPP
#define ENTT_RUNNER_SPRITE_RENDER_HPP

#include <entt/entt.hpp>
#include <SDL.h>
#include "../components/render.hpp"
#include "../components/transform.hpp"

void sprite_render(entt::registry &registry, SDL_Renderer *renderer, position camera_position);

#endif //ENTT_RUNNER_SPRITE_RENDER_HPP
