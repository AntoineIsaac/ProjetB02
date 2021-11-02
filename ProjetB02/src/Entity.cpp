#include "../include/Entity.h"

Entity::Entity(float xPosition, float yPosition, string textureString):xPosition(xPosition), yPosition(yPosition), textureString(textureString)
{
    texture.loadFromFile(textureString);
    sprite.setTexture(texture);
}

Entity::~Entity()
{

}

Entity::Entity(const Entity& other):xPosition(other.xPosition), yPosition(other.yPosition), textureString(other.textureString)
{
    //copy ctor
}

Entity& Entity::operator=(const Entity& rhs)
{
    if (this != &rhs)
    {
        xSpeed = rhs.xSpeed;
        ySpeed = rhs.ySpeed;
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
    setXPosition(x);
    setYPosition(y);
}

void Entity::move(float x, float y)
{
    sprite.move(x, y);
}

void Entity::setScale(float x)
{
    sprite.scale(x, x);
}

FloatRect Entity::getLocalBounds()
{
    return sprite.getLocalBounds();
}

float Entity::getXSpeed()const
{
    return xSpeed;
}

float Entity::getYSpeed()const
{
    return ySpeed;
}

void Entity::setXSpeed(float xSpeed)
{
    this->xSpeed = xSpeed;
}

void Entity::setYSpeed(float ySpeed)
{
    this->ySpeed = ySpeed;
}

