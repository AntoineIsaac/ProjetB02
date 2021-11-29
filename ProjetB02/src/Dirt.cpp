#include "../include/Dirt.h"

Dirt::Dirt(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 2, 16 * 0, 16, 16));
}

Dirt::~Dirt()
{
    //dtor
}

Dirt::Dirt(const Dirt& other)
{
    //copy ctor
}

Dirt& Dirt::operator=(const Dirt& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

string Dirt::getType() const
{
    return "Dirt";
}
