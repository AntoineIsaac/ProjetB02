#include "../include/RedQuicksandBlock.h"

RedQuicksandBlock::RedQuicksandBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 11, 16 * 20, 16, 16));
}

RedQuicksandBlock::~RedQuicksandBlock()
{
    //dtor
}

RedQuicksandBlock::RedQuicksandBlock(const RedQuicksandBlock& other):Platform(other)
{
    //copy ctor
}

RedQuicksandBlock& RedQuicksandBlock::operator=(const RedQuicksandBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

string RedQuicksandBlock::getType() const
{
    return "RedQuicksandBlock";
}
