#ifndef ENTT_RUNNER_COLLISION_SYSTEMS_HPP
#define ENTT_RUNNER_COLLISION_SYSTEMS_HPP

#include <entt/entt.hpp>

void box_collider_update_system(entt::registry &registry);

void box_collider_collision_system(entt::registry &registry);

void clean_collisions_system(entt::registry &registry);

void ground_collision_system(entt::registry &registry);

#endif //ENTT_RUNNER_COLLISION_SYSTEMS_HPP
