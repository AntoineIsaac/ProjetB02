#include "../include/StateNormal.h"

StateNormal::StateNormal()
{}

StateNormal::StateNormal(Player* player):State(player)
{
}

StateNormal::~StateNormal()
{}

StateNormal::StateNormal(const StateNormal& other):State(other)
{}

StateNormal& StateNormal::operator=(const StateNormal& rhs)
{
    if (this != &rhs)
    {
        State::operator=(rhs);
    }
    return *this;
}

void StateNormal::setSlow(float fps)
{}

void StateNormal::setSpeed(float fps)
{}

void StateNormal::setNormal(float fps)
{
    player->setXSpeed(5 * fps);
}
