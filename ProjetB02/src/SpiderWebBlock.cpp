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

float SpiderWebBlock::getXPosition()const
{
    return Platform::getXPosition();
}

void SpiderWebBlock::setXPosition(float x)
{
    Platform::setXPosition(x);
}

float SpiderWebBlock::getYPosition()const
{
    return Platform::getYPosition();
}

void SpiderWebBlock::setYPosition(float y)
{
    Platform::setYPosition(y);
}

Sprite SpiderWebBlock::getSprite()const
{
    return Platform::getSprite();
}

void SpiderWebBlock::setSprite(string textureString, IntRect coord)
{
    Platform::setSprite(textureString, coord);
}

int SpiderWebBlock::getType() const
{
    return 7;
}
