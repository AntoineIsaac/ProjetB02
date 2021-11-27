#ifndef LEAFBLOCK_H
#define LEAFBLOCK_H
#include "Platform.h"

class LeafBlock : public Platform
{
    public:
        LeafBlock(float xPosition, float yPosition);
        virtual ~LeafBlock();
        LeafBlock(const LeafBlock& other);
        LeafBlock& operator=(const LeafBlock& other);

        string getType()const;
};

#endif // LEAFBLOCK_H
