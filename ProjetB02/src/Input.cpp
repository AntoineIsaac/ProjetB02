#include "../include/Input.h"

Input::Input()
{
	button.left = button.right = button.space = button.escape = button.m = false;
}

Input::~Input()
{
    //dtor
}

Input::Input(const Input& other)
{
    //copy ctor
}

Input& Input::operator=(const Input& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

Input::Button Input::GetButton() const
{
	return button;
}

void Input::InputHandler(Event event, RenderWindow& window)
{
	//Fermer la fenêtre si on clique sur la croix
	if (event.type == Event::Closed)
	{
		window.close();
	}
	//Gestion des inputs (appuyés)
	if (event.type == Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case Keyboard::Escape:
			button.escape = true;
			break;
		case Keyboard::Left:
			button.left = true;
			break;
		case Keyboard::Right:
			button.right = true;
			break;
        case Keyboard::Space:
			button.space = true;
			break;
        case Keyboard::M:
			button.m = true;
			break;
		default:
			break;
		}
	}

	//Touce relachée
	if (event.type == Event::KeyReleased)
	{
		switch (event.key.code)
		{
		case Keyboard::Escape:
			button.escape = false;
			break;
		case Keyboard::Left:
			button.left = false;
			break;
		case Keyboard::Right:
			button.right = false;
			break;
		case Keyboard::Space:
			button.space = false;
			break;
        case Keyboard::M:
			button.m = false;
			break;
		default:
			break;
		}
	}
}

