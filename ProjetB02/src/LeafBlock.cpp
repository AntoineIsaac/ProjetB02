#include "../include/LeafBlock.h"

LeafBlock::LeafBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 5, 16 * 8, 16, 16));
}

LeafBlock::~LeafBlock()
{
    //dtor
}

LeafBlock::LeafBlock(const LeafBlock& other):Platform(other)
{
    //copy ctor
}

LeafBlock& LeafBlock::operator=(const LeafBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

int LeafBlock::getType() const
{
    return 9;
}
