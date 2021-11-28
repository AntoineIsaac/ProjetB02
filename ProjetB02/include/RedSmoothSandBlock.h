#ifndef REDSMOOTHSANDBLOCK_H
#define REDSMOOTHSANDBLOCK_H
#include "Platform.h"


class RedSmoothSandBlock : public Platform
{
    public:
        RedSmoothSandBlock(float xPosition, float yPosition);
        virtual ~RedSmoothSandBlock();
        RedSmoothSandBlock(const RedSmoothSandBlock& other);
        RedSmoothSandBlock& operator=(const RedSmoothSandBlock& other);

        string getType()const;
};

#endif // REDSMOOTHSANDBLOCK_H
