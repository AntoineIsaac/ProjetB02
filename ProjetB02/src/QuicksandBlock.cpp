#include "../include/QuicksandBlock.h"

QuicksandBlock::QuicksandBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 0, 16 * 13, 16, 16));
}

QuicksandBlock::~QuicksandBlock()
{
    //dtor
}

QuicksandBlock::QuicksandBlock(const QuicksandBlock& other):Platform(other)
{
    //copy ctor
}

QuicksandBlock& QuicksandBlock::operator=(const QuicksandBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

string QuicksandBlock::getType() const
{
    return "QuicksandBlock";
}
