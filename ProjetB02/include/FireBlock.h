#ifndef FIREBLOCK_H
#define FIREBLOCK_H
#include "Platform.h"

class FireBlock : public Platform
{
    public:
        FireBlock(float xPosition, float yPosition);
        virtual ~FireBlock();
        FireBlock(const FireBlock& other);
        FireBlock& operator=(const FireBlock& other);

        //Getters and setters
        float getXPosition()const;
        void setXPosition(float x);

        float getYPosition()const;
        void setYPosition(float y);

        Sprite getSprite()const;
        void setSprite(string textureString, IntRect coord);

        int getType()const;
};

#endif // FIREBLOCK_H
