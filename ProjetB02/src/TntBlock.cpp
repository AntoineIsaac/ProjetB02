#include "../include/TntBlock.h"

TntBlock::TntBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 8, 16 * 0, 16, 16));
}

TntBlock::~TntBlock()
{
    //dtor
}

TntBlock::TntBlock(const TntBlock& other)
{
    //copy ctor
}

TntBlock& TntBlock::operator=(const TntBlock& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

string TntBlock::getType() const
{
    return "TntBlock";
}
