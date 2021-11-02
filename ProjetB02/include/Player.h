#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include <string>
#include <iostream>
#include <cmath>


class Player : public Entity
{
    private :
        float scale = 0.5;
        float hitBoxWidth[2] = {80*scale, 280*scale};
        float hitBoxHeight[2] = {20*scale, 490*scale};

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
        void setScale(float x);
        FloatRect getLocalBounds();

        float getXSpeed()const;
        float getYSpeed()const;
        void setXSpeed(float xSpeed);
        void setYSpeed(float ySpeed);

        //Functions
        void update(bool left, bool right, bool space, float fps, float groundHeight);
        void collision(int &newXPosition, int &newYposition);
};

#endif // PLAYER_H
