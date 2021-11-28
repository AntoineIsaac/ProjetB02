#include "../include/CactusBlock.h"

CactusBlock::CactusBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 6, 16 * 4, 16, 16));
}

CactusBlock::~CactusBlock()
{
    //dtor
}

CactusBlock::CactusBlock(const CactusBlock& other):Platform(other)
{
    //copy ctor
}

CactusBlock& CactusBlock::operator=(const CactusBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

string CactusBlock::getType() const
{
    return "CactusBlock";
}
