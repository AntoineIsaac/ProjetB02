#include "../include/SugarCaneBlock.h"

SugarCaneBlock::SugarCaneBlock(float xPosition, float yPosition):Platform(xPosition, yPosition)
{
    setSprite("Images/blocks.png", IntRect(16 * 9, 16 * 4, 16, 16));
}

SugarCaneBlock::~SugarCaneBlock()
{
    //dtor
}

SugarCaneBlock::SugarCaneBlock(const SugarCaneBlock& other):Platform(other)
{
    //copy ctor
}

SugarCaneBlock& SugarCaneBlock::operator=(const SugarCaneBlock& rhs)
{
    if(this != &rhs)
    {
        Platform::operator=(rhs);
    }
    return *this;
}

string SugarCaneBlock::getType() const
{
    return "SugarCaneBlock";
}
