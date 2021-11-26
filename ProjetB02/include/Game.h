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

using namespace sf;

class Game
{

    private:
        bool endLevel = false;

    public:
        Game();
        virtual ~Game();
        Game(const Game& other);
        Game& operator=(const Game& other);

        void startLevel1();

        void setEndLevel(bool endLevel);

    protected:


};

#endif // GAME_H
