#ifndef PLAYER_H
#define PLAYER_H
#include "Game.h"
#include "Entity.h"
#include <string>
#include <iostream>
#include <cmath>

#include "Platform.h"
#include "Checkpoint.h"
#include "Zombie.h"
#include <thread>
class Game;


class Player : public Entity
{
    private :
        float scale = 0.1;
        //490 si on veut au bout de la tête
        float hitBoxWidth[2] = {50*scale, 365*scale};
        float hitBoxHeight[2] = {115*scale, 725*scale};
        float width = hitBoxWidth[1] - hitBoxWidth[0];
        float height = hitBoxHeight[1] - hitBoxHeight[0];

        int animation = 1;

        Vector2f respawnPosition;

        float jumpHeight = 175.;
        int jumpBlock;
        bool alreadyTouched = false;
        bool colTop = false;
        bool canJump = false;


    public:
        bool onGround;

        Player(float xPosition, float yPosition, string textureString);
        virtual ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);




        //Functions
        FloatRect getGlobalBoundsHitBox();
        void update(bool left, bool right, bool space, float fps, vector<Platform*> level, vector<Zombie*> enemies, Game* game);
        bool collision(int &newXPosition, int &newYposition, vector<Platform*> level, Game* game);
        void collisionEnemies(int &newXPosition, int &newYposition, vector<Zombie*> enemies);

        void loadTexture();
        void loadTextureIdle();
        void loadTextureJump();

        Vector2f getRespawnPosition()const;
        void setRespawnPosition(float x, float y);
};

#endif // PLAYER_H
