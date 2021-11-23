#include "../include/Zombie.h"

Zombie::Zombie(float xPosition, float yPosition, string textureString):Entity(xPosition, yPosition, textureString)
{
    setXSpeed(3.0);
    setScale(scale);
}

Zombie::~Zombie()
{
    //dtor
}

Zombie::Zombie(const Zombie& other):Entity(other)
{
    //copy ctor
}

Zombie& Zombie::operator=(const Zombie& rhs)
{
    if(this != &rhs)
    {
        Entity::operator=(rhs);
    }
    return *this;
}

Sprite Zombie::getSprite()const
{
    return Entity::getSprite();
}

float Zombie::getXPosition()const
{
    return Entity::getXPosition();
}

float Zombie::getYPosition()const
{
    return Entity::getYPosition();
}

void Zombie::setXPosition(float x)
{
    Entity::setXPosition(x);
}

void Zombie::setYPosition(float y)
{
    Entity::setYPosition(y);
}

int Zombie::getWidth() const
{
    return width;
}

void Zombie::setPosition(float x, float y)
{
    Entity::setPosition(x, y);
}

void Zombie::setScale(float x)
{
    Entity::setScale(x);
}

float Zombie::getXSpeed()const
{
    return Entity::getXSpeed();
}

float Zombie::getYSpeed()const
{
    return Entity::getYSpeed();
}

void Zombie::setXSpeed(float xSpeed)
{
    Entity::setXSpeed(xSpeed);
}



void Zombie::setYSpeed(float ySpeed)
{
    Entity::setYSpeed(ySpeed);
}


FloatRect Zombie::getGlobalBoundsHitBox()
{
    FloatRect rect = Entity::getGlobalBounds();
    rect.left += hitBoxWidth[0];
    rect.top += hitBoxHeight[0];
    rect.height = height;
    rect.width = width;
    return rect;
}


void Zombie::loadTexture()
{
    if(!texture.loadFromFile("./Images/zombie2.gif"))
    {
        cout << "Erreur dans le chargement de la texture"<<endl;
    }
}
