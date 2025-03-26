#include "player.h"
#include "EnemyManager.h"
#include <string>
#include <iostream>

#pragma once

const int win_width = 1400;
const int win_height = 1000;
const Vector2f center = Vector2f(win_width / 2, win_height / 2);
const Vector2f player_spawn = center; // @brief location of player starting position

const int end_game_font_size = 100; // @brief size of end_game_text
const Vector2f end_text_spawn = Vector2f(center.x, center.y - 50); // @brief the pos of the "Game Over!" text

const int score_font_size = 50; //@brief the size of the score text
const Vector2f score_pos = Vector2f(150, 75); //@brief position of the score text

const int start_font_size = 100; //@brief size of the game Title for start screen
const Vector2f start_text_pos = Vector2f(center.x, center.y - 75); //@brief position of game title for start screen

const Vector2f button_pos = Vector2f(center.x, center.y + 50);
const Vector2f button_size = Vector2f(200, 60);

/*
* @brief create a text object with given size and color
* @param font_size: size of text
* color: color of text
*/
Text get_text(const int font_size, Color color);

class Game_engine
{
private:
	RenderWindow& game_wn;
	Clock game_timer;
	Font font;
	Player player;
	EnemyManager e_manager;
	Sprite button;
	Text title = get_text(end_game_font_size, Color::Red); //@brief the "GAME OVER" text
	Text score_text = get_text(score_font_size, Color::White); //@breif score text
	bool game_start = 0;
	std::vector<std::pair<Sprite, int>> icons; //@brief vector storing the abilities icon {Icon_Sprite, ability id}

	/*
	* @brief prevents the mouse from going outside the game window
	*/
	void keep_mouse_in_bound();

	/*
	* @brief calculate the score and draw it on screen
	*/
	void draw_score();

	/*
	* @brief draw a given text object on screen
	* @param text: the text object
	* @param msg: the string of the text
	* @param pos: the position of the object
	*/
	void draw_text(Text& text, const std::string msg, Vector2f pos);

	/*
	* @brief draw the icons and update them base on whether the ability is on CD or not.
	* If it is then there will be a timer to let user know when it will be up again
	*/
	void draw_icons();

public:
	Game_engine(RenderWindow& game_wn, const Font font, const std::vector<Texture>& textures);
	~Game_engine() = default;

	/*
	* @brief run the game
	*/
	void run();



};