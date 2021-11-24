#include "../include/LeafBlock.h"

LeafBlock::LeafBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 5, 16 * 8, 16, 16));
}

LeafBlock::~LeafBlock()
{
    //dtor
}

LeafBlock::LeafBlock(const LeafBlock& other):Platform(other)
{
    //copy ctor
}

LeafBlock& LeafBlock::operator=(const LeafBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

float LeafBlock::getXPosition()const
{
    return Platform::getXPosition();
}

void LeafBlock::setXPosition(float x)
{
    Platform::setXPosition(x);
}

float LeafBlock::getYPosition()const
{
    return Platform::getYPosition();
}

void LeafBlock::setYPosition(float y)
{
    Platform::setYPosition(y);
}

Sprite LeafBlock::getSprite()const
{
    return Platform::getSprite();
}

void LeafBlock::setSprite(string textureString, IntRect coord)
{
    Platform::setSprite(textureString, coord);
}

int LeafBlock::getType() const
{
    return 9;
}
