#ifndef OAKWOODBLOCK_H
#define OAKWOODBLOCK_H

#include "Platform.h"

class oakWoodBlock : public Platform
{
    public:
        oakWoodBlock(float xPosition, float yPosition);
        virtual ~oakWoodBlock();
        oakWoodBlock(const oakWoodBlock& other);
        oakWoodBlock& operator=(const oakWoodBlock& other);

        string getType()const;


    protected:

    private:
};

#endif // OAKWOODBLOCK_H
