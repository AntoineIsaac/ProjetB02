#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "include/Player.h"
#include "include/Input.h"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 800), "The running dead");

    //Set framerate of the window
    window.setFramerateLimit(60);
    Clock clock;
    //float dt;
    //float multiplier = 60.f;
    //float fps;

    //Creation of a player
    Player player(1, 0, 0, "Images/zombie.gif");
    player.getSprite().setPosition(500.f, 100.f);

    Input input;


    while (window.isOpen())
    {
        //dt = clock.restart().asSeconds();
        //fps = dt * multiplier;

        Event event;
        while (window.pollEvent(event))
        {
            input.InputHandler(event, window);
        }

        player.update(input.GetButton().left, input.GetButton().right, input.GetButton().space);

        window.clear();
        window.draw(player.getSprite());
        window.display();
    }
    return 0;
}
