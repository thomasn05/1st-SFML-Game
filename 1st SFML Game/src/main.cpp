#include "game_engine.h"

const std::string sprites[] = { "rsc/Q-Icon.png", "rsc/W-Icon.png", "rsc/E-Icon.png", "rsc/play_button.png", "rsc/replay.png"}; //@brief the texture for the abilities icon

int main()
{
    RenderWindow window(VideoMode(win_width, win_height), "Dodging Game");
    window.setFramerateLimit(60);
    Clock game_timer;
    Font font;
    std::vector<Texture> icons; //@brief vector storing the textures
    if (!font.loadFromFile("rsc\\arial.ttf")) { return -1; }

    for (std::string s : sprites)
    {
        Texture texture;
        if (!texture.loadFromFile(s)) { return -1; }
        else { icons.push_back(texture); }
    }
    
    Game_engine game_engine(window, font, icons);

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