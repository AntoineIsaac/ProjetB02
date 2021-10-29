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
        Texture texture;
        string stringTexture;

    public:
        Entity(int speed = 0, int xPosition = 0, int yPosition = 0, string stringTexture = "");
        virtual ~Entity();
        Entity(const Entity& other);
        Entity& operator=(const Entity& other);


};

#endif // ENTITY_H
