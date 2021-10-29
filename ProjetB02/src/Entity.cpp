#include "../include/Entity.h"

Entity::Entity(int speed, int xPosition, int yPosition, Sprite sprite):speed(speed), xPosition(xPosition), yPosition(yPosition), sprite(sprite)
{

}

Entity::~Entity()
{

}

Entity::Entity(const Entity& other):speed(other.speed), xPosition(other.xPosition), yPosition(other.yPosition), sprite(other.sprite)
{
    //copy ctor
}

Entity& Entity::operator=(const Entity& rhs)
{
    if (this != &rhs)
    {
        speed = rhs.speed;
        xPosition = rhs.xPosition;
        yPosition = rhs.yPosition;
        sprite = rhs.sprite;
    }

    return *this;
}

Sprite Entity::getSprite()const
{
    return sprite;
}

int Entity::getXPosition()const
{
    return xPosition;
}

int Entity::getYPosition()const
{
    return yPosition;
}

void Entity::setXPosition(int x)
{
    this->xPosition = x;
}

void Entity::setYPosition(int y)
{
    this->yPosition = y;
}

int Entity::getSpeed()const
{
    return speed;
}
