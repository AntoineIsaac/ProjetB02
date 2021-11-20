#ifndef CHECKPOINT_H
#define CHECKPOINT_H
#include "Platform.h"

class Checkpoint : public Platform
{
    private:
        bool activated = false;

    public:
        Checkpoint(float xPosition, float yPosition);
        virtual ~Checkpoint();
        Checkpoint(const Checkpoint& other);
        Checkpoint& operator=(const Checkpoint& other);

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

#endif // CHECKPOINT_H
