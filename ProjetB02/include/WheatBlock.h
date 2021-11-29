#ifndef WHEATBLOCK_H
#define WHEATBLOCK_H

#include "Platform.h"
class WheatBlock : public Platform
{
    public:
        WheatBlock(float xPosition, float yPosition);
        virtual ~WheatBlock();
        WheatBlock(const WheatBlock& other);
        WheatBlock& operator=(const WheatBlock& other);

        string getType()const;


    protected:

    private:
};

#endif // WHEATBLOCK_H
