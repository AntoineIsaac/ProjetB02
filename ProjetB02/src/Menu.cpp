#include "../include/Menu.h"

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("Fonts/CottonButter.ttf"))
	{
		cout <<"No font is here";
	}

	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::White);
	mainMenu[0].setString("Play");
	mainMenu[0].setCharacterSize(70);
	mainMenu[0].setPosition(400, 200);

	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setString("Options");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition(400, 300);

	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::White);
	mainMenu[2].setString("About");
	mainMenu[2].setCharacterSize(70);
	mainMenu[2].setPosition(400, 400);

	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(Color::White);
	mainMenu[3].setString("Exit");
	mainMenu[3].setCharacterSize(70);
	mainMenu[3].setPosition(400, 500);

	MenuSelected = -1;
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

		MenuSelected--;
		if(MenuSelected == -1)
        {
            MenuSelected = 2;
        }

		mainMenu[MenuSelected].setFillColor(Color::Blue);
	}
}

void Menu::MoveDown()
{
	if (MenuSelected + 1 <= Max_main_menu)
	{
		mainMenu[MenuSelected].setFillColor(Color::White);

		MenuSelected++;
		if(MenuSelected == 4)
        {
            MenuSelected = 0;
        }

		mainMenu[MenuSelected].setFillColor(Color::Blue);
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
    sf::RenderWindow menu(sf::VideoMode(960, 720), "SFML WORK!");

	menu.setPosition(Vector2i(300,0));

	Menu mainMenu(menu.getSize().x, menu.getSize().y);

	//mainmenu
	RectangleShape background;
	background.setSize(Vector2f(960, 720));
	Texture Maintexture;
	Maintexture.loadFromFile("Texture/background.jpg");
	background.setTexture(&Maintexture);

	//options
	RectangleShape Optionsbackground;
	Optionsbackground.setSize(Vector2f(960, 720));
	Texture options_texture;
	options_texture.loadFromFile("Texture/options.jpg");
	Optionsbackground.setTexture(&options_texture);

	//about
	RectangleShape Aboutbackground;
	Aboutbackground.setSize(Vector2f(960, 720));
	Texture about_texture;
	about_texture.loadFromFile("Texture/about.jpg");
	Aboutbackground.setTexture(&about_texture);


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
                    mainMenu.MoveUp();
                    break;
                }
                if(event.key.code == Keyboard::Down)
                {
                    mainMenu.MoveDown();
                    break;
                }
                if(event.key.code == Keyboard::Return)
                {

                    Game game;

                    RenderWindow Options(VideoMode(960, 720), "options");
                    Options.setPosition(Vector2i(300,0));
                    RenderWindow about(VideoMode(960, 720), "about");
                    about.setPosition(Vector2i(300,0));

                    int x = mainMenu.MenuPressed();
                    if(x == 0)
                    {
                        game.startLevel1();
                    }
                    if(x == 1)
                    {
                        while(Options.isOpen())
                        {
                            Event aevent;
                            while(Options.pollEvent(aevent))
                            {
                                if(aevent.type == Event::Closed)
                                {
                                    Options.close();
                                }

                                if(aevent.type == Event::KeyPressed)
                                {
                                    if(aevent.key.code == Keyboard::Escape)
                                    {
                                        Options.close();
                                    }
                                }
                            }

                            Options.clear();
                            Options.draw(Optionsbackground);
                            about.close();

                            Options.display();

                        }
                    }
                     if(x == 2)
                    {
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

                            Options.clear();
                            about.clear();
                            about.draw(Aboutbackground);

                            about.display();
                }
            }
            if(x == 3)
                menu.close();
            break;
		}
    }
}

		menu.clear();

		menu.draw(background);

		mainMenu.draw(menu);

		menu.display();

}
}

