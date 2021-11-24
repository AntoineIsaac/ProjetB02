#include "../include/JackOLanternBlock.h"

JackOLanternBlock::JackOLanternBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 7, 16 * 7, 16, 16));
}

JackOLanternBlock::~JackOLanternBlock()
{
    //dtor
}

JackOLanternBlock::JackOLanternBlock(const JackOLanternBlock& other):Platform(other)
{
    //copy ctor
}

JackOLanternBlock& JackOLanternBlock::operator=(const JackOLanternBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

float JackOLanternBlock::getXPosition()const
{
    return Platform::getXPosition();
}

void JackOLanternBlock::setXPosition(float x)
{
    Platform::setXPosition(x);
}

float JackOLanternBlock::getYPosition()const
{
    return Platform::getYPosition();
}

void JackOLanternBlock::setYPosition(float y)
{
    Platform::setYPosition(y);
}

Sprite JackOLanternBlock::getSprite()const
{
    return Platform::getSprite();
}

void JackOLanternBlock::setSprite(string textureString, IntRect coord)
{
    Platform::setSprite(textureString, coord);
}

void JackOLanternBlock::switchCheckpoint()
{
    activated = !activated;
    if(activated == true)
    {
        setSprite("Images/blocks.png", IntRect(16 * 8, 16 * 7, 16, 16));
    }
}

bool JackOLanternBlock::isActivated()const
{
    return activated;
}

int JackOLanternBlock::getType() const
{
    return 4;
}
