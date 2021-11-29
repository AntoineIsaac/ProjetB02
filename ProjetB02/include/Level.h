#ifndef LEVEL_H
#define LEVEL_H
#include "Platform.h"
#include "GrassBlock.h"
#include "LavaBlock.h"
#include "Checkpoint.h"
#include <string>
#include "Zombie.h"
#include "NetherBlock.h"
#include "PortalBlock.h"
#include "ObsidianBlock.h"
#include "SpiderWebBlock.h"
#include "NetherWoodBlock.h"
#include "LeafBlock.h"
#include "FireBlock.h"
#include "SandBlock.h"
#include "NetherFence.h"
#include "CactusBlock.h"
#include "QuicksandBlock.h"
#include "RedQuicksandBlock.h"
#include "RedSandBlock.h"
#include "RedSmoothSandBlock.h"
#include "SandBlock.h"
#include "SmoothSandBlock.h"
#include "SugarCaneBlock.h"
#include "NetherLianaBlock.h"
#include "NetherWartBlock.h"
<<<<<<< HEAD
#include "CloudBlock.h"
#include "AcasiaLeafBlock.h"
#include "AcasiaWoodBlock.h"
#include "LianaBlock.h"
=======
#include "Dirt.h"
#include "WheatBlock.h"
#include "WoodPlank.h"
>>>>>>> d2a823a35ffe5a52ec1f767fe4091b1797eafd6a

using namespace std;


class Level
{
    private:


    public:
        Level();
        virtual ~Level();
        Level(const Level& other);
        Level& operator=(const Level& other);

        virtual vector<Platform*> createLevel()const = 0;
        virtual vector<Platform*> createDecorLevel()const = 0;
        virtual vector<Zombie*> createZombiesLevel()const = 0;
};

#endif // LEVEL_H
