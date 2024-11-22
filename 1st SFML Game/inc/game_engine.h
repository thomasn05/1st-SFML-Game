#include "player.h"
#include "EnemyManager.h"

#pragma once

class Game_engine
{
private:
	RenderWindow& game_wn;
	Clock game_timer;
	Font font;
	Player player = player;
	EnemyManager e_manager;

	void end_screen();

	void keep_mouse_in_bound();

	//void start_screen();

	//void draw_score();

public:
	Game_engine(RenderWindow& game_wn, Font font, Player player, EnemyManager e_manager) : game_wn(game_wn), font(font), player(player), e_manager(e_manager) {}
	~Game_engine() = default;

	void run();

};

