#ifndef NETHERWOODBLOCK_H
#define NETHERWOODBLOCK_H
#include "Platform.h"

class NetherWoodBlock : public Platform
{
    public:
        NetherWoodBlock(float xPosition, float yPosition);
        virtual ~NetherWoodBlock();
        NetherWoodBlock(const NetherWoodBlock& other);
        NetherWoodBlock& operator=(const NetherWoodBlock& other);

        //Getters and setters
        float getXPosition()const;
        void setXPosition(float x);

        float getYPosition()const;
        void setYPosition(float y);

        Sprite getSprite()const;
        void setSprite(string textureString, IntRect coord);

        int getType()const;
};

#endif // NETHERWOODBLOCK_H
