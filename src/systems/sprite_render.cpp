#include "sprite_render.hpp"

void sprite_render(entt::registry &registry, SDL_Renderer *renderer, position camera_position) {
    auto view = registry.view<sprite, position>();
    for (auto entity: view) {
        auto sprite_component = view.get<sprite>(entity);
        auto position_component = view.get<position>(entity);

        auto source_rect = sprite_component.source_rect;
        source_rect.x = (int) (position_component.x - camera_position.x);
        source_rect.y = (int) (position_component.y - camera_position.y);

        SDL_RenderCopy(renderer, sprite_component.texture, NULL, &source_rect);
    }
}