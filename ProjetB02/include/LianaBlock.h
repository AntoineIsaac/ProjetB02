#ifndef LIANABLOCK_H
#define LIANABLOCK_H
#include "Platform.h"


class LianaBlock : public Platform
{
    public:
        LianaBlock(float xPosition, float yPosition);
        virtual ~LianaBlock();
        LianaBlock(const LianaBlock& other);
        LianaBlock& operator=(const LianaBlock& other);

        string getType()const;
};

#endif // LIANABLOCK_H
