#include "player.h"
#include "EnemyManager.h"

#pragma once

const int win_width = 1400;
const int win_height = 1000;
const Vector2f player_spawn = Vector2f(win_width / 2, win_height / 2); // @brief location of player starting position

const int end_game_font_size = 100; // @brief size of end_game_text
const Vector2f end_text_spawn = Vector2f(win_width / 2 - end_game_font_size / 2 - 175, win_height / 2 - end_game_font_size / 2); // @brief the pos of the "Game Over!" text

const int score_font_size = 25;
const Vector2f score_pos = Vector2f(100, 100);

const int start_font_size = 100;
const Vector2f start_text_pos = Vector2f(win_width / 2 - start_font_size / 2 - 175, win_height / 2 - start_font_size / 2);

Text& get_text(const Font font, const int font_size, Color color, Vector2f pos);

class Game_engine
{
private:
	RenderWindow& game_wn;
	Clock game_timer;
	Font font;
	Player& player = player;
	EnemyManager& e_manager;
	Text end_text = get_text(font, end_game_font_size, Color::Red, end_text_spawn);
	Text score_text = get_text(font, score_font_size, Color::White, score_pos);
	Text start_text = get_text(font, start_font_size, Color::Red, start_text_pos);

	void end_screen();

	void keep_mouse_in_bound();

	//void start_screen();

	void draw_score();

public:
	Game_engine(RenderWindow& game_wn, Font font, Player& player, EnemyManager& e_manager) : game_wn(game_wn), font(font), player(player), e_manager(e_manager) {}
	~Game_engine() = default;

	void run();

};