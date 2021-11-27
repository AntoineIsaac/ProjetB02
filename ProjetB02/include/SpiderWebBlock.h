#ifndef SPIDERWEBBLOCK_H
#define SPIDERWEBBLOCK_H
#include "Platform.h"


class SpiderWebBlock : public Platform
{
    public:
        SpiderWebBlock(float xPosition, float yPosition);
        virtual ~SpiderWebBlock();
        SpiderWebBlock(const SpiderWebBlock& other);
        SpiderWebBlock& operator=(const SpiderWebBlock& other);

        string getType()const;
};

#endif // SPIDERWEBBLOCK_H
