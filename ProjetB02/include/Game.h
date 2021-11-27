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

using namespace sf;
using namespace std;
class Menu;


class Game
{

    private:
        bool endLevel = false;

    public:
        Game();
        virtual ~Game();
        Game(const Game& other);
        Game& operator=(const Game& other);

        void startLevel1(Menu* menu);

        void setEndLevel(bool endLevel);

    protected:


};

#endif // GAME_H
