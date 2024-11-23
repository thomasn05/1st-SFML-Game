#include "game_engine.h"

int main()
{
    RenderWindow window(VideoMode(win_width, win_height), "Dodging Game");
    window.setFramerateLimit(60);
    Clock game_timer;
    Font font;
    if (!font.loadFromFile("arial.ttf")) { return -1; }

    Player player(player_spawn);
    EnemyManager e_manager(player);
    
    Game_engine game_engine(window, font, player, e_manager);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
        }

        window.clear();

        game_engine.run();

        window.display();
    }
    return 0;
}

//TODO: Score board, replay button, start screen