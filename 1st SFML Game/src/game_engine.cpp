#include "game_engine.h"
#include <iomanip>

Text get_text(const int font_size, Color color)
{
    Text end_text;
    end_text.setCharacterSize(font_size);
    end_text.setFillColor(color);
    end_text.setStyle(Text::Bold);

    return end_text;
}

void Game_engine::draw_text(Text& text, const std::string msg, Vector2f pos)
{
    text.setFont(this->font);
    text.setString(msg);

    FloatRect bounds = text.getLocalBounds();
    text.setOrigin(Vector2f(bounds.width / 2, bounds.height / 2));
    text.setPosition(pos);

    this->game_wn.draw(text);
}

void Game_engine::draw_icons()
{
    for (auto& i : this->icons)
    {
        Sprite icon = i.first;
        int ability_id = i.second;

        Ability ability = this->player.get_abilities(ability_id);
        if (!ability.is_up) { 
            icon.setColor(Color(105, 105, 105));
            this->game_wn.draw(icon);

            Text icon_timer = get_text(30, Color::White);
            Time time = ability.CD - (this->game_timer.getElapsedTime() - ability.timer);
            std::string time_string = std::to_string(((float)time.asSeconds()));
            time_string.resize(4);
            this->draw_text(icon_timer, time_string, icon.getPosition());
        }

        else {
            icon.setColor(Color::White);
            this->game_wn.draw(icon);
        }
    }
}

Game_engine::Game_engine(RenderWindow& game_wn, const Font font, Player& player, EnemyManager& e_manager, const std::vector<Texture>& icons_texture) : game_wn(game_wn), font(font), player(player), e_manager(e_manager)
{
    for (size_t i = 0; i < icons_texture.size(); i++)
    {
        Sprite icon_sprite;
        icon_sprite.setTexture(icons_texture[i]);
        icon_sprite.setScale(0.1, 0.1);
        FloatRect bounds = icon_sprite.getLocalBounds();
        icon_sprite.setOrigin(bounds.width / 2, bounds.height / 2);
        icon_sprite.setPosition(600 + 100 * i, 875);

        std::pair<Sprite, int> icon = std::make_pair(icon_sprite, i);
        this->icons.push_back(icon);
    }
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
            this->draw_icons();

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

