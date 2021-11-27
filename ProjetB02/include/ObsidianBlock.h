#ifndef OBSIDIANBLOCK_H
#define OBSIDIANBLOCK_H
#include "Platform.h"


class ObsidianBlock : public Platform
{
    public:
        ObsidianBlock(float xPosition, float yPosition);
        virtual ~ObsidianBlock();
        ObsidianBlock(const ObsidianBlock& other);
        ObsidianBlock& operator=(const ObsidianBlock& other);

        string getType()const;
};

#endif // OBSIDIANBLOCK_H
