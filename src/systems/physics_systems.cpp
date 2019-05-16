#include "physics_systems.hpp"
#include "../components/transform.hpp"
#include "../components/physics.hpp"

void gravity_system(entt::registry &registry, float deltaTime) {
    // TODO: Move to constants maybe?
    float gravity = 9.8f;
    registry.view<speed, body>().each([=](auto &speed_component, auto &body_component) {
        speed_component.y += (body_component.mass * gravity * deltaTime);
    });
}

void speed_system(entt::registry &registry, float deltaTime) {
    registry.view<position, speed>().each([=](auto &position_component, auto &speed_component) {
        position_component.x += speed_component.x * deltaTime;
        position_component.y += speed_component.y * deltaTime;
    });
}
