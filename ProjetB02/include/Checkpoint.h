#ifndef CHECKPOINT_H
#define CHECKPOINT_H
#include "Platform.h"

class Checkpoint : public Platform
{
    private:
        bool activated = false;

    public:
        Checkpoint(float xPosition, float yPosition);
        virtual ~Checkpoint();
        Checkpoint(const Checkpoint& other);
        Checkpoint& operator=(const Checkpoint& other);

        void switchCheckpoint();
        bool isActivated()const;

        string getType()const;
};

#endif // CHECKPOINT_H
