#include "game.hpp"
#include "../components/transform.hpp"
#include "../components/render.hpp"
#include "../systems/sprite_render.hpp"
#include "../systems/sprite_load.hpp"
#include "../systems/transform_systems.hpp"
#include "../components/physics.hpp"
#include "../systems/physics_systems.hpp"
#include "../components/collision.hpp"
#include "../systems/collision_systems.hpp"

void Game::update(float deltaTime) {
    look_at_system(registry);
    gravity_system(registry, deltaTime);
    speed_system(registry, deltaTime);

    box_collider_update_system(registry);
    box_collider_collision_system(registry);

    ground_collision_system(registry);

    clean_collisions_system(registry);

    perform_movement_system(registry);
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
    registry.assign<speed>(player, 300.f, 0.f);
    registry.assign<body>(player, 100.0f);
    registry.assign<box_collider>(player);
    registry.assign<box_collisions>(player);

    auto camera = registry.create();
    registry.assign<main_camera>(camera);
    registry.assign<position>(camera);
    registry.assign<look_at>(camera, player);

    for (int i = 0; i < 100; ++i) {
        auto tileBlock = registry.create();
        registry.assign<position>(tileBlock, i * 64.f, (float) screen_height);
        registry.assign<sprite_loader>(tileBlock, "resources/tiles/tileBlue_05.png");
        registry.assign<box_collider>(tileBlock);
    }
}
