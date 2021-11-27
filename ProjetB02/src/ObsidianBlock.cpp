#include "../include/ObsidianBlock.h"

ObsidianBlock::ObsidianBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 7, 16 * 11, 16, 16));
}

ObsidianBlock::~ObsidianBlock()
{
    //dtor
}

ObsidianBlock::ObsidianBlock(const ObsidianBlock& other):Platform(other)
{
    //copy ctor
}

ObsidianBlock& ObsidianBlock::operator=(const ObsidianBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

string ObsidianBlock::getType() const
{
    return "ObsidianBlock";
}
