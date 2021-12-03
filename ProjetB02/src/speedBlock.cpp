#include "../include/speedBlock.h"

speedBlock::speedBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 10, 16 * 28, 16, 16));
}

speedBlock::~speedBlock()
{
    //dtor
}

speedBlock::speedBlock(const speedBlock& other):Platform(other)
{
    //copy ctor
}

speedBlock& speedBlock::operator=(const speedBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

string speedBlock::getType() const
{
    return "speedBlock";
}
