#ifndef LEAFBLOCK_H
#define LEAFBLOCK_H
#include "Platform.h"

class LeafBlock : public Platform
{
    public:
        LeafBlock(float xPosition, float yPosition);
        virtual ~LeafBlock();
        LeafBlock(const LeafBlock& other);
        LeafBlock& operator=(const LeafBlock& other);

        //Getters and setters
        float getXPosition()const;
        void setXPosition(float x);

        float getYPosition()const;
        void setYPosition(float y);

        Sprite getSprite()const;
        void setSprite(string textureString, IntRect coord);

        int getType()const;
};

#endif // LEAFBLOCK_H
