#ifndef ACASIAWOODBLOCK_H
#define ACASIAWOODBLOCK_H
#include "Platform.h"


class AcasiaWoodBlock : public Platform
{
    public:
        AcasiaWoodBlock(float xPosition, float yPosition);
        virtual ~AcasiaWoodBlock();
        AcasiaWoodBlock(const AcasiaWoodBlock& other);
        AcasiaWoodBlock& operator=(const AcasiaWoodBlock& other);

        string getType()const;
};

#endif // ACASIAWOODBLOCK_H
