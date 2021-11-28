#ifndef REDQUICKSANDBLOCK_H
#define REDQUICKSANDBLOCK_H
#include "Platform.h"


class RedQuicksandBlock : public Platform
{
    public:
        RedQuicksandBlock(float xPosition, float yPosition);
        virtual ~RedQuicksandBlock();
        RedQuicksandBlock(const RedQuicksandBlock& other);
        RedQuicksandBlock& operator=(const RedQuicksandBlock& other);

        string getType()const;
};

#endif // REDQUICKSANDBLOCK_H
