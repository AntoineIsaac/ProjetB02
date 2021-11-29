#include "../include/CloudBlock.h"

CloudBlock::CloudBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 2, 16 * 4, 16, 16));
}

CloudBlock::~CloudBlock()
{
    //dtor
}

CloudBlock::CloudBlock(const CloudBlock& other):Platform(other)
{
    //copy ctor
}

CloudBlock& CloudBlock::operator=(const CloudBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

string CloudBlock::getType() const
{
    return "CloudBlock";
}
