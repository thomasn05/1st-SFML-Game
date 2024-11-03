#include "entity.h"

const int win_width = 1400;
const int win_height = 1000;

int main()
{
    RenderWindow window(VideoMode(win_width, win_height), "SFML works!");
 
    Vector2f pos = Vector2f(win_width/2, win_height/2);
    Color color = Color::Green;
    Vector2f size = Vector2f(100.f, 100.f);

    Entity player(pos, size, color);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Right)
            {
                player.move(Mouse::getPosition(window));
            }
        }

        window.clear();

        player.draw(window);

        window.display();
    }

    return 0;
}