#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 800), "The running dead");

    window.setFramerateLimit(60);
    Clock clock;
    //float dt;
    //float multiplier = 60.f;
    //float fps;

    while (window.isOpen())
    {
        //dt = clock.restart().asSeconds();
        //fps = dt * multiplier;

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.display();
    }
    return 0;
}
