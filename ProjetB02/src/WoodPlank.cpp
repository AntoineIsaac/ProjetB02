#include "../include/WoodPlank.h"

WoodPlank::WoodPlank(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 4, 16 * 0, 16, 16));
}

WoodPlank::~WoodPlank()
{
    //dtor
}

WoodPlank::WoodPlank(const WoodPlank& other)
{
    //copy ctor
}

WoodPlank& WoodPlank::operator=(const WoodPlank& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

string WoodPlank::getType() const
{
    return "WoodPlank";
}
