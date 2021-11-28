#ifndef SUGARCANEBLOCK_H
#define SUGARCANEBLOCK_H
#include "Platform.h"


class SugarCaneBlock : public Platform
{
    public:
        SugarCaneBlock(float xPosition, float yPosition);
        virtual ~SugarCaneBlock();
        SugarCaneBlock(const SugarCaneBlock& other);
        SugarCaneBlock& operator=(const SugarCaneBlock& other);

        string getType()const;
};

#endif // SUGARCANEBLOCK_H
