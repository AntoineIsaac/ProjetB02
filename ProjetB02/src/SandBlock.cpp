#include "../include/SandBlock.h"

SandBlock::SandBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 0, 16 * 12, 16, 16));
}

SandBlock::~SandBlock()
{
    //dtor
}

SandBlock::SandBlock(const SandBlock& other):Platform(other)
{
    //copy ctor
}

SandBlock& SandBlock::operator=(const SandBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

string SandBlock::getType() const
{
    return "SandBlock";
}
