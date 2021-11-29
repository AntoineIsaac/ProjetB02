#ifndef ACASIALEAFBLOCK_H
#define ACASIALEAFBLOCK_H
#include "Platform.h"


class AcasiaLeafBlock : public Platform
{
    public:
        AcasiaLeafBlock(float xPosition, float yPosition);
        virtual ~AcasiaLeafBlock();
        AcasiaLeafBlock(const AcasiaLeafBlock& other);
        AcasiaLeafBlock& operator=(const AcasiaLeafBlock& other);

        string getType()const;
};

#endif // ACASIALEAFBLOCK_H
