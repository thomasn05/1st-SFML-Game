#include "player.h"
#include "EnemyManager.h"
#include <iostream>

const int win_width = 1400;
const int win_height = 1000;
const Vector2f player_spawn = Vector2f(win_width / 2, win_height / 2); // @brief location of player starting position

const int font_size = 50; // @brief size of end_game_text
const Vector2f end_text_spawn = Vector2f(win_width / 2 - font_size / 2 - 75, win_height / 2 - font_size / 2); // @brief the pos of the "Game Over!" text

void draw_end_screen(Font font, RenderWindow& wn)
{
    Text end_text;
    end_text.setFont(font);
    end_text.setString("Game Over!");
    end_text.setCharacterSize(font_size);
    end_text.setFillColor(Color::Red);
    end_text.setStyle(Text::Bold);
    end_text.setOrigin(Vector2f(font_size / 2, font_size / 2));
    end_text.setPosition(end_text_spawn);

    wn.draw(end_text);
}

void keep_mouse_in_bound(RenderWindow& wn)
{
    Vector2i pos = Mouse::getPosition(wn);
    int x_pos = std::max(0, std::min(win_width, pos.x));
    int y_pos = std::max(0,std::min(win_height, pos.y));

    Mouse::setPosition(Vector2i(x_pos, y_pos), wn);
}

int main()
{
    RenderWindow window(VideoMode(win_width, win_height), "Dodging Game");
    window.setFramerateLimit(60);
    Clock game_timer;
    Font font;
    if (!font.loadFromFile("arial.ttf")) { return -1; }

    Player player(player_spawn);
    Entity object(Vector2f(100, 100), Vector2f(50, 50), Color::Blue);
    
    //EnemyManager E_manager(player);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
        }

        window.clear();

        keep_mouse_in_bound(window);

        if (!player.is_dead())
        {
            player.update(window, game_timer.getElapsedTime());
            player.object.setFillColor(Color::Green);
            //E_manager.update(window, game_timer.getElapsedTime());

            if (SAT_Collision(player.get_corners(), object.get_corners()))
            {
                player.object.setFillColor(Color::Red);
            }
        }
        else { draw_end_screen(font, window); }

        window.draw(object.object);

        window.display();
    }
    return 0;
}

//TODO: Score board, replay button, start screen