#include "../include/FireBlock.h"

FireBlock::FireBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 19, 16 * 3, 16, 16));
}

FireBlock::~FireBlock()
{
    //dtor
}

FireBlock::FireBlock(const FireBlock& other):Platform(other)
{
    //copy ctor
}

FireBlock& FireBlock::operator=(const FireBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

string FireBlock::getType() const
{
    return "FireBlock";
}
