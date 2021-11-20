#include "../include/GrassBlock.h"

GrassBlock::GrassBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 3, 16 * 0, 16, 16));
}

GrassBlock::~GrassBlock()
{
    //dtor
}

GrassBlock::GrassBlock(const GrassBlock& other):Platform(other)
{
    //copy ctor
}

GrassBlock& GrassBlock::operator=(const GrassBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

float GrassBlock::getXPosition()const
{
    return Platform::getXPosition();
}

void GrassBlock::setXPosition(float x)
{
    Platform::setXPosition(x);
}

float GrassBlock::getYPosition()const
{
    return Platform::getYPosition();
}

void GrassBlock::setYPosition(float y)
{
    Platform::setYPosition(y);
}

Sprite GrassBlock::getSprite()const
{
    return Platform::getSprite();
}

void GrassBlock::setSprite(string textureString, IntRect coord)
{
    Platform::setSprite(textureString, coord);
}

int GrassBlock::getType() const
{
    return 1;
}

