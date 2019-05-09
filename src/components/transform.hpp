#ifndef ENTT_RUNNER_TRANSFORM_HPP
#define ENTT_RUNNER_TRANSFORM_HPP

#include <entt/entt.hpp>

struct position {
    int x;
    int y;
};

struct look_at {
    entt::entity *target;
};

#endif //ENTT_RUNNER_TRANSFORM_HPP
