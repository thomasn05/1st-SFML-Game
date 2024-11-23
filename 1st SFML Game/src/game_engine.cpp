#include "game_engine.h"
#include <iostream>

Text get_text(const int font_size, Color color)
{
    Text end_text;
    end_text.setCharacterSize(font_size);
    end_text.setFillColor(color);
    end_text.setStyle(Text::Bold);

    return end_text;
}

void Game_engine::draw_text(Text& text, const std::string msg, Vector2f pos) const
{
    text.setFont(this->font);
    text.setString(msg);

    FloatRect bounds = text.getLocalBounds();
    text.setOrigin(Vector2f(bounds.width / 2, bounds.height / 2));
    text.setPosition(pos);

    this->game_wn.draw(text);
}

void Game_engine::run()
{
    if (!this->game_start) { this->draw_text(start_text, "GAME!", start_text_pos); }

    else {
        this->keep_mouse_in_bound();

        this->draw_score();

        if (!player.is_dead())
        {
            player.update(this->game_wn, this->game_timer.getElapsedTime());
            e_manager.update(this->game_wn, this->game_timer.getElapsedTime());

        }
        else { this->draw_text(end_text, "GAME OVER!", end_text_spawn); }
    }
}

void Game_engine::keep_mouse_in_bound()
{
    Vector2i pos = Mouse::getPosition(this->game_wn);
    int x_pos = std::max(0, std::min(win_width, pos.x));
    int y_pos = std::max(0, std::min(win_height, pos.y));

    Mouse::setPosition(Vector2i(x_pos, y_pos), this->game_wn);
}


void Game_engine::draw_score()
{
    std::string score = "SCORE: " + std::to_string(this->e_manager.get_enemies_killed() * 10);
    this->draw_text(score_text, score, score_pos);
}
