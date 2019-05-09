#include "game.hpp"
#include "../components/transform.hpp"
#include "../components/render.hpp"

void Game::update(float deltaTime) {

}

void Game::render(SDL_Renderer *renderer) {

}

void Game::input(SDL_Event event) {

}

void Game::init() {
    auto player = registry.create();
    registry.assign<position>(player, 1280 / 2, 720 / 2);
    registry.assign<sprite_loader>(player, "resources/character/platformChar_idle.png");
}
