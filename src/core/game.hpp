#ifndef ENTT_RUNNER_GAME_HPP
#define ENTT_RUNNER_GAME_HPP

#include <SDL.h>
#include <entt/entt.hpp>

class Game {
public:
    void update(float deltaTime);

    void render(SDL_Renderer *renderer);

    void input(SDL_Event event);

    void init();

protected:
    entt::registry registry;
};


#endif //ENTT_RUNNER_GAME_HPP