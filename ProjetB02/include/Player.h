#ifndef PLAYER_H
#define PLAYER_H
#include "Game.h"
#include "Entity.h"
#include <string>
#include <iostream>
#include <cmath>
#include "Player.h"
#include "Platform.h"
#include "Checkpoint.h"
#include "Zombie.h"
#include <thread>
#include "State.h"
#include "StateNormal.h"
#include "StateSlow.h"
#include "StateSpeed.h"
class Game;

class Player : public Entity
{
    private :
        //Etat pour DP State
        //Nous avons une agrégation interne car un Player possède un état (state). De plus, un état ne peut
        //exister en dehors d'un Player donc celui-ci est créé à l'interieur du constructeur de Player.
        //Nous avons un State pour introduire notre DP State qui gère l'état de la vitesse de
        //notre Player (Normal, accéléré, ralenti).
        State* state;
        float scale = 0.1;
        //Une hitbox qui permet de délimiter les dimensions du personnage
        float hitBoxWidth[2] = {50*scale, 365*scale};
        float hitBoxHeight[2] = {115*scale, 725*scale};
        float width = hitBoxWidth[1] - hitBoxWidth[0];
        float height = hitBoxHeight[1] - hitBoxHeight[0];

        int animation = 1;

        //Valeur de la position à laquelle le personnage doit apparaitre lorsqu'il meurt
        Vector2f respawnPosition;

        //Nombre de points de vie
        int HP;
        float jumpHeight = 175.;
        int jumpBlock;
        bool alreadyTouched = false;
        bool colTop = false;
        bool canJump = false;
        //Permet de savoir si le personnage est dans une toile d'araignée ou dans l'eau
        bool web = false;

        SoundBuffer zombieBuffer;
        SoundBuffer painBuffer;
        SoundBuffer teleportBuffer;
        Sound zombieSound;
        Sound painSound;
        Sound teleportSound;

    public:
        bool onGround;

        Player(float xPosition, float yPosition, string textureString);
        virtual ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);

        //Permet de récupérer les dimensions du personnage
        FloatRect getGlobalBoundsHitBox();
        //Récupère les inputs entrés par le joueur et bouge le personnage en fonction
        void updatePlayer(bool left, bool right, bool space, float fps, vector<Platform*> level, vector<Zombie*> enemies, Game* game);
        //Permet de savoir si le personnage entre en collision avec un block
        bool collision(int &newXPosition, int &newYposition, vector<Platform*> level, Game* game);
        //Permet de savoir si le personnage entre en collision avec un Zombie
        void collisionEnemies(int &newXPosition, int &newYposition, vector<Zombie*> enemies, Game* game);

        void loadTexture();
        void loadTextureIdle();
        void loadTextureJump();

        //Getters and Setters
        Vector2f getRespawnPosition()const;
        void setRespawnPosition(float x, float y);

        void setHP(int hp);
        int getHP()const;

        void setState(State* state);
        State* getState()const;
};

#endif // PLAYER_H
