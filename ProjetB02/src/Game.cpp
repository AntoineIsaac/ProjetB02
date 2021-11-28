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



void Game::startLevel(Menu* menu)
{
    RenderWindow window(VideoMode(windowWidht, windowHeight), "The running dead");
    window.setPosition(Vector2i(300,0));

    //Set framerate of the window
    window.setFramerateLimit(60);

    //Initiation of the view
    View view(Vector2f(0, 0), Vector2f(windowWidht, windowHeight));

    //Creation of a player
    Player player(80.0, 1000, "./Images/jackfree/png/Run (1).png");

    //Creation of the level, the decoration and the zombie in this level
    vector<Platform*> level;
    vector<Zombie*> zombieLevel;
    vector<Platform*> decorLevel;
    Level* lvl;
    Color color;


    switch(currentLevel)
    {
        case 1:
                player.setHP(16);
                lvl = new Level1();
                level = lvl->createLevel();
                zombieLevel = lvl->createZombiesLevel();
                decorLevel = lvl->createDecorLevel();
                color = Color(0,191,255);
                break;

        case 2:
                player.setHP(16);
                lvl = new Level2();
                level = lvl->createLevel();
                zombieLevel = lvl->createZombiesLevel();
                decorLevel = lvl->createDecorLevel();
                color = Color::Black;
                break;

    }


    Input input;

    while (window.isOpen())
    {
        if(endLevel1 == true && currentLevel == 1)
        {
            currentLevel++;
            startLevel(menu);
            window.close();
            break;

        }
        if(endLevel2 == true)
        {
            window.close();
            menu->level1Finish();
        }

        dt = clock.restart().asSeconds();
        fps = dt * multiplier;

        Event event;

        while (window.pollEvent(event))
        {
            input.InputHandler(event, window);
        }

        player.update(input.GetButton().left, input.GetButton().right, input.GetButton().space, fps, level, zombieLevel, this);

        //Set the view on the player
        view.setCenter(player.getXPosition(), player.getYPosition());
        window.setView(view);

        window.clear(color);

        // Draw the decor
        for(Platform* p : decorLevel)
        {
            window.draw(p->getSprite());
        }

        //Draw the player
        window.draw(player.getSprite());

        //Draw the Zombies of the level
        for(Zombie* z : zombieLevel)
        {
            window.draw(z->getSprite());
            z->setPosition(z->getXPosition(), z->getYPosition());
        }

        //Draw the platform
        for(Platform* p : level)
        {
            window.draw(p->getSprite());
        }

        window.display();


    }

}


void Game::setEndLevel(bool endLevel)
{
    switch(currentLevel)
    {
        case 1:
            endLevel1 = true;
            break;
        case 2:
            endLevel2 = true;
            break;
    }
}

void Game::setCurrentLevel(int currentLevel)
{
    this->currentLevel = currentLevel;
}

