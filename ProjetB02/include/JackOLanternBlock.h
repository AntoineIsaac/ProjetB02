#ifndef JACKOLANTERNBLOCK_H
#define JACKOLANTERNBLOCK_H
#include "Platform.h"


class JackOLanternBlock : public Platform
{
    private:
        bool activated = false;

    public:
        JackOLanternBlock(float xPosition, float yPosition);
        virtual ~JackOLanternBlock();
        JackOLanternBlock(const JackOLanternBlock& other);
        JackOLanternBlock& operator=(const JackOLanternBlock& other);

        //Getters and setters
        float getXPosition()const;
        void setXPosition(float x);

        float getYPosition()const;
        void setYPosition(float y);

        Sprite getSprite()const;
        void setSprite(string textureString, IntRect coord);

        void switchCheckpoint();
        bool isActivated()const;

        int getType()const;
};

#endif // JACKOLANTERNBLOCK_H
