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


void Game::startLevel1()
{
    int windowWidht = 960;
    int windowHeight = 720;
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
    Player player(80.0, 900, "./Images/jackfree/png/Run (1).png");

    //player.getSprite().setScale(Vector2f(0.05f, 0.05f));

    //Creation of a Zombie
    //Zombie zombie(0, 0, "Images/jackfree/png/Run (0).png");

    //Creation of a block

    //Platform* level[] = {new GrassBlock(0, 0), new LavaBlock(75, 0)};
    Level level;
    vector<Platform*> level1 = level.createLevel1();
    vector<Zombie*> zombieLevel1 = level.createZombiesLevel1();
    vector<Platform*> decorLevel1 = level.createDecorLevel1();

    Input input;


//    RectangleShape background;
//    background.setSize(Vector2f(800, 800));
//    background.setPosition(0, 0);
//    Texture Maintexture;
//    Maintexture.loadFromFile("Images/ciel.jpg");
//    background.setTexture(&Maintexture);


    while (window.isOpen())
    {
        dt = clock.restart().asSeconds();
        fps = dt * multiplier;

        Event event;

        while (window.pollEvent(event))
        {
            input.InputHandler(event, window);
        }

        player.update(input.GetButton().left, input.GetButton().right, input.GetButton().space, fps, level1, zombieLevel1);

        //Set the view on the player
        view.setCenter(player.getXPosition(), player.getYPosition());
        window.setView(view);

        window.clear();
//        window.draw(background);

        // Draw the decor
        for(Platform* p : decorLevel1)
        {
            window.draw(p->getSprite());
        }

        //Draw the player
        window.draw(player.getSprite());
        //window.draw(zombie.getSprite());

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
