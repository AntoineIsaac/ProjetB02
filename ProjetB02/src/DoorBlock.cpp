#include "../include/DoorBlock.h"

DoorBlock::DoorBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 1, 16 * 5, 16, 32));
}

DoorBlock::~DoorBlock()
{
    //dtor
}

DoorBlock::DoorBlock(const DoorBlock& other)
{
    //copy ctor
}

DoorBlock& DoorBlock::operator=(const DoorBlock& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

string DoorBlock::getType() const
{
    return "DoorBlock";
}
