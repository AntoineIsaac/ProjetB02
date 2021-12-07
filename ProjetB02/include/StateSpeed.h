#ifndef STATESPEED_H
#define STATESPEED_H
#include "State.h"
#include "Player.h"

class StateSpeed: public State
{
    public:
        StateSpeed();
        StateSpeed(Player* player);
        virtual ~StateSpeed();
        StateSpeed(const StateSpeed& other);
        StateSpeed& operator=(const StateSpeed& other);

        void setSlow(float fps) override;

        void setNormal(float fps) override;

        void setSpeed(float fps) override;
};
#endif // STATESPEED_H
