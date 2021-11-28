#ifndef NETHERWARTBLOCK_H
#define NETHERWARTBLOCK_H
#include "Platform.h"

class NetherWartBlock: public Platform
{
    public:
        NetherWartBlock(float xPosition, float yPosition);
        virtual ~NetherWartBlock();
        NetherWartBlock(const NetherWartBlock& other);
        NetherWartBlock& operator=(const NetherWartBlock& other);

        string getType()const;
};

#endif // NETHERWARTBLOCK_H
