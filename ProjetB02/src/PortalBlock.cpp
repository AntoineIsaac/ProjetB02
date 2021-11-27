#include "../include/PortalBlock.h"

PortalBlock::PortalBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 20, 16 * 1, 16, 16));
}

PortalBlock::~PortalBlock()
{
    //dtor
}

PortalBlock::PortalBlock(const PortalBlock& other):Platform(other)
{
    //copy ctor
}

PortalBlock& PortalBlock::operator=(const PortalBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

int PortalBlock::getType() const
{
    return 6;
}
