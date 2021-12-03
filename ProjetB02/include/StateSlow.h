#ifndef STATESLOW_H
#define STATESLOW_H
#include "State.h"
#include "Player.h"

class StateSlow: public State
{
    public:
        StateSlow();
        StateSlow(Player* player);
        virtual ~StateSlow();
        StateSlow(const StateSlow& other);
        StateSlow& operator=(const StateSlow& other);

        void setSlow(float fps) override;

        void setNormal(float fps) override;

        void setSpeed(float fps) override;

    protected:

    private:
};

#endif // STATESLOW_H
