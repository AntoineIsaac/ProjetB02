#ifndef PORTALBLOCK_H
#define PORTALBLOCK_H
#include "Platform.h"


class PortalBlock : public Platform
{
    public:
        PortalBlock(float xPosition, float yPosition);
        virtual ~PortalBlock();
        PortalBlock(const PortalBlock& other);
        PortalBlock& operator=(const PortalBlock& other);


        //Getters and setters
        float getXPosition()const;
        void setXPosition(float x);

        float getYPosition()const;
        void setYPosition(float y);

        Sprite getSprite()const;
        void setSprite(string textureString, IntRect coord);

        int getType()const;
};

#endif // PORTALBLOCK_H
