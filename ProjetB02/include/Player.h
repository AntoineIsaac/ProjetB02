#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"


class Player : public Entity
{
    public:
        Player(int speed = 0, int xPosition = 0, int yPosition = 0, string stringTexture = "");
        virtual ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);

    protected:

    private:
};

#endif // PLAYER_H
