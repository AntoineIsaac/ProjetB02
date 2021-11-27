#ifndef GRASSBLOCK_H
#define GRASSBLOCK_H
#include "Platform.h"


class GrassBlock : public Platform
{
    private:

    public:
        GrassBlock(float xPosition, float yPosition);
        virtual ~GrassBlock();
        GrassBlock(const GrassBlock& other);
        GrassBlock& operator=(const GrassBlock& other);

        int getType()const;


};

#endif // GRASSBLOCK_H
