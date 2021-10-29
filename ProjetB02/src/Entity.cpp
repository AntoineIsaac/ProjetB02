#include "Entity.h"

Entity::Entity(int speed, int xPosition, int yPosition):speed(speed), xPosition(xPosition), yPosition(yPosition)
{
    //ctor
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
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
