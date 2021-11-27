#ifndef PORTALBLOCK_H
#define PORTALBLOCK_H
#include "Platform.h"


class PortalBlock : public Platform
{
    public:
        PortalBlock(float xPosition, float yPosition);
        virtual ~PortalBlock();
        PortalBlock(const PortalBlock& other);
        PortalBlock& operator=(const PortalBlock& other);

        string getType()const;
};

#endif // PORTALBLOCK_H
