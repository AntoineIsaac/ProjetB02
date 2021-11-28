#include "../include/NetherLianaBlock.h"

NetherLianaBlock::NetherLianaBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 5, 16 * 15, 16, 16));
}

NetherLianaBlock::~NetherLianaBlock()
{
    //dtor
}

NetherLianaBlock::NetherLianaBlock(const NetherLianaBlock& other):Platform(other)
{
    //copy ctor
}

NetherLianaBlock& NetherLianaBlock::operator=(const NetherLianaBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

string NetherLianaBlock::getType() const
{
    return "NetherLianaBlock";
}
