#include "player.h"
#include "EnemyManager.h"

const int win_width = 1400;
const int win_height = 1000;
const Vector2f player_spawn = Vector2f(win_width / 2, win_height / 2);

void draw_end_screen(Font font, RenderWindow& wn)
{
    Text end_text;
    end_text.setFont(font);
    end_text.setString("Game Over!");
    end_text.setCharacterSize(50);
    end_text.setFillColor(Color::Red);
    end_text.setStyle(Text::Bold);
    end_text.setPosition(player_spawn);

    wn.draw(end_text);
}

int main()
{
    RenderWindow window(VideoMode(win_width, win_height), "Dodging Game");
    window.setFramerateLimit(60);
    Clock game_timer;
    Font font;
    if (!font.loadFromFile("arial.ttf")) { return -1; }

    Player player(player_spawn);
    EnemyManager E_manager(player);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
        }

        window.clear();

        if (!player.is_dead())
        {
            player.update(window, game_timer);
            E_manager.update(window, game_timer.getElapsedTime());
        }
        else { draw_end_screen(font, window); }

        window.display();
    }
    return 0;
}