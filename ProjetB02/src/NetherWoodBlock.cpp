#include "../include/NetherWoodBlock.h"

NetherWoodBlock::NetherWoodBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 7, 16 * 32, 16, 16));
}

NetherWoodBlock::~NetherWoodBlock()
{
    //dtor
}

NetherWoodBlock::NetherWoodBlock(const NetherWoodBlock& other):Platform(other)
{
    //copy ctor
}

NetherWoodBlock& NetherWoodBlock::operator=(const NetherWoodBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

int NetherWoodBlock::getType() const
{
    return 8;
}

