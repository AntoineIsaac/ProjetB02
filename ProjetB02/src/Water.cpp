#include "../include/Water.h"

Water::Water(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 10, 16 * 18, 16, 16));
}

Water::~Water()
{
    //dtor
}

Water::Water(const Water& other)
{
    //copy ctor
}

Water& Water::operator=(const Water& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}


string Water::getType() const
{
    return "Water";
}
