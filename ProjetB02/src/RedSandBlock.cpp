#include "../include/RedSandBlock.h"

RedSandBlock::RedSandBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 7, 16 * 20, 16, 16));
}

RedSandBlock::~RedSandBlock()
{
    //dtor
}

RedSandBlock::RedSandBlock(const RedSandBlock& other):Platform(other)
{
    //copy ctor
}

RedSandBlock& RedSandBlock::operator=(const RedSandBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

string RedSandBlock::getType() const
{
    return "RedSandBlock";
}
