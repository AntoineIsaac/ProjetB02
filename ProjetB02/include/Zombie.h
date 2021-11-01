#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "Entity.h"

class Zombie : public Entity
{
    private:

    public:
        Zombie(float xPosition, float yPosition, string textureString);
        virtual ~Zombie();
        Zombie(const Zombie& other);
        Zombie& operator=(const Zombie& other);

        //Getters and setters
        Sprite getSprite()const;

        float getXPosition()const;
        float getYPosition()const;
        void setXPosition(float x);
        void setYPosition(float y);

        //Redefinition of sprite method
        void setPosition(float x, float y);

        float getXSpeed()const;
        float getYSpeed()const;
        void setXSpeed(float xSpeed);
        void setYSpeed(float ySpeed);


};

#endif // ZOMBIE_H
