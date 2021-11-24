#ifndef OBSIDIANBLOCK_H
#define OBSIDIANBLOCK_H
#include "Platform.h"


class ObsidianBlock : public Platform
{
    public:
        ObsidianBlock(float xPosition, float yPosition);
        virtual ~ObsidianBlock();
        ObsidianBlock(const ObsidianBlock& other);
        ObsidianBlock& operator=(const ObsidianBlock& other);

        //Getters and setters
        float getXPosition()const;
        void setXPosition(float x);

        float getYPosition()const;
        void setYPosition(float y);

        Sprite getSprite()const;
        void setSprite(string textureString, IntRect coord);

        int getType()const;
};

#endif // OBSIDIANBLOCK_H
