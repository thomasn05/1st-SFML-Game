#include "player.h"
#include "EnemyManager.h"
#include <string>

#pragma once

const int win_width = 1400;
const int win_height = 1000;
const Vector2f player_spawn = Vector2f(win_width / 2, win_height / 2); // @brief location of player starting position

const int end_game_font_size = 100; // @brief size of end_game_text
const Vector2f end_text_spawn = Vector2f(win_width / 2, win_height / 2 - 50); // @brief the pos of the "Game Over!" text

const int score_font_size = 50;
const Vector2f score_pos = Vector2f(150, 75);

const int start_font_size = 100;
const Vector2f start_text_pos = Vector2f(win_width / 2, win_height / 2 - 75);

Text get_text(const int font_size, Color color);

class Game_engine
{
private:
	RenderWindow& game_wn;
	Clock game_timer;
	Font font;
	Player& player = player;
	EnemyManager& e_manager;
	Text end_text = get_text(end_game_font_size, Color::Red);
	Text score_text = get_text(score_font_size, Color::White);
	Text start_text = get_text(start_font_size, Color::Red);
	bool game_start = 1;
	std::vector<std::pair<Sprite, Text>> icons;
	

	void keep_mouse_in_bound();

	void draw_score();

	void draw_text(Text& text, const std::string msg, Vector2f pos);

	void draw_icons();

public:
	Game_engine(RenderWindow& game_wn, const Font font, Player& player, EnemyManager& e_manager, const std::vector<Texture>& icons_texture);
	~Game_engine() = default;

	void run();

};