#include "player.h"
#include "EnemyManager.h"
#include <string>
#include <iostream>

#pragma once

const int win_width = 1400;
const int win_height = 1000;
const Vector2f center = Vector2f(win_width / 2, win_height / 2);
const Vector2f player_spawn = center; // @brief location of player starting position

const int title_font_size = 100; 
const Vector2f title_spawn = Vector2f(center.x, center.y - 75);
const std::string name = "League Shooter";
const std::string end_str = "GAME OVER!";

const int score_font_size = 50; 
const Vector2f score_pos = Vector2f(150, 75); 

const Vector2f button_pos = Vector2f(center.x, center.y + 25);

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
	Player player = Player(player_spawn);
	EnemyManager e_manager = EnemyManager();
	Sprite button;
	Text title = get_text(title_font_size, Color::Red); 
	Text score_text = get_text(score_font_size, Color::White);
	bool game_start = 0;
	std::pair<Texture, Texture> buttons;
	std::vector<std::pair<Sprite, int>> icons; //@brief vector storing the abilities icon {Icon_Sprite, ability id}

	/*
	* @brief prevents the mouse from going outside the game window
	*/
	void keep_mouse_in_bound();

	/*
	* @brief calculate the score and draw it on screen
	*/
	void draw_score(Vector2f pos = score_pos);

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

	/*
	@breif the title screen
	*/
	void start_screen();

	/*
	* @breif explain how to play
	*/
	void instruction_screen();

public:
	Game_engine(RenderWindow& game_wn, const Font& font, const std::vector<Texture>& textures);
	~Game_engine() = default;

	/*
	* @brief run the game
	*/
	void run();

	bool button_clicked();

};

template<typename T>
Vector2f get_center(const T& drawable) {
	FloatRect bounds = drawable.getLocalBounds();
	return Vector2f(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
}