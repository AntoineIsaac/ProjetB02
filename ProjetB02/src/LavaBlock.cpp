#include "../include/LavaBlock.h"

LavaBlock::LavaBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 11, 16 * 18, 16, 16));
}

LavaBlock::~LavaBlock()
{
    //dtor
}

LavaBlock::LavaBlock(const LavaBlock& other):Platform(other)
{
    //copy ctor
}

LavaBlock& LavaBlock::operator=(const LavaBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

float LavaBlock::getXPosition()const
{
    return Platform::getXPosition();
}

void LavaBlock::setXPosition(float x)
{
    Platform::setXPosition(x);
}

float LavaBlock::getYPosition()const
{
    return Platform::getYPosition();
}

void LavaBlock::setYPosition(float y)
{
    Platform::setYPosition(y);
}

Sprite LavaBlock::getSprite()const
{
    return Platform::getSprite();
}

void LavaBlock::setSprite(string textureString, IntRect coord)
{
    Platform::setSprite(textureString, coord);
}

int LavaBlock::getType() const
{
    return 2;
}

