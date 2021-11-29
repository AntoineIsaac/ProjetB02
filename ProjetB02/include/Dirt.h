#ifndef DIRT_H
#define DIRT_H

#include "Platform.h"


class Dirt : public Platform
{
    public:
        Dirt(float xPosition, float yPosition);
        virtual ~Dirt();
        Dirt(const Dirt& other);
        Dirt& operator=(const Dirt& other);

        string getType()const;

    protected:

    private:
};

#endif // DIRT_H
