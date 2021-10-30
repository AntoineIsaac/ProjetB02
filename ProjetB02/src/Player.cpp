#include "../include/Player.h"

Player::Player(float xPosition, float yPosition, string textureString):Entity(xPosition, yPosition, textureString)
{
    setSpeed(5.0);
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

float Player::getXPosition()const
{
    return Entity::getXPosition();
}

float Player::getYPosition()const
{
    return Entity::getYPosition();
}

void Player::setXPosition(float x)
{
    Entity::setXPosition(x);
}

void Player::setYPosition(float y)
{
    Entity::setYPosition(y);
}

void Player::setPosition(float x, float y)
{
    Entity::setPosition(x, y);
}

void Player::move(float x, float y)
{
    Entity::move(x, y);
}

float Player::getSpeed()const
{
    return Entity::getSpeed();
}

void Player::setSpeed(float speed)
{
    Entity::setSpeed(speed);
}

void Player::update(bool left, bool right, bool space, float fps)
{
    if(left)
    {
        move((getXPosition() - getSpeed())*fps, 0);
    }
    if(right)
    {
        move((getXPosition() + getSpeed())*fps, 0);
    }
}
