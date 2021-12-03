#include "../include/StateSpeed.h"

StateSpeed::StateSpeed()
{}

StateSpeed::StateSpeed(Player* player):State(player)
{
}

StateSpeed::~StateSpeed()
{}

StateSpeed::StateSpeed(const StateSpeed& other):State(other)
{}

StateSpeed& StateSpeed::operator=(const StateSpeed& rhs)
{
    if (this != &rhs)
    {
        State::operator=(rhs);
    }
    return *this;
}

void StateSpeed::setSpeed(float fps)
{
    player->setXSpeed(15 * fps);
}

void StateSpeed::setNormal(float fps)
{}

void StateSpeed::setSlow(float fps)
{}
