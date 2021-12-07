#ifndef STATENORMAL_H
#define STATENORMAL_H
#include "State.h"
#include "Player.h"

class StateNormal: public State
{
    public:
        StateNormal();
        StateNormal(Player* player);
        virtual ~StateNormal();
        StateNormal(const StateNormal& other);
        StateNormal& operator=(const StateNormal& other);

        void setSlow(float fps) override;

        void setNormal(float fps) override;

        void setSpeed(float fps) override;
};

#endif // STATENORMAL_H
