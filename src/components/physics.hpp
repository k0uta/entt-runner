#ifndef ENTT_RUNNER_PHYSICS_HPP
#define ENTT_RUNNER_PHYSICS_HPP

struct body {
    float mass;
};

struct speed {
    float x;
    float y;
};

typedef entt::tag<"grounded"_hs> grounded;

#endif //ENTT_RUNNER_PHYSICS_HPP
