#include "../include/NetherBlock.h"

NetherBlock::NetherBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 23, 16 * 22, 16, 16));
}

NetherBlock::~NetherBlock()
{
    //dtor
}

NetherBlock::NetherBlock(const NetherBlock& other):Platform(other)
{
    //copy ctor
}

NetherBlock& NetherBlock::operator=(const NetherBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

float NetherBlock::getXPosition()const
{
    return Platform::getXPosition();
}

void NetherBlock::setXPosition(float x)
{
    Platform::setXPosition(x);
}

float NetherBlock::getYPosition()const
{
    return Platform::getYPosition();
}

void NetherBlock::setYPosition(float y)
{
    Platform::setYPosition(y);
}

Sprite NetherBlock::getSprite()const
{
    return Platform::getSprite();
}

void NetherBlock::setSprite(string textureString, IntRect coord)
{
    Platform::setSprite(textureString, coord);
}

int NetherBlock::getType() const
{
    return 4;
}
