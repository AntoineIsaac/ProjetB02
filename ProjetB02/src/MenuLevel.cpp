#include "../include/MenuLevel.h"

MenuLevel::MenuLevel()
{
    if (!font.loadFromFile("Fonts/CottonButter.ttf"))
	{
		cout <<"No font is here";
	}


	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::Blue);
	mainMenu[0].setString("Level 1");
	mainMenu[0].setCharacterSize(85);
	mainMenu[0].setPosition(350, 200);
	mainMenu[0].setStyle(1);

	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setString("Level 2");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition(350, 300);

	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::White);
	mainMenu[2].setString("Level 3");
	mainMenu[2].setCharacterSize(70);
	mainMenu[2].setPosition(350, 400);

	MenuSelected = 0;
}

MenuLevel::~MenuLevel()
{
    //dtor
}

MenuLevel::MenuLevel(const MenuLevel& other)
{
    //copy ctor
}

MenuLevel& MenuLevel::operator=(const MenuLevel& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void MenuLevel::draw(RenderWindow &window)
{
	for (int i = 0; i < Max_main_menu; i++)
	{
		window.draw(mainMenu[i]);
	}
}


void MenuLevel::MoveUp()
{
	if (MenuSelected - 1 >= 0)
	{
	    //Lorsque le niveau a été fini, il s'affiche en vert
	    if((MenuSelected == 0 && level1Succeed == true) || (MenuSelected == 1 && level2Succeed) || (MenuSelected == 2 && level3Succeed))
        {
            mainMenu[MenuSelected].setFillColor(Color::Green);
        }
        else
        {
            mainMenu[MenuSelected].setFillColor(Color::White);
        }
        mainMenu[MenuSelected].setCharacterSize(70);
        mainMenu[MenuSelected].setStyle(0);


		MenuSelected--;
		if(MenuSelected == -1)
        {
            MenuSelected = 2;
        }

        if((MenuSelected == 0 && level1Succeed == true) || (MenuSelected == 1 && level2Succeed) || (MenuSelected == 2 && level3Succeed))
        {
            mainMenu[MenuSelected].setFillColor(Color::Green);
        }
        else
        {
            mainMenu[MenuSelected].setFillColor(Color::Blue);
        }
        mainMenu[MenuSelected].setCharacterSize(85);
        mainMenu[MenuSelected].setStyle(1);

	}
}

void MenuLevel::MoveDown()
{
	if (MenuSelected + 1 <= Max_main_menu)
	{
		if((MenuSelected == 0 && level1Succeed == true) || (MenuSelected == 1 && level2Succeed) || (MenuSelected == 2 && level3Succeed))
        {
            mainMenu[MenuSelected].setFillColor(Color::Green);
        }
        else
        {
            mainMenu[MenuSelected].setFillColor(Color::White);
        }
        mainMenu[MenuSelected].setCharacterSize(70);
        mainMenu[MenuSelected].setStyle(0);


		MenuSelected++;
		if(MenuSelected == 3)
        {
            MenuSelected = 0;
        }

		if((MenuSelected == 0 && level1Succeed == true) || (MenuSelected == 1 && level2Succeed) || (MenuSelected == 2 && level3Succeed))
        {
            mainMenu[MenuSelected].setFillColor(Color::Green);
        }
        else
        {
            mainMenu[MenuSelected].setFillColor(Color::Blue);
        }
        mainMenu[MenuSelected].setCharacterSize(85);
        mainMenu[MenuSelected].setStyle(1);
	}
}



void MenuLevel::startMenu()
{
    sf::RenderWindow menu(sf::VideoMode(width, height), "The running dead");

	menu.setPosition(Vector2i(300,0));

	//mainmenu
	RectangleShape background;
	background.setSize(Vector2f(width, height));
	Texture Maintexture;
	Maintexture.loadFromFile("Texture/background.jpg");
	background.setTexture(&Maintexture);


	while (menu.isOpen())
	{
		Event event;

		while (menu.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
                menu.close();
			}

			if(event.type == Event::KeyReleased)
            {
                if(event.key.code == Keyboard::Up)
                {
                    MoveUp();
                    break;
                }
                if(event.key.code == Keyboard::Down)
                {
                    MoveDown();
                    break;
                }
                if(event.key.code == Keyboard::Return)
                {
                    Game game;

                    int x = MenuPressed();
                    if(x == 0)
                    {
                        game.setCurrentLevel(1);
                        game.startLevel(this);
                    }
                     if(x == 1)
                    {
                        game.setCurrentLevel(2);
                        game.startLevel(this);
                    }
                    if(x == 2)
                    {
                        game.setCurrentLevel(3);
                        game.startLevel(this);
                    }
                    if(x == 3){
                        menu.close();
                        break;
                    }
        }
    }
}

		menu.clear();

		menu.draw(background);

		draw(menu);

		menu.display();

		menu.clear();
}
}

void MenuLevel::levelFinish(int level)
{
    switch(level)
    {
        case 1:
            mainMenu[0].setFillColor(Color::Green);
            level1Succeed = true;
            break;

        case 2:
            mainMenu[1].setFillColor(Color::Green);
            level2Succeed = true;
            break;
        case 3:
            mainMenu[2].setFillColor(Color::Green);
            level3Succeed = true;
            break;

    }

}

int Menu::MenuPressed()
{
    return MenuSelected;
}
