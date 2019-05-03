#ifndef ENTT_RUNNER_GAME_HPP
#define ENTT_RUNNER_GAME_HPP


#include <SDL_render.h>
#include <SDL_events.h>

class Game {
public:
    void update(float deltaTime);

    void render(SDL_Renderer *renderer);

    void input(SDL_Event event);
};


#endif //ENTT_RUNNER_GAME_HPP
