#ifndef LAVABLOCK_H
#define LAVABLOCK_H
#include "Platform.h"


class LavaBlock : public Platform
{
    private:

    public:
        LavaBlock(float xPosition, float yPosition);
        virtual ~LavaBlock();
        LavaBlock(const LavaBlock& other);
        LavaBlock& operator=(const LavaBlock& other);

        string getType()const;

};

#endif // LAVABLOCK_H
