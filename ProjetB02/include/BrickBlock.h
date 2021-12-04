#ifndef BRICKBLOCK_H
#define BRICKBLOCK_H

#include "Platform.h"

class BrickBlock : public Platform
{
    public:
        BrickBlock(float xPosition, float yPosition);
        virtual ~BrickBlock();
        BrickBlock(const BrickBlock& other);
        BrickBlock& operator=(const BrickBlock& other);

        string getType()const;

    protected:

    private:
};

#endif // BRICKBLOCK_H
