#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include <string>
#include <iostream>


class Player : public Entity
{
    private :

    public:
        Player(float xPosition, float yPosition, string textureString);
        virtual ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);

        //Getters and setters
        Sprite getSprite()const;

        float getXPosition()const;
        float getYPosition()const;
        void setXPosition(float x);
        void setYPosition(float y);

        //Redefinition of sprite method
        void setPosition(float x, float y);
        void move(float x, float y);

        float getSpeed()const;
        void setSpeed(float speed);

        //Functions
        void update(bool left, bool right, bool space, float fps);
};

#endif // PLAYER_H
