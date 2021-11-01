#ifndef PLATFORM_H
#define PLATFORM_H
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;


class Platform
{
    private:
        float xPosition;
        float yPosition;
        Texture texture;
        Sprite sprite;

    public:
        Platform(float xPosition, float yPosition);
        virtual ~Platform();
        Platform(const Platform& other);
        Platform& operator=(const Platform& other);

        //Getters and setters
        virtual float getXPosition()const;
        virtual void setXPosition(float x);

        virtual float getYPosition()const;
        virtual void setYPosition(float y);

        virtual Sprite getSprite()const;
        virtual void setSprite(string textureString, IntRect coord);

};

#endif // PLATFORM_H
