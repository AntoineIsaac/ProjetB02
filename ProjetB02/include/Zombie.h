#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "Entity.h"
#include <string>
#include <iostream>

using namespace std;

class Zombie : public Entity
{
    private:
        float scale = 0.2;

        float hitBoxWidth[2] = {95*scale, 470*scale};
        float hitBoxHeight[2] = {15*scale, 500*scale};
        float width = hitBoxWidth[1] - hitBoxWidth[0];
        float height = hitBoxHeight[1] - hitBoxHeight[0];

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

        int getWidth()const;

        //Redefinition of sprite method
        void setPosition(float x, float y);
        void setScale(float x);



        float getXSpeed()const;
        float getYSpeed()const;
        void setXSpeed(float xSpeed);
        void setYSpeed(float ySpeed);

        FloatRect getGlobalBoundsHitBox();

        void loadTexture();


};

#endif // ZOMBIE_H
