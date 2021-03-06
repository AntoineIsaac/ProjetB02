#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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

    public:
        Entity(float xPosition, float yPosition, string textureString);
        virtual ~Entity();
        Entity(const Entity& other);
        Entity& operator=(const Entity& other);


        //Getters and setters
        virtual Sprite getSprite()const;
        virtual Texture getTexture()const;
        virtual void loadTexture()=0;

        virtual float getXPosition()const;
        virtual float getYPosition()const;
        virtual void setXPosition(float x);
        virtual void setYPosition(float y);

        virtual float getXSpeed()const;
        virtual float getYSpeed()const;
        virtual void setXSpeed(float xSpeed);
        virtual void setYSpeed(float ySpeed);

        //Redéfinitions des méthode SFML
        virtual void setPosition(float x, float y);
        virtual void move(float x, float y);
        virtual void setScale(float x);
        virtual FloatRect getGlobalBounds();



};

#endif // ENTITY_H
