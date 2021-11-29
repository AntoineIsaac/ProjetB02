#ifndef WOODPLANK_H
#define WOODPLANK_H

#include "Platform.h"
class WoodPlank : public Platform
{
    public:
        WoodPlank(float xPosition, float yPosition);
        virtual ~WoodPlank();
        WoodPlank(const WoodPlank& other);
        WoodPlank& operator=(const WoodPlank& other);

        string getType()const;

    protected:

    private:
};

#endif // WOODPLANK_H
