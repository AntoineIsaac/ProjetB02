#include "../include/State.h"

State::State()
{}

State::State(Player* player): player(player)
{}

State::~State()
{}

State::State(const State& other): player(other.player)
{
}

State& State::operator=(const State& rhs)
{
    if (this != &rhs)
    {
        player = rhs.player;
    }
    return *this;
}


void State::setSlow(float fps)
{}

void State::setNormal(float fps)
{}

void State::setSpeed(float fps)
{}

void State::setPlayer(Player* player)
{
    this->player = player;
}
