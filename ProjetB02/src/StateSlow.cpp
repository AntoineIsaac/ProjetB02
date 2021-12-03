#include "../include/StateSlow.h"

StateSlow::StateSlow()
{}

StateSlow::StateSlow(Player* player):State(player)
{
}

StateSlow::~StateSlow()
{}

StateSlow::StateSlow(const StateSlow& other):State(other)
{}

StateSlow& StateSlow::operator=(const StateSlow& rhs)
{
    if (this != &rhs)
    {
        State::operator=(rhs);
    }
    return *this;
}

void StateSlow::setSlow(float fps)
{
    player->setXSpeed(2 * fps);
}

void StateSlow::setNormal(float fps)
{}

void StateSlow::setSpeed(float fps)
{}
