#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"


class Player : public Entity
{
    private :

    public:
        Player(int speed = 0, int xPosition = 0, int yPosition = 0, Sprite sprite = Sprite());
        virtual ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);

        //Getters
        Sprite getSprite()const;
};

#endif // PLAYER_H
