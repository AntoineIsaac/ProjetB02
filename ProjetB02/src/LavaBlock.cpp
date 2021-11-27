#include "../include/LavaBlock.h"

LavaBlock::LavaBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 22, 16 * 22, 16, 16));
}

LavaBlock::~LavaBlock()
{
    //dtor
}

LavaBlock::LavaBlock(const LavaBlock& other):Platform(other)
{
    //copy ctor
}

LavaBlock& LavaBlock::operator=(const LavaBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

string LavaBlock::getType() const
{
    return "LavaBlock";
}

