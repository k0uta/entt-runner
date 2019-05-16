#include "app.hpp"
#include "game.hpp"

#include <iostream>
#include <SDL.h>

void App::run() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "Failed to initialise SDL\n";
        throw std::runtime_error(SDL_GetError());
    }

    SDL_Window *window = SDL_CreateWindow(appName,
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          width,
                                          height,
                                          SDL_WINDOW_ALLOW_HIGHDPI);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    auto game = new Game();
    game->screen_width = width;
    game->screen_height = height;
    game->init();

    auto fpsDeltaTime = 1000.f / fps;

    auto previousTick = SDL_GetTicks();
    auto accumulator = 0.f;

    while (true) {
        auto currentTick = SDL_GetTicks();
        auto deltaTime = currentTick - previousTick;
        previousTick = currentTick;

        accumulator += deltaTime;

        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                break;
            } else {
                game->input(event);
            }
        }

        while(accumulator >= fpsDeltaTime) {
            accumulator -= fpsDeltaTime;
            game->update(fpsDeltaTime/1000.f);
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        game->render(renderer);

        SDL_RenderPresent(renderer);
    }

    delete(game);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}