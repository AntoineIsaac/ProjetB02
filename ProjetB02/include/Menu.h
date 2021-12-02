#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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

        SoundBuffer buffer;
        Sound sound;

        int width = 800;
        int height = 800;



    public:
        Menu();
        virtual ~Menu();
        Menu(const Menu& other);
        Menu& operator=(const Menu& other);


        void draw(RenderWindow &window);
        //Action à faire quand on appuie sur la flèche du haut
        void MoveUp();
        //Action à faire quand on appuie sur la flèche du bas
        void MoveDown();
        void startMenu();

        int MenuPressed();
};

#endif // MENU_H
