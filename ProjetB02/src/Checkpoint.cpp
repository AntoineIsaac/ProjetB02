#include "../include/Checkpoint.h"

Checkpoint::Checkpoint(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 7, 16 * 7, 16, 16));
}

Checkpoint::~Checkpoint()
{
    //dtor
}

Checkpoint::Checkpoint(const Checkpoint& other):Platform(other)
{
    //copy ctor
}

Checkpoint& Checkpoint::operator=(const Checkpoint& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

float Checkpoint::getXPosition()const
{
    return Platform::getXPosition();
}

void Checkpoint::setXPosition(float x)
{
    Platform::setXPosition(x);
}

float Checkpoint::getYPosition()const
{
    return Platform::getYPosition();
}

void Checkpoint::setYPosition(float y)
{
    Platform::setYPosition(y);
}

Sprite Checkpoint::getSprite()const
{
    return Platform::getSprite();
}

void Checkpoint::setSprite(string textureString, IntRect coord)
{
    Platform::setSprite(textureString, coord);
}

void Checkpoint::switchCheckpoint()
{
    activated = !activated;
    if(activated == true)
    {
        setSprite("Images/blocks.png", IntRect(16 * 8, 16 * 7, 16, 16));
    }
}

bool Checkpoint::isActivated()const
{
    return activated;
}

int Checkpoint::getType() const
{
    return 3;
}
