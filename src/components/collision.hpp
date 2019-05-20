#ifndef ENTT_RUNNER_COLLISION_HPP
#define ENTT_RUNNER_COLLISION_HPP

#include <entt/entt.hpp>

struct box_collider {
    float xMin;
    float yMin;
    float xMax;
    float yMax;
};

struct box_collision {
    entt::entity other_entity;
    float xDiff;
    float yDiff;
};

struct box_collisions {
    std::vector<box_collision> collisions;
};

#endif //ENTT_RUNNER_COLLISION_HPP
