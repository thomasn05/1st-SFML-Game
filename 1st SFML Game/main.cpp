#include "entity.h"
#include "player.h"
#include <iostream>

const int win_width = 1400;
const int win_height = 1000;

int main()
{
    RenderWindow window(VideoMode(win_width, win_height), "Dodging Game");
    window.setFramerateLimit(60);
 
    Vector2f pos = Vector2f(win_width/2, win_height/2);
    Color color = Color::Green;
    Vector2f size = Vector2f(100.f, 100.f);

    Player player(pos, size, color);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
        }

        window.clear();

        player.update(window);

        window.display();
    }

    return 0;
}