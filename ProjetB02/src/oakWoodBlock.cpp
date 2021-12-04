#include "../include/oakWoodBlock.h"

oakWoodBlock::oakWoodBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 4, 16 * 1, 16, 16));
}

oakWoodBlock::~oakWoodBlock()
{
    //dtor
}

oakWoodBlock::oakWoodBlock(const oakWoodBlock& other)
{
    //copy ctor
}

oakWoodBlock& oakWoodBlock::operator=(const oakWoodBlock& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

string oakWoodBlock::getType() const
{
    return "oakWoodBlock";
}
