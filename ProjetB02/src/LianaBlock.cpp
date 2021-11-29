#include "../include/LianaBlock.h"

LianaBlock::LianaBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 15, 16 * 8, 16, 16));
}

LianaBlock::~LianaBlock()
{
    //dtor
}

LianaBlock::LianaBlock(const LianaBlock& other):Platform(other)
{
    //copy ctor
}

LianaBlock& LianaBlock::operator=(const LianaBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

string LianaBlock::getType() const
{
    return "LianaBlock";
}
