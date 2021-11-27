#ifndef FIREBLOCK_H
#define FIREBLOCK_H
#include "Platform.h"

class FireBlock : public Platform
{
    public:
        FireBlock(float xPosition, float yPosition);
        virtual ~FireBlock();
        FireBlock(const FireBlock& other);
        FireBlock& operator=(const FireBlock& other);

        int getType()const;
};

#endif // FIREBLOCK_H
