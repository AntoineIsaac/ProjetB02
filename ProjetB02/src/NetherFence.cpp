#include "../include/NetherFence.h"

NetherFence::NetherFence(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 22, 16 * 1, 16, 16));
}

NetherFence::~NetherFence()
{
    //dtor
}

NetherFence::NetherFence(const NetherFence& other):Platform(other)
{
    //copy ctor
}

NetherFence& NetherFence::operator=(const NetherFence& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

string NetherFence::getType() const
{
    return "NetherFence";
}
