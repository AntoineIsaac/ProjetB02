#include "../include/Entity.h"

Entity::Entity(float xPosition, float yPosition, string textureString):xPosition(xPosition), yPosition(yPosition), textureString(textureString)
{
    texture.loadFromFile(textureString);
    sprite.setTexture(texture);
    sprite.scale(0.5, 0.5);
}

Entity::~Entity()
{

}

Entity::Entity(const Entity& other):speed(other.speed), xPosition(other.xPosition), yPosition(other.yPosition), textureString(other.textureString)
{
    //copy ctor
}

Entity& Entity::operator=(const Entity& rhs)
{
    if (this != &rhs)
    {
        speed = rhs.speed;
        xPosition = rhs.xPosition;
        yPosition = rhs.yPosition;
        texture = rhs.texture;
    }

    return *this;
}

Sprite Entity::getSprite()const
{
    return sprite;
}

float Entity::getXPosition()const
{
    return xPosition;
}

float Entity::getYPosition()const
{
    return yPosition;
}

void Entity::setXPosition(float x)
{
    this->xPosition = x;
}

void Entity::setYPosition(float y)
{
    this->yPosition = y;
}

void Entity::setPosition(float x, float y)
{
    sprite.setPosition(x, y);
}

void Entity::move(float x, float y)
{
    sprite.move(x, y);
}

float Entity::getSpeed()const
{
    return speed;
}

void Entity::setSpeed(float speed)
{
    this->speed = speed;
}

