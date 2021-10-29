#include "../include/Entity.h"

Entity::Entity(int speed, int xPosition, int yPosition, string stringTexture):speed(speed), xPosition(xPosition), yPosition(yPosition)
{
    texture.loadFromFile(stringTexture);
}

Entity::~Entity()
{
    //dtor
}

Entity::Entity(const Entity& other):speed(other.speed), xPosition(other.xPosition), yPosition(other.yPosition)
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
        texture = rhs.texture;
    }

    return *this;
}
