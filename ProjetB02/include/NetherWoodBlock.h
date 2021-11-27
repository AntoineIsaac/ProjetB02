#ifndef NETHERWOODBLOCK_H
#define NETHERWOODBLOCK_H
#include "Platform.h"

class NetherWoodBlock : public Platform
{
    public:
        NetherWoodBlock(float xPosition, float yPosition);
        virtual ~NetherWoodBlock();
        NetherWoodBlock(const NetherWoodBlock& other);
        NetherWoodBlock& operator=(const NetherWoodBlock& other);

        int getType()const;
};

#endif // NETHERWOODBLOCK_H
