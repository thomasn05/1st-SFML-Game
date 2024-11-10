#include "player.h"
#include "enemy.h"

const int win_width = 1400;
const int win_height = 1000;
const Vector2f player_spawn = Vector2f(win_width / 2, win_height / 2);

int main()
{
    RenderWindow window(VideoMode(win_width, win_height), "Dodging Game");
    window.setFramerateLimit(60);
    Clock game_timer;

    Player player(player_spawn);
    Enemy e1(player);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
        }

        window.clear();

        player.update(window, game_timer);
        e1.update(window);

        window.display();
    }

    return 0;
}