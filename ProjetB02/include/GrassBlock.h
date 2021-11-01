#ifndef GRASSBLOCK_H
#define GRASSBLOCK_H
#include "Platform.h"


class GrassBlock : public Platform
{
    private:

    public:
        GrassBlock(float xPosition, float yPosition);
        virtual ~GrassBlock();
        GrassBlock(const GrassBlock& other);
        GrassBlock& operator=(const GrassBlock& other);

        //Getters and setters
        float getXPosition()const;
        void setXPosition(float x);

        float getYPosition()const;
        void setYPosition(float y);

        Sprite getSprite()const;
        void setSprite(string textureString, IntRect coord);


};

#endif // GRASSBLOCK_H
