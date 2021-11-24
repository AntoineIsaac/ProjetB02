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

float PortalBlock::getXPosition()const
{
    return Platform::getXPosition();
}

void PortalBlock::setXPosition(float x)
{
    Platform::setXPosition(x);
}

float PortalBlock::getYPosition()const
{
    return Platform::getYPosition();
}

void PortalBlock::setYPosition(float y)
{
    Platform::setYPosition(y);
}

Sprite PortalBlock::getSprite()const
{
    return Platform::getSprite();
}

void PortalBlock::setSprite(string textureString, IntRect coord)
{
    Platform::setSprite(textureString, coord);
}

int PortalBlock::getType() const
{
    return 6;
}
