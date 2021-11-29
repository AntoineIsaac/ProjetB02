#ifndef MENU_H
#define MENU_H


#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

using namespace std;
using namespace sf;


#define Max_main_menu 4

class Menu
{

       private:
        int MenuSelected;
        Font font;
        Text mainMenu[Max_main_menu];

        int width;
        int height;

        bool level1Succeed = false;
        bool level2Succeed = false;
        bool level3Succeed = false;

    public:
        Menu(float width, float height);
        virtual ~Menu();
        Menu(const Menu& other);
        Menu& operator=(const Menu& other);


        void draw(RenderWindow &window);
        void MoveUp();
        void MoveDown();

        int MenuPressed(){
            return MenuSelected;
        }

        void startMenu();
        void levelFinish(int level);


};

#endif // MENU_H
