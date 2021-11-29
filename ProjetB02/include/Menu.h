#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

using namespace std;
using namespace sf;


#define Max_main_menu 3

class Menu
{

       private:
        int MenuSelected;
        Font font;
        Text mainMenu[Max_main_menu];

        int width = 800;
        int height = 800;



    public:
        Menu();
        virtual ~Menu();
        Menu(const Menu& other);
        Menu& operator=(const Menu& other);


        void draw(RenderWindow &window);
        void MoveUp();
        void MoveDown();
        void startMenu();

        virtual int MenuPressed();
};

#endif // MENU_H
