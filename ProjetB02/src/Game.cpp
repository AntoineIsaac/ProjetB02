#include "../include/Game.h"

Game::Game()
{
    //ctor
}

Game::~Game()
{
    //dtor
}

Game::Game(const Game& other)
{
    //copy ctor
}

Game& Game::operator=(const Game& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}


void Game::startLevel1(Menu* menu)
{
    int windowWidht = 800;
    int windowHeight = 800;
    RenderWindow window(VideoMode(windowWidht, windowHeight), "The running dead");
    window.setPosition(Vector2i(300,0));


    //Initiation of the view
    View view(Vector2f(0, 0), Vector2f(windowWidht, windowHeight));

    //Set framerate of the window
    window.setFramerateLimit(60);
    Clock clock;
    float dt;
    float multiplier = 60.f;
    float fps;

    //Creation of a player
    Player player(800.0, 900, "./Images/jackfree/png/Run (1).png");
    player.setPosition(player.getXPosition(), player.getYPosition());

    //Creation of the level, the decoration and the zombie in this level
    Level level;
    vector<Platform*> level1 = level.createLevel1();
    vector<Zombie*> zombieLevel1 = level.createZombiesLevel1();
    vector<Platform*> decorLevel1 = level.createDecorLevel1();

    Input input;


    while (window.isOpen())
    {
        if(endLevel == true)
        {
            menu->level1Finish();
            this_thread::sleep_for(2000ms);
            window.close();

        }

        dt = clock.restart().asSeconds();
        fps = dt * multiplier;

        Event event;

        while (window.pollEvent(event))
        {
            input.InputHandler(event, window);
        }

        player.update(input.GetButton().left, input.GetButton().right, input.GetButton().space, fps, level1, zombieLevel1, this);

        //Set the view on the player
        view.setCenter(player.getXPosition(), player.getYPosition());
        window.setView(view);

        window.clear();

        // Draw the decor
        for(Platform* p : decorLevel1)
        {
            window.draw(p->getSprite());
        }

        //Draw the player
        window.draw(player.getSprite());

        //Draw the Zombies of the level
        for(Zombie* z : zombieLevel1)
        {
            window.draw(z->getSprite());
            z->setPosition(z->getXPosition(), z->getYPosition());
        }

        //Draw the platform
        for(Platform* p : level1)
        {
            window.draw(p->getSprite());
        }

        window.display();


    }

}



void Game::setEndLevel(bool endLevel)
{
    this->endLevel = endLevel;
}
