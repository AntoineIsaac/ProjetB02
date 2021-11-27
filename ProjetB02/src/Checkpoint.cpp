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

string Checkpoint::getType() const
{
    return "Checkpoint";
}
