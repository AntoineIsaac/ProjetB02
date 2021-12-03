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
#include "Level3.h"
#include "MenuLevel.h"
using namespace sf;
using namespace std;
class MenuLevel;
class Player;


class Game
{

    private:

        //Permet de savoir si un niveau a été fini
        bool endLevel1 = false;
        bool endLevel2 = false;
        bool endLevel3 = false;

        //Permet de savoir si le joueur a perdu toutes ses vies sur un niveau
        bool levelFailed = false;

        int currentLevel = 0;

        int windowWidht = 800;
        int windowHeight = 800;

        Clock clock;
        float dt;
        float multiplier = 60.f;
        float fps;

        Font font;

        Music music;

    public:
        Game();
        virtual ~Game();
        Game(const Game& other);
        Game& operator=(const Game& other);

        //Démarre le niveau en fonction de la valeur de currentLevel
        void startLevel(MenuLevel* menu);

        //Setters
        void setEndLevel(bool endLevel);
        void setCurrentLevel(int currentLevel);

        void setLevelFailed(bool failed);


    protected:


};

#endif // GAME_H
