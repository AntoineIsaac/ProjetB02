#include "../include/GrassBlock.h"

GrassBlock::GrassBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 3, 16 * 0, 16, 16));
}

GrassBlock::~GrassBlock()
{
    //dtor
}

GrassBlock::GrassBlock(const GrassBlock& other):Platform(other)
{
    //copy ctor
}

GrassBlock& GrassBlock::operator=(const GrassBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

int GrassBlock::getType() const
{
    return 1;
}

