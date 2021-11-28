#include "../include/RedSmoothSandBlock.h"

RedSmoothSandBlock::RedSmoothSandBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 9, 16 * 20, 16, 16));
}

RedSmoothSandBlock::~RedSmoothSandBlock()
{
    //dtor
}

RedSmoothSandBlock::RedSmoothSandBlock(const RedSmoothSandBlock& other):Platform(other)
{
    //copy ctor
}

RedSmoothSandBlock& RedSmoothSandBlock::operator=(const RedSmoothSandBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

string RedSmoothSandBlock::getType() const
{
    return "RedSmoothSandBlock";
}
