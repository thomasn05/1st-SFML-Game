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

    text.setOrigin(get_center(text));
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
            icon.setColor(Color(105, 105, 105)); //Color for when ability is on CD
            this->game_wn.draw(icon);

            Text icon_timer = get_text(30, Color::White);
            Time time = ability.CD - (this->game_timer.getElapsedTime() - ability.timer); //Find time until the ability is up again
            std::string time_string = std::to_string(((float)time.asSeconds()));
            time_string.resize(4); //4 because we want three significant figures (0.00)
            this->draw_text(icon_timer, time_string, icon.getPosition());
        }

        else {
            icon.setColor(Color::White); //Return to normal if it is up
            this->game_wn.draw(icon);
        }
    }
}

Game_engine::Game_engine(RenderWindow& game_wn, const Font& font, const std::vector<Texture>& textures) : game_wn(game_wn), font(font)
{
    size_t i = 0;
    for (; i < 3; i++)
    {
        Sprite icon_sprite;
        icon_sprite.setTexture(textures[i]);
        icon_sprite.setScale(0.1f, 0.1f);
        icon_sprite.setOrigin(get_center(icon_sprite));
        icon_sprite.setPosition(600 + 100 * i, 875);

        std::pair<Sprite, int> icon = std::make_pair(icon_sprite, i);
        this->icons.push_back(icon);
    }

    button.setTexture(textures[i]);
    button.setOrigin(get_center(button));
    button.setPosition(button_pos);
}

void Game_engine::run()
{
    if (!this->game_start) { 
        this->draw_text(title, name, title_spawn);
        this->game_wn.draw(button);
        Vector2f mouse_pos = (Vector2f)Mouse::getPosition(this->game_wn);
        this->game_start = button.getGlobalBounds().contains(mouse_pos) && Mouse::isButtonPressed(Mouse::Left);
    }

    else {
        this->keep_mouse_in_bound();

        if (!player.is_dead())
        {
            this->draw_score();
            player.update(this->game_wn, this->game_timer.getElapsedTime());
            e_manager.update(this->game_wn, this->game_timer.getElapsedTime());
            this->draw_icons();
        }
        else { 
            this->draw_text(title, end_str, title_spawn); 
            this->draw_score(Vector2f(title_spawn.x, title_spawn.y - 75));
        }
    }
}

void Game_engine::keep_mouse_in_bound()
{
    Vector2i pos = Mouse::getPosition(this->game_wn);
    int x_pos = std::max(0, std::min(win_width, pos.x));
    int y_pos = std::max(0, std::min(win_height, pos.y));

    Mouse::setPosition(Vector2i(x_pos, y_pos), this->game_wn);
}


void Game_engine::draw_score(Vector2f pos)
{
    std::string score = "SCORE: " + std::to_string(this->e_manager.get_enemies_killed() * 10);
    this->draw_text(score_text, score, pos);
}

