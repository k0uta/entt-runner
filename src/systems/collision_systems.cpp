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

void box_collider_collision_system(entt::registry &registry) {
    auto view = registry.view<box_collider, movement>();
    auto other_view = registry.view<box_collider>();

    for (auto entity : view) {
        auto box_collider_component = view.get<box_collider>(entity);

        for (auto other_entity : other_view) {
            if (other_entity == entity) {
                continue;
            }

            auto other_box_collider_component = other_view.get(other_entity);

            if (box_collider_component.xMax < other_box_collider_component.xMin ||
                box_collider_component.xMin > other_box_collider_component.xMax) {
                continue;
            }
            if (box_collider_component.yMax < other_box_collider_component.yMin ||
                box_collider_component.yMin > other_box_collider_component.yMax) {
                continue;
            }

            auto &box_collisions_component = registry.get<box_collisions>(entity);

            box_collision collision_info{
                    other_entity,
                    box_collider_component.xMax - other_box_collider_component.xMin,
                    box_collider_component.yMax - other_box_collider_component.yMin
            };
            box_collisions_component.collisions.push_back(collision_info);
        }
    }
}

void clean_collisions_system(entt::registry &registry) {
    registry.view<box_collisions>().each([](auto &box_collisions_component) {
        box_collisions_component.collisions.clear();
    });
}

void ground_collision_system(entt::registry &registry) {
    auto view = registry.view<box_collisions, movement, speed>();
    for (auto entity: view) {
        auto collisions = view.get<box_collisions>(entity).collisions;

        float yDiff = 0.f;

        for (auto collision_info: collisions) {
            // Check ground
            yDiff = std::max(yDiff, collision_info.yDiff);
        }

        auto hasGrounded = registry.has<grounded>(entity);

        if (yDiff > 0.f && !hasGrounded) {
            registry.assign<grounded>(entity);
            hasGrounded = true;
        } else if (yDiff == 0.f && hasGrounded) {
            registry.remove<grounded>(entity);
            hasGrounded = false;
        }

        if (hasGrounded) {
            auto &movement_component = view.get<movement>(entity);
            auto &speed_component = view.get<speed>(entity);

            movement_component.y -= yDiff;
            speed_component.y = 0.f;
        }

    }
}