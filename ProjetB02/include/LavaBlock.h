#ifndef LAVABLOCK_H
#define LAVABLOCK_H
#include "Platform.h"


class LavaBlock : public Platform
{
    private:

    public:
        LavaBlock(float xPosition, float yPosition);
        virtual ~LavaBlock();
        LavaBlock(const LavaBlock& other);
        LavaBlock& operator=(const LavaBlock& other);

        //Getters and setters
        float getXPosition()const;
        void setXPosition(float x);

        float getYPosition()const;
        void setYPosition(float y);

        Sprite getSprite()const;
        void setSprite(string textureString, IntRect coord);

        int getType()const;

};

#endif // LAVABLOCK_H
