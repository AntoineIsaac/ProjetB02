#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "include/Player.h"
#include "include/Zombie.h"
#include "include/Input.h"
#include "include/Platform.h"
#include "include/GrassBlock.h"
#include "include/LavaBlock.h"
#include "include/Level.h"

using namespace sf;

int main()
{
    int windowWidht = 800;
    int windowHeight = 800;
    RenderWindow window(VideoMode(windowWidht, windowHeight), "The running dead");

    //Initiation of the view
    View view(Vector2f(0, 0), Vector2f(windowWidht, windowHeight));

    //Set framerate of the window
    window.setFramerateLimit(60);
    Clock clock;
    float dt;
    float multiplier = 60.f;
    float fps;

    //Creation of a player
    Player player(300.0, 100, "./Images/jackfree/png/Run (1).png");

    //player.getSprite().setScale(Vector2f(0.05f, 0.05f));

    //Creation of a Zombie
    //Zombie zombie(0, 0, "Images/jackfree/png/Run (0).png");

    //Creation of a block

    //Platform* level[] = {new GrassBlock(0, 0), new LavaBlock(75, 0)};
    Level level;
    vector<Platform*> level1 = level.createLevel1();

    Input input;


    while (window.isOpen())
    {
        dt = clock.restart().asSeconds();
        fps = dt * multiplier;

        Event event;

        while (window.pollEvent(event))
        {
            input.InputHandler(event, window);
        }

        player.update(input.GetButton().left, input.GetButton().right, input.GetButton().space, fps, level1);

        //Set the view on the player
        view.setCenter(player.getXPosition(), player.getYPosition());
        window.setView(view);

        window.clear();

        //Draw the player
        window.draw(player.getSprite());
        //window.draw(zombie.getSprite());

        //Draw the platform
        for(Platform* p : level1)
        {
            window.draw(p->getSprite());
        }

        window.display();
    }
    return 0;
}
