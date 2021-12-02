#ifndef MENULEVEL_H
#define MENULEVEL_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

using namespace std;
using namespace sf;


#define Max_main_menu 3

class MenuLevel
{
    private:
        int MenuSelected;
        Font font;
        Text mainMenu[Max_main_menu];

        int width = 800;
        int height = 800;

        //Permet de savoir si un niveau à été fini par un joueur
        bool level1Succeed = false;
        bool level2Succeed = false;
        bool level3Succeed = false;

    public:
        MenuLevel();
        virtual ~MenuLevel();
        MenuLevel(const MenuLevel& other);
        MenuLevel& operator=(const MenuLevel& other);


        void draw(RenderWindow &window);
        //Action à faire quand on appuie sur la flèche du haut
        void MoveUp();
        //Action à faire quand on appuie sur la flèche du bas
        void MoveDown();
        void startMenuLevel();

        void levelFinish(int level);

        virtual int MenuPressed();
};

#endif // MENULEVEL_H
