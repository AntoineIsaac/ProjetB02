#include "../include/SmoothSandBlock.h"

SmoothSandBlock::SmoothSandBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 6, 16 * 14, 16, 16));
}

SmoothSandBlock::~SmoothSandBlock()
{
    //dtor
}

SmoothSandBlock::SmoothSandBlock(const SmoothSandBlock& other):Platform(other)
{
    //copy ctor
}

SmoothSandBlock& SmoothSandBlock::operator=(const SmoothSandBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

string SmoothSandBlock::getType() const
{
    return "SmoothSandBlock";
}
