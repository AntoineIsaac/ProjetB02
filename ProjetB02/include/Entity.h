#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;


class Entity
{
    protected:
        float xSpeed;
        float ySpeed;
        float xPosition;
        float yPosition;
        string textureString;
        Texture texture;
        Sprite sprite;
        enum Direction{gauche, droite};
        Direction direction = Direction::droite;

    public:
        Entity(float xPosition, float yPosition, string textureString);
        virtual ~Entity();
        Entity(const Entity& other);
        Entity& operator=(const Entity& other);


        //Getters and setters
        virtual Sprite getSprite()const=0;
        virtual Texture getTexture()const;
        virtual void loadTexture()=0;

        virtual float getXPosition()const;
        virtual float getYPosition()const;
        virtual void setXPosition(float x);
        virtual void setYPosition(float y);

        virtual void setPosition(float x, float y)=0;
        virtual void move(float x, float y);
        virtual void setScale(float x)=0;
        virtual FloatRect getGlobalBounds();

        virtual float getXSpeed()const=0;
        virtual float getYSpeed()const=0;
        virtual void setXSpeed(float xSpeed)=0;
        virtual void setYSpeed(float ySpeed)=0;

};

#endif // ENTITY_H
