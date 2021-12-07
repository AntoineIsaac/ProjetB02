#include "../include/Menu.h"

Menu::Menu()
{
	if (!font.loadFromFile("Fonts/CottonButter.ttf"))
	{
		cout <<"No font is here";
	}

	if (!buffer.loadFromFile("sounds/select_option.wav"))
	{
		cout <<"No sound is here";
	}

	sound.setBuffer(buffer);


	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::Blue);
	mainMenu[0].setString("Play");
	mainMenu[0].setCharacterSize(85);
	mainMenu[0].setPosition(350, 200);
	mainMenu[0].setStyle(1);

	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setString("About");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition(350, 300);

	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::White);
	mainMenu[2].setString("Exit");
	mainMenu[2].setCharacterSize(70);
	mainMenu[2].setPosition(350, 400);

	MenuSelected = 0;
}


Menu::~Menu()
{
}

void Menu::draw(RenderWindow &window)
{
	for (int i = 0; i < Max_main_menu; i++)
	{
		window.draw(mainMenu[i]);
	}
}

void Menu::MoveUp()
{
	if (MenuSelected - 1 >= 0)
	{
        mainMenu[MenuSelected].setFillColor(Color::White);
        mainMenu[MenuSelected].setCharacterSize(70);
        mainMenu[MenuSelected].setStyle(0);


		MenuSelected--;
		if(MenuSelected == -1)
        {
            MenuSelected = 2;
        }

        mainMenu[MenuSelected].setFillColor(Color::Blue);
        mainMenu[MenuSelected].setCharacterSize(85);
        mainMenu[MenuSelected].setStyle(1);

	}
}

void Menu::MoveDown()
{
	if (MenuSelected + 1 <= Max_main_menu)
	{
        mainMenu[MenuSelected].setFillColor(Color::White);
        mainMenu[MenuSelected].setCharacterSize(70);
        mainMenu[MenuSelected].setStyle(0);


		MenuSelected++;
		if(MenuSelected == 3)
        {
            MenuSelected = 0;
        }

        mainMenu[MenuSelected].setFillColor(Color::Blue);
        mainMenu[MenuSelected].setCharacterSize(85);
        mainMenu[MenuSelected].setStyle(1);
	}
}


Menu::Menu(const Menu& other)
{
    //copy ctor
}

Menu& Menu::operator=(const Menu& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void Menu::startMenu()
{
    sf::RenderWindow menu(sf::VideoMode(width, height), "The running dead");

    menu.setPosition(Vector2i(300,0));

    //mainmenu
    RectangleShape background;
    background.setSize(Vector2f(width, height));
    Texture Maintexture;
    Maintexture.loadFromFile("Texture/background.jpg");
    background.setTexture(&Maintexture);

    //about
    RectangleShape Aboutbackground;
    Aboutbackground.setSize(Vector2f(width, height));
    Aboutbackground.setFillColor(Color(168,227,238));


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
                    sound.play();
                    Game game;

                    int x = MenuPressed();
                    if(x == 0)
                    {
                        MenuLevel menuLevel;
                        menuLevel.startMenuLevel();
                    }
                     if(x == 1)
                    {
                        RenderWindow about(VideoMode(width, height), "about");
                        about.setPosition(Vector2i(300,0));

                        while(about.isOpen())
                        {
                            Event aevent;
                            while(about.pollEvent(aevent))
                            {
                                if(aevent.type == Event::Closed)
                                {
                                    about.close();
                                }

                                if(aevent.type == Event::KeyPressed)
                                {
                                    if(aevent.key.code == Keyboard::Escape)
                                    {
                                        about.close();
                                    }
                                }
                            }
                            Text titleAbout;
                            titleAbout.setFont(font);
                            titleAbout.setString("About");
                            titleAbout.setPosition(400, 10);
                            titleAbout.setCharacterSize(48);
                            titleAbout.setStyle(1 << 2);


                            Text textAbout;
                            textAbout.setFont(font);
                            textAbout.setCharacterSize(20);
                            textAbout.setString("The game was created by 3rd year students in management computing.\nOur game is a platform video game based on the game 'New Super Mario Bros'. \nIn this one, you have just one goal : arrive at the end of all the levels that we created. \nWe have tree levels with their specificities. It's your job to find which blocks can kill you and which blocks belong to the decor. \nIf you run on a death block, you will die immediately. If you run on a decor block, you will cross the platform and fall into the void .\nOn the first level, be careful not to sting yourself, and don't get dragged into quicksand . \nAbout the second level, don't forget that lava can burn you ! \nAnd for the last level, be careful not to explode. \nDuring all the gameplay, you will meet zombies, and you have to avoid it, and avoid the death in the same time. \nFinally, for finish a level, you have to cross the end portal, it will teleport you in an other dimension ! \n\n                                                              Enjoy yourself, and keep running :)");
                            textAbout.setPosition(10, 70);

                            about.clear();
                            about.draw(Aboutbackground);
                            about.draw(textAbout);
                            about.draw(titleAbout);



                            about.display();
                }
            }
            if(x == 2)
                menu.close();
            break;
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

int MenuLevel::MenuPressed()
{
    return MenuSelected;
}


