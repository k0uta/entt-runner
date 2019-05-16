#ifndef ENTT_RUNNER_PHYSICS_SYSTEMS_HPP
#define ENTT_RUNNER_PHYSICS_SYSTEMS_HPP

#include <entt/entt.hpp>

void gravity_system(entt::registry &registry, float deltaTime);

void speed_system(entt::registry &registry, float deltaTime);

#endif //ENTT_RUNNER_PHYSICS_SYSTEMS_HPP
