#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;


class Entity
{
    private:
        float speed;
        float xPosition;
        float yPosition;
        string textureString;
        Texture texture;
        Sprite sprite;

    public:
        Entity(float xPosition, float yPosition, string textureString);
        virtual ~Entity();
        Entity(const Entity& other);
        Entity& operator=(const Entity& other);


        //Getters and setters
        virtual Sprite getSprite()const=0;


        virtual float getXPosition()const=0;
        virtual float getYPosition()const=0;
        virtual void setXPosition(float x)=0;
        virtual void setYPosition(float y)=0;

        virtual void setPosition(float x, float y)=0;
        virtual void move(float x, float y);

        virtual float getSpeed()const=0;
        virtual void setSpeed(float speed)=0;

};

#endif // ENTITY_H
