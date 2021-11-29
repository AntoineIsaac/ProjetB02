#include "../include/WheatBlock.h"

WheatBlock::WheatBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 16, 16 * 13, 16, 16));
}

WheatBlock::~WheatBlock()
{
    //dtor
}

WheatBlock::WheatBlock(const WheatBlock& other)
{
    //copy ctor
}

WheatBlock& WheatBlock::operator=(const WheatBlock& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}


string WheatBlock::getType() const
{
    return "WheatBlock";
}
