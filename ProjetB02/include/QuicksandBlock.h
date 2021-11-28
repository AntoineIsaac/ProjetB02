#ifndef QUICKSANDBLOCK_H
#define QUICKSANDBLOCK_H
#include "Platform.h"


class QuicksandBlock : public Platform
{
    public:
        QuicksandBlock(float xPosition, float yPosition);
        virtual ~QuicksandBlock();
        QuicksandBlock(const QuicksandBlock& other);
        QuicksandBlock& operator=(const QuicksandBlock& other);

        string getType()const;
};

#endif // QUICKSANDBLOCK_H
