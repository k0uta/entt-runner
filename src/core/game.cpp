#include "game.hpp"
#include "../components/transform.hpp"
#include "../components/render.hpp"
#include "../systems/sprite_render.hpp"
#include "../systems/sprite_load.hpp"
#include "../systems/transform_systems.hpp"
#include "../components/physics.hpp"
#include "../systems/physics_systems.hpp"

void Game::update(float deltaTime) {
    look_at_system(registry);
    gravity_system(registry, deltaTime);
    speed_system(registry, deltaTime);
}

void Game::render(SDL_Renderer *renderer) {
    // TODO: Move to some kind of resource systems lane?
    sprite_load(registry, renderer);

    auto camera_position = registry.get<position>(registry.view<main_camera>()[0]);
    camera_position.x -= (float) screen_width / 2.f;
    camera_position.y -= (float) screen_height / 2.f;

    sprite_render(registry, renderer, camera_position);
}

void Game::input(SDL_Event event) {

}

void Game::init() {
    auto player = registry.create();
    registry.assign<position>(player, screen_width / 2.f, screen_height / 2.f);
    registry.assign<movement>(player, 0.f, 0.f);
    registry.assign<sprite_loader>(player, "resources/character/platformChar_idle.png");
    registry.assign<speed>(player, 0.f, 0.f);
    registry.assign<body>(player, 4.0f);

    auto camera = registry.create();
    registry.assign<main_camera>(camera);
    registry.assign<position>(camera);
    registry.assign<look_at>(camera, player);
}
