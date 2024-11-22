#include "game_engine.h"

Text& get_text(const Font font, const int font_size, Color color, Vector2f pos)
{
    Text end_text;
    end_text.setFont(font);
    end_text.setCharacterSize(font_size);
    end_text.setFillColor(color);
    end_text.setStyle(Text::Bold);
    end_text.setOrigin(Vector2f(font_size / 2.f, font_size / 2.f));
    end_text.setPosition(pos);

    return end_text;
}

void Game_engine::run()
{
    this->game_wn.clear();

    this->keep_mouse_in_bound();

    if (!player.is_dead())
    {
        player.update(this->game_wn, this->game_timer.getElapsedTime());

        e_manager.update(this->game_wn, this->game_timer.getElapsedTime());
    }
    else { end_screen(); }

    this->game_wn.display();
}

void Game_engine::end_screen()
{
    this->end_text.setString("GAME OVER!");
    this->game_wn.draw(this->end_text);
}

void Game_engine::keep_mouse_in_bound()
{
    Vector2i pos = Mouse::getPosition(this->game_wn);
    int x_pos = std::max(0, std::min(win_width, pos.x));
    int y_pos = std::max(0, std::min(win_height, pos.y));

    Mouse::setPosition(Vector2i(x_pos, y_pos), this->game_wn);
}

//void Game_engine::start_screen()
//{
//}
//
void Game_engine::draw_score()
{
}
