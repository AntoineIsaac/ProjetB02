#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include <string>
#include <iostream>
#include <cmath>
#include "Platform.h"
#include "Checkpoint.h"


class Player : public Entity
{
    private :
        float scale = 0.2;
        float hitBoxWidth[2] = {50*scale, 490*scale};
        float hitBoxHeight[2] = {115*scale, 725*scale};
        float width = hitBoxWidth[1] - hitBoxWidth[0];
        float height = hitBoxHeight[1] - hitBoxHeight[0];
        bool onGround;
        int animation = 1;

    public:
        Player(float xPosition, float yPosition, string textureString);
        virtual ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);

        //Getters and setters
        Sprite getSprite()const;

        float getXPosition()const;
        float getYPosition()const;
        void setXPosition(float x);
        void setYPosition(float y);

        //Redefinition of sprite method
        void setPosition(float x, float y);
        void move(float x, float y);
        void setScale(float x);
        FloatRect getGlobalBounds();
        FloatRect getGlobalBoundsHitBox();

        float getXSpeed()const;
        float getYSpeed()const;
        void setXSpeed(float xSpeed);
        void setYSpeed(float ySpeed);

        //Functions
        void update(bool left, bool right, bool space, float fps, vector<Platform*> level);
        void collision(int &newXPosition, int &newYposition, vector<Platform*> level);

        void loadTexture();
        void loadTextureIdle();
        void loadTextureJump();
};

#endif // PLAYER_H
