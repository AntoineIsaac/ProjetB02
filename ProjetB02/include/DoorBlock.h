#ifndef DOORBLOCK_H
#define DOORBLOCK_H

#include "Platform.h"

class DoorBlock : public Platform
{
    public:
        DoorBlock(float xPosition, float yPosition);
        virtual ~DoorBlock();
        DoorBlock(const DoorBlock& other);
        DoorBlock& operator=(const DoorBlock& other);

        string getType()const;

    protected:

    private:
};

#endif // DOORBLOCK_H
