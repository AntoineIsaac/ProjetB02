#ifndef CLOUDBLOCK_H
#define CLOUDBLOCK_H
#include "Platform.h"


class CloudBlock : public Platform
{
    public:
        CloudBlock(float xPosition, float yPosition);
        virtual ~CloudBlock();
        CloudBlock(const CloudBlock& other);
        CloudBlock& operator=(const CloudBlock& other);

        string getType()const;
};

#endif // CLOUDBLOCK_H
