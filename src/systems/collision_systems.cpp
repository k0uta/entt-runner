#include "collision_systems.hpp"
#include "../components/collision.hpp"
#include "../components/transform.hpp"
#include "../components/render.hpp"
#include "../components/physics.hpp"

void box_collider_update_system(entt::registry &registry) {
    auto view = registry.view<box_collider, position, sprite>();

    for (auto entity : view) {
        auto &box_collider_component = view.get<box_collider>(entity);
        auto position_component = view.get<position>(entity);
        auto movement_component = registry.try_get<movement>(entity);
        auto sprite_component = view.get<sprite>(entity);

        float xMin = position_component.x;
        float yMin = position_component.y;

        if (movement_component != nullptr) {
            xMin += movement_component->x;
            yMin += movement_component->y;
        }

        box_collider_component.xMin = xMin;
        box_collider_component.yMin = yMin;
        box_collider_component.xMax = xMin + sprite_component.source_rect.w;
        box_collider_component.yMax = yMin + sprite_component.source_rect.h;
    }
}