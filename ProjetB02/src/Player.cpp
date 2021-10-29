#include "../include/Player.h"

Player::Player(int speed, int xPosition, int yPosition, Sprite sprite):Entity(speed, xPosition, yPosition, sprite)
{

}

Player::~Player()
{

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

int Player::getXPosition()const
{
    return Entity::getXPosition();
}

int Player::getYPosition()const
{
    return Entity::getYPosition();
}

void Player::setXPosition(int x)
{
    Entity::setXPosition(x);
}

void Player::setYPosition(int y)
{
    Entity::setYPosition(y);
}

int Player::getSpeed()const
{
    return Entity::getSpeed();
}

void Player::update(bool left, bool right, bool space)
{
    if(left)
    {
        getSprite().setPosition(Vector2f(getXPosition() - getSpeed(), getYPosition()));
    }
    if(right)
    {
        getSprite().setPosition(Vector2f(getXPosition() + getSpeed(), getYPosition()));
    }
}
