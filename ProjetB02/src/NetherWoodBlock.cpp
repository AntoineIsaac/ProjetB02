#include "../include/NetherWoodBlock.h"

NetherWoodBlock::NetherWoodBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 7, 16 * 32, 16, 16));
}

NetherWoodBlock::~NetherWoodBlock()
{
    //dtor
}

NetherWoodBlock::NetherWoodBlock(const NetherWoodBlock& other):Platform(other)
{
    //copy ctor
}

NetherWoodBlock& NetherWoodBlock::operator=(const NetherWoodBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

float NetherWoodBlock::getXPosition()const
{
    return Platform::getXPosition();
}

void NetherWoodBlock::setXPosition(float x)
{
    Platform::setXPosition(x);
}

float NetherWoodBlock::getYPosition()const
{
    return Platform::getYPosition();
}

void NetherWoodBlock::setYPosition(float y)
{
    Platform::setYPosition(y);
}

Sprite NetherWoodBlock::getSprite()const
{
    return Platform::getSprite();
}

void NetherWoodBlock::setSprite(string textureString, IntRect coord)
{
    Platform::setSprite(textureString, coord);
}

int NetherWoodBlock::getType() const
{
    return 8;
}

