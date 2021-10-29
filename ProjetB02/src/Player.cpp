#include "../include/Player.h"

Player::Player(int speed, int xPosition, int yPosition, string stringTexture):Entity(speed, xPosition, yPosition, stringTexture)
{

}

Player::~Player()
{
    //dtor
}

Player::Player(const Player& other):Entity(other)
{
    //copy ctor
}

Player& Player::operator=(const Player& rhs)
{
    if(this != &rhs)
    {
        Entity::operator=(rhs);
    }
    return *this;
}
