#ifndef ENTT_RUNNER_TRANSFORM_HPP
#define ENTT_RUNNER_TRANSFORM_HPP

#include <entt/entt.hpp>

struct position {
    float x;
    float y;
};

struct look_at {
    entt::entity target;
};

typedef entt::tag<"main_camera"_hs> main_camera;

#endif //ENTT_RUNNER_TRANSFORM_HPP
