#ifndef WATER_H
#define WATER_H

#include "Platform.h"

class Water : public Platform
{
    public:
        Water(float xPosition, float yPosition);
        virtual ~Water();
        Water(const Water& other);
        Water& operator=(const Water& other);

        string getType()const;

    protected:

    private:
};

#endif // WATER_H
