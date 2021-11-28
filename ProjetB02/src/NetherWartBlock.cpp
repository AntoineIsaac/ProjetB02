#include "../include/NetherWartBlock.h"

NetherWartBlock::NetherWartBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 3, 16 * 14, 16, 16));
}

NetherWartBlock::~NetherWartBlock()
{
    //dtor
}

NetherWartBlock::NetherWartBlock(const NetherWartBlock& other):Platform(other)
{
    //copy ctor
}

NetherWartBlock& NetherWartBlock::operator=(const NetherWartBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

string NetherWartBlock::getType() const
{
    return "NetherWartBlock";
}
