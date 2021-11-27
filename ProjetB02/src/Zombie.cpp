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

int Zombie::getWidth() const
{
    return width;
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
