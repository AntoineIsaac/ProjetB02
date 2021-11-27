#ifndef NETHERFENCE_H
#define NETHERFENCE_H
#include "Platform.h"

class NetherFence : public Platform
{
    public:
        NetherFence(float xPosition, float yPosition);
        virtual ~NetherFence();
        NetherFence(const NetherFence& other);
        NetherFence& operator=(const NetherFence& other);

        string getType()const;
};

#endif // NETHERFENCE_H
