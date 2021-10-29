#ifndef ENTITY_H
#define ENTITY_H


class Entity
{
    private:
        int speed;
        int xPosition;
        int yPosition;

    public:
        Entity(int speed = 0, int xPosition = 0, int yPosition = 0);
        virtual ~Entity();
        Entity(const Entity& other);
        Entity& operator=(const Entity& other);


};

#endif // ENTITY_H
