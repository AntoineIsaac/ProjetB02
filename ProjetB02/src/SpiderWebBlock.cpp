#include "../include/SpiderWebBlock.h"

SpiderWebBlock::SpiderWebBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 11, 16 * 0, 16, 16));
}

SpiderWebBlock::~SpiderWebBlock()
{
    //dtor
}

SpiderWebBlock::SpiderWebBlock(const SpiderWebBlock& other):Platform(other)
{
    //copy ctor
}

SpiderWebBlock& SpiderWebBlock::operator=(const SpiderWebBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

string SpiderWebBlock::getType() const
{
    return "SpiderWebBlock";
}
