#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;


class Entity
{
    private:
        int speed;
        int xPosition;
        int yPosition;
        Sprite sprite;

    public:
        Entity(int speed = 0, int xPosition = 0, int yPosition = 0, Sprite sprite = Sprite());
        virtual ~Entity();
        Entity(const Entity& other);
        Entity& operator=(const Entity& other);

        virtual Sprite getSprite()const=0;


};

#endif // ENTITY_H
