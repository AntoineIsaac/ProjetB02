#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include <string>
#include <iostream>


class Player : public Entity
{
    private :

    public:
        Player(int speed, int xPosition, int yPosition, string textureString);
        virtual ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);

        //Getters and setters
        Sprite getSprite()const;

        int getXPosition()const;
        int getYPosition()const;
        void setXPosition(int x);
        void setYPosition(int y);
        int getSpeed()const;

        //Functions
        void update(bool left, bool right, bool space);
};

#endif // PLAYER_H
