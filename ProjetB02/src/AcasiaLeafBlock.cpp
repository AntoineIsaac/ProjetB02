#include "../include/AcasiaLeafBlock.h"

AcasiaLeafBlock::AcasiaLeafBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 20, 16 * 5, 16, 16));
}

AcasiaLeafBlock::~AcasiaLeafBlock()
{
    //dtor
}

AcasiaLeafBlock::AcasiaLeafBlock(const AcasiaLeafBlock& other):Platform(other)
{
    //copy ctor
}

AcasiaLeafBlock& AcasiaLeafBlock::operator=(const AcasiaLeafBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

string AcasiaLeafBlock::getType() const
{
    return "AcasiaLeafBlock";
}
