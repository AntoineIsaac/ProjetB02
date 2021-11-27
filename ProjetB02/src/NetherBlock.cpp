#include "../include/NetherBlock.h"

NetherBlock::NetherBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 23, 16 * 22, 16, 16));
}

NetherBlock::~NetherBlock()
{
    //dtor
}

NetherBlock::NetherBlock(const NetherBlock& other):Platform(other)
{
    //copy ctor
}

NetherBlock& NetherBlock::operator=(const NetherBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

string NetherBlock::getType() const
{
    return "NetherBlock";
}
