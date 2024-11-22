#include "player.h"
#include "EnemyManager.h"

#pragma once

const int win_width = 1400;
const int win_height = 1000;
const Vector2f player_spawn = Vector2f(win_width / 2, win_height / 2); // @brief location of player starting position

const int font_size = 50; // @brief size of end_game_text
const Vector2f end_text_spawn = Vector2f(win_width / 2 - font_size / 2 - 75, win_height / 2 - font_size / 2); // @brief the pos of the "Game Over!" text

class Game_engine
{
private:
	RenderWindow& game_wn;
	Clock game_timer;
	Font font;
	Player& player = player;
	EnemyManager& e_manager;

	void end_screen();

	void keep_mouse_in_bound();

	//void start_screen();

	//void draw_score();

public:
	Game_engine(RenderWindow& game_wn, Font font, Player& player, EnemyManager& e_manager) : game_wn(game_wn), font(font), player(player), e_manager(e_manager) {}
	~Game_engine() = default;

	void run();

};

