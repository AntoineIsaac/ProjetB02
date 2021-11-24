#ifndef NETHERBLOCK_H
#define NETHERBLOCK_H
#include "Platform.h"


class NetherBlock : public Platform
{
    public:
        NetherBlock(float xPosition, float yPosition);
        virtual ~NetherBlock();
        NetherBlock(const NetherBlock& other);
        NetherBlock& operator=(const NetherBlock& other);

        //Getters and setters
        float getXPosition()const;
        void setXPosition(float x);

        float getYPosition()const;
        void setYPosition(float y);

        Sprite getSprite()const;
        void setSprite(string textureString, IntRect coord);

        int getType()const;
};

#endif // NETHERBLOCK_H
