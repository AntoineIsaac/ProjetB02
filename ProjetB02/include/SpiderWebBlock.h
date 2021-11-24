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

        //Getters and setters
        float getXPosition()const;
        void setXPosition(float x);

        float getYPosition()const;
        void setYPosition(float y);

        Sprite getSprite()const;
        void setSprite(string textureString, IntRect coord);

        int getType()const;
};

#endif // SPIDERWEBBLOCK_H
