#include "../include/Player.h"

Player::Player(int speed, int xPosition, int yPosition, Sprite sprite):Entity(speed, xPosition, yPosition, sprite)
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

Sprite Player::getSprite()const
{
    return Entity::getSprite();
}
