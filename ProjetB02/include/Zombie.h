#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "Entity.h"
#include <string>
#include <iostream>


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
        void move(float x, float y);

        float getSpeed()const;
        void setSpeed(float speed);

};

#endif // ZOMBIE_H
