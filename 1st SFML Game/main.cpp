#include <SFML/Graphics.hpp>

const int win_width = 1400;
const int win_height = 1000;

int main()
{
    sf::RenderWindow window(sf::VideoMode(win_width, win_height), "SFML works!");
    sf::RectangleShape player(sf::Vector2f(100.f, 100.f));
    player.setFillColor(sf::Color::Green);
    player.setPosition(win_width / 2, win_height / 2);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        window.clear();

        window.draw(player);

        window.display();
    }

    return 0;
}