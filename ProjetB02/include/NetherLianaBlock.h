#ifndef NETHERLIANABLOCK_H
#define NETHERLIANABLOCK_H
#include "Platform.h"

class NetherLianaBlock: public Platform
{
    public:
        NetherLianaBlock(float xPosition, float yPosition);
        virtual ~NetherLianaBlock();
        NetherLianaBlock(const NetherLianaBlock& other);
        NetherLianaBlock& operator=(const NetherLianaBlock& other);

        string getType()const;
};

#endif // NETHERLIANABLOCK_H
