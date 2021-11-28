#ifndef REDSANDBLOCK_H
#define REDSANDBLOCK_H
#include "Platform.h"


class RedSandBlock : public Platform
{
    public:
        RedSandBlock(float xPosition, float yPosition);
        virtual ~RedSandBlock();
        RedSandBlock(const RedSandBlock& other);
        RedSandBlock& operator=(const RedSandBlock& other);

        string getType()const;
};

#endif // REDSANDBLOCK_H
