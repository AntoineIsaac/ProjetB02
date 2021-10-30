#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;


class Entity
{
    private:
        int speed;
        int xPosition;
        int yPosition;
        string textureString;
        Texture texture;
        Sprite sprite;

    public:
        Entity(int speed, int xPosition, int yPosition, string textureString);
        virtual ~Entity();
        Entity(const Entity& other);
        Entity& operator=(const Entity& other);


        //Getters and setters
        virtual Sprite getSprite()const=0;


        virtual int getXPosition()const=0;
        virtual int getYPosition()const=0;
        virtual void setXPosition(int x)=0;
        virtual void setYPosition(int y)=0;

        virtual int getSpeed()const=0;

};

#endif // ENTITY_H
