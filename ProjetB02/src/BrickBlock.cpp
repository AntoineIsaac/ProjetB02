#include "../include/BrickBlock.h"

BrickBlock::BrickBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 20, 16 * 12, 16, 16));
}

BrickBlock::~BrickBlock()
{
    //dtor
}

BrickBlock::BrickBlock(const BrickBlock& other)
{
    //copy ctor
}

BrickBlock& BrickBlock::operator=(const BrickBlock& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

string BrickBlock::getType() const
{
    return "BrickBlock";
}
