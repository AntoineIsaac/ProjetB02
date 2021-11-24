#include "../include/FireBlock.h"

FireBlock::FireBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 19, 16 * 3, 16, 16));
}

FireBlock::~FireBlock()
{
    //dtor
}

FireBlock::FireBlock(const FireBlock& other):Platform(other)
{
    //copy ctor
}

FireBlock& FireBlock::operator=(const FireBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

float FireBlock::getXPosition()const
{
    return Platform::getXPosition();
}

void FireBlock::setXPosition(float x)
{
    Platform::setXPosition(x);
}

float FireBlock::getYPosition()const
{
    return Platform::getYPosition();
}

void FireBlock::setYPosition(float y)
{
    Platform::setYPosition(y);
}

Sprite FireBlock::getSprite()const
{
    return Platform::getSprite();
}

void FireBlock::setSprite(string textureString, IntRect coord)
{
    Platform::setSprite(textureString, coord);
}

int FireBlock::getType() const
{
    return 10;
}
