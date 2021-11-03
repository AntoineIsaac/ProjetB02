#include "../include/Platform.h"

Platform::Platform(float xPosition, float yPosition):xPosition(xPosition), yPosition(yPosition)
{
    //ctor
}

Platform::~Platform()
{
    //dtor
}

Platform::Platform(const Platform& other):xPosition(other.xPosition), yPosition(other.yPosition)
{
    //copy ctor
}

Platform& Platform::operator=(const Platform& rhs)
{
    if (this != &rhs)
    {
        xPosition = rhs.xPosition;
        yPosition = rhs.yPosition;
        sprite = rhs.sprite;
    }

    return *this;
}

float Platform::getXPosition()const
{
    return xPosition;
}

void Platform::setXPosition(float x)
{
    xPosition = x;
}

float Platform::getYPosition()const
{
    return yPosition;
}

void Platform::setYPosition(float y)
{
    yPosition = y;
}

FloatRect Platform::getGlobalBounds()
{
    return sprite.getGlobalBounds();
}

float Platform::getSize()
{
    return size;
}

Sprite Platform::getSprite()const
{
    return sprite;
}

void Platform::setSprite(string textureString, IntRect coord)
{
    texture.loadFromFile(textureString);
    sprite.setTexture(texture);
    sprite.setTextureRect(coord);
    sprite.setPosition(xPosition, yPosition);
}
