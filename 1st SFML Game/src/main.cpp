#include "game_engine.h"

const std::string abilities_img[3] = { "rsc\\Q-Icon.png", "rsc\\W-Icon.png", "rsc\\E-Icon.png" };

int main()
{
    RenderWindow window(VideoMode(win_width, win_height), "Dodging Game");
    window.setFramerateLimit(60);
    Clock game_timer;
    Font font;
    std::vector<Texture> icons;
    if (!font.loadFromFile("rsc\\arial.ttf")) { return -1; }

    for (size_t i = 0; i < 3; i++)
    {
        Texture texture;
        if (!texture.loadFromFile(abilities_img[i])) { return -1; }
        else { icons.push_back(texture); }
    }

    Player player(player_spawn);
    EnemyManager e_manager(player);
    
    Game_engine game_engine(window, font, player, e_manager, icons);

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