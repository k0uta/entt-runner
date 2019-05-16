#include "transform_systems.hpp"
#include "../components/transform.hpp"
#include "../components/render.hpp"

void look_at_system(entt::registry &registry) {
    auto view = registry.view<position, look_at>();
    for(auto entity: view) {
        auto follow_component = view.get<look_at>(entity);

        auto target_entity = follow_component.target;
        auto target_position = registry.get<position>(target_entity);

        // I don't know if using this is quite right, maybe in the future some kind of size component?
        auto target_sprite = registry.get<sprite>(target_entity);

        auto &position_component = view.get<position>(entity);

        position_component.x = target_position.x + (target_sprite.source_rect.w / 2);
        position_component.y = target_position.y + (target_sprite.source_rect.h / 2);
    }
}
