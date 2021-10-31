#include "../include/Zombie.h"

Zombie::Zombie(float xPosition, float yPosition, string textureString):Entity(xPosition, yPosition, textureString)
{
    setSpeed(3.0);
}

Zombie::~Zombie()
{
    //dtor
}

Zombie::Zombie(const Zombie& other):Entity(other)
{
    //copy ctor
}

Zombie& Zombie::operator=(const Zombie& rhs)
{
    if(this != &rhs)
    {
        Entity::operator=(rhs);
    }
    return *this;
}

Sprite Zombie::getSprite()const
{
    return Entity::getSprite();
}

float Zombie::getXPosition()const
{
    return Entity::getXPosition();
}

float Zombie::getYPosition()const
{
    return Entity::getYPosition();
}

void Zombie::setXPosition(float x)
{
    Entity::setXPosition(x);
}

void Zombie::setYPosition(float y)
{
    Entity::setYPosition(y);
}

void Zombie::setPosition(float x, float y)
{
    Entity::setPosition(x, y);
}

void Zombie::move(float x, float y)
{
    Entity::move(x, y);
}

float Zombie::getSpeed()const
{
    return Entity::getSpeed();
}

void Zombie::setSpeed(float speed)
{
    Entity::setSpeed(speed);
}