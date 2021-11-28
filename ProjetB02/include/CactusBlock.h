#ifndef CACTUSBLOCK_H
#define CACTUSBLOCK_H
#include "Platform.h"


class CactusBlock : public Platform
{
    public:
        CactusBlock(float xPosition, float yPosition);
        virtual ~CactusBlock();
        CactusBlock(const CactusBlock& other);
        CactusBlock& operator=(const CactusBlock& other);

        string getType()const;
};

#endif // CACTUSBLOCK_H
