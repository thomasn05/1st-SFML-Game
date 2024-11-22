#include <SFML/Graphics.hpp>

#pragma once

using namespace sf;

const int win_width = 1400;
const int win_height = 1000;
const Vector2f player_spawn = Vector2f(win_width / 2, win_height / 2); // @brief location of player starting position

const int font_size = 50; // @brief size of end_game_text
const Vector2f end_text_spawn = Vector2f(win_width / 2 - font_size / 2 - 75, win_height / 2 - font_size / 2); // @brief the pos of the "Game Over!" text

const Vector2f BULLET_SIZE = Vector2f(5.f, 10.f);
const int MAX_BULLET_DISTANCE = 300; // @brief the maximum distance the bullet can travel
const int BULLET_SPEED = 10;

const float SPAWN_DISTANCE = 200; // @brief how far the enemy will spawn from the player
const Vector2f ENEMY_SIZE = Vector2f(25, 25);
const int ENEMY_SPEED = 3;

const Time SPAWN_INTERVAL = milliseconds(500);

