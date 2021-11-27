#ifndef NETHERBLOCK_H
#define NETHERBLOCK_H
#include "Platform.h"


class NetherBlock : public Platform
{
    public:
        NetherBlock(float xPosition, float yPosition);
        virtual ~NetherBlock();
        NetherBlock(const NetherBlock& other);
        NetherBlock& operator=(const NetherBlock& other);

        string getType()const;
};

#endif // NETHERBLOCK_H
