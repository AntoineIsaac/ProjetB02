#ifndef GAME_H
#define GAME_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Zombie.h"
#include "Input.h"
#include "Platform.h"
#include "Level.h"
#include <string>
#include <chrono>
#include <thread>
#include "Menu.h"
#include "Level1.h"
#include "Level2.h"

using namespace sf;
using namespace std;
class Menu;


class Game
{

    private:
        bool endLevel1 = false;
        bool endLevel2 = false;

        int currentLevel = 0;

        int windowWidht = 800;
        int windowHeight = 800;

        Clock clock;
        float dt;
        float multiplier = 60.f;
        float fps;

    public:
        Game();
        virtual ~Game();
        Game(const Game& other);
        Game& operator=(const Game& other);

        void initWindow();

        void startLevel1(Menu* menu);
        void startLevel2(Menu* menu);

        void setEndLevel(bool endLevel);


    protected:


};

#endif // GAME_H
