#ifndef SMOOTHSANDBLOCK_H
#define SMOOTHSANDBLOCK_H
#include "Platform.h"


class SmoothSandBlock : public Platform
{
    public:
        SmoothSandBlock(float xPosition, float yPosition);
        virtual ~SmoothSandBlock();
        SmoothSandBlock(const SmoothSandBlock& other);
        SmoothSandBlock& operator=(const SmoothSandBlock& other);

        string getType()const;
};

#endif // SMOOTHSANDBLOCK_H
