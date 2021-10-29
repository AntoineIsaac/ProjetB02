#ifndef INPUT_H
#define INPUT_H
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;


class Input
{
    struct Button {
		bool left, right, space, escape;
	};

    private:
        Button button;

    public:
        Input();
        virtual ~Input();
        Input(const Input& other);
        Input& operator=(const Input& other);


        Button GetButton() const;
        void InputHandler(Event event, RenderWindow& window);


};

#endif // INPUT_H
