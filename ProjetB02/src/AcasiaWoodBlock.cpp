#include "../include/AcasiaWoodBlock.h"

AcasiaWoodBlock::AcasiaWoodBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 21, 16 * 16, 16, 16));
}

AcasiaWoodBlock::~AcasiaWoodBlock()
{
    //dtor
}

AcasiaWoodBlock::AcasiaWoodBlock(const AcasiaWoodBlock& other):Platform(other)
{
    //copy ctor
}

AcasiaWoodBlock& AcasiaWoodBlock::operator=(const AcasiaWoodBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

string AcasiaWoodBlock::getType() const
{
    return "AcasiaWoodBlock";
}
