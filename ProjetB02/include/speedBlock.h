#ifndef SPEEDBLOCK_H
#define SPEEDBLOCK_H
#include "Platform.h"


class speedBlock : public Platform
{
    public:
        speedBlock(float xPosition, float yPosition);
        virtual ~speedBlock();
        speedBlock(const speedBlock& other);
        speedBlock& operator=(const speedBlock& other);

        string getType()const;
};

#endif // SPEEDBLOCK_H
