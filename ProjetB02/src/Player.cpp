#include "../include/Player.h"

Player::Player(float xPosition, float yPosition, string textureString):Entity(xPosition, yPosition, textureString)
{
    setXSpeed(5.0);
    setYSpeed(10.0);
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

float Player::getXSpeed()const
{
    return Entity::getXSpeed();
}

float Player::getYSpeed()const
{
    return Entity::getYSpeed();
}

void Player::setXSpeed(float xSpeed)
{
    Entity::setXSpeed(xSpeed);
}

void Player::setYSpeed(float ySpeed)
{
    Entity::setYSpeed(ySpeed);
}

void Player::update(bool left, bool right, bool space, float fps, float groundHeight)
{
    if(left)
    {
        setXSpeed(-5.0);
        setPosition(getXPosition() + getXSpeed(), getYPosition());
    }
    if(right)
    {
        setXSpeed(5.0);
        setPosition(getXPosition() + getXSpeed(), getYPosition());
    }
    if(space && getYSpeed() > 0)
    {
        setYSpeed(-10.0);
        setPosition(getXPosition(), getYPosition() + getYSpeed() - 130.);
    }
    if(!space && getYPosition() < groundHeight)
    {
        setYSpeed(10.0);
        setPosition(getXPosition(), getYPosition() + getYSpeed());
    }

}
