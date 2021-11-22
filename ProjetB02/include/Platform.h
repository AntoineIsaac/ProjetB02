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
        static inline float scale = 3.5;
        static inline float size = 16*scale;

        Platform(float xPosition=0, float yPosition=0);
        virtual ~Platform();
        Platform(const Platform& other);
        Platform& operator=(const Platform& other);

        //Getters and setters
        virtual float getXPosition()const;
        virtual void setXPosition(float x);

        virtual float getYPosition()const;
        virtual void setYPosition(float y);
        virtual FloatRect getGlobalBounds();
        virtual float getSize();

        virtual Sprite getSprite()const;
        virtual void setSprite(string textureString, IntRect coord);

        virtual void setScale(float x);

        virtual int getType()const = 0;

};

#endif // PLATFORM_H
