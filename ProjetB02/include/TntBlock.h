#ifndef TNTBLOCK_H
#define TNTBLOCK_H

#include "Platform.h"

class TntBlock : public Platform
{
    public:
        TntBlock(float xPosition, float yPosition);
        virtual ~TntBlock();
        TntBlock(const TntBlock& other);
        TntBlock& operator=(const TntBlock& other);


        string getType()const;

    protected:

    private:
};

#endif // TNTBLOCK_H
