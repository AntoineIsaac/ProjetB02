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

float ObsidianBlock::getXPosition()const
{
    return Platform::getXPosition();
}

void ObsidianBlock::setXPosition(float x)
{
    Platform::setXPosition(x);
}

float ObsidianBlock::getYPosition()const
{
    return Platform::getYPosition();
}

void ObsidianBlock::setYPosition(float y)
{
    Platform::setYPosition(y);
}

Sprite ObsidianBlock::getSprite()const
{
    return Platform::getSprite();
}

void ObsidianBlock::setSprite(string textureString, IntRect coord)
{
    Platform::setSprite(textureString, coord);
}

int ObsidianBlock::getType() const
{
    return 5;
}
