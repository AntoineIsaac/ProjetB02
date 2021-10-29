#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "include/Player.h"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 800), "The running dead");

    window.setFramerateLimit(60);
    Clock clock;
    //float dt;
    //float multiplier = 60.f;
    //float fps;

    //Creation of a player
    Texture texturePlayer;
    texturePlayer.loadFromFile("Images/zombie.gif");
    Sprite spritePlayer(texturePlayer);
    Player player(1, 0, 0, spritePlayer);


    while (window.isOpen())
    {
        //dt = clock.restart().asSeconds();
        //fps = dt * multiplier;

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(player.getSprite());
        window.display();
    }
    return 0;
}
