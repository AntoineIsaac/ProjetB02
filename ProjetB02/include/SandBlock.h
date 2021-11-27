#ifndef SANDBLOCK_H
#define SANDBLOCK_H
#include "Platform.h"


class SandBlock : public Platform
{
    public:
        SandBlock(float xPosition, float yPosition);
        virtual ~SandBlock();
        SandBlock(const SandBlock& other);
        SandBlock& operator=(const SandBlock& other);

        string getType()const;
};

#endif // SANDBLOCK_H
