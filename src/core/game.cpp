#include "game.hpp"
#include "../components/transform.hpp"
#include "../components/render.hpp"
#include "../systems/sprite_load.hpp"
#include "../systems/transform_systems.hpp"

void Game::update(float deltaTime) {
    look_at_system(registry);
}

void Game::render(SDL_Renderer *renderer) {
    sprite_load(registry, renderer);
}

void Game::input(SDL_Event event) {

}

void Game::init() {
    auto player = registry.create();
    registry.assign<position>(player, screen_width / 2, screen_height / 2);
    registry.assign<sprite_loader>(player, "resources/character/platformChar_idle.png");

    auto camera = registry.create();
    registry.assign<main_camera>(camera);
    registry.assign<position>(camera);
    registry.assign<look_at>(camera, &player);
}
