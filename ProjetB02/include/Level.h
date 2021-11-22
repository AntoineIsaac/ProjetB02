#ifndef LEVEL_H
#define LEVEL_H
#include "Platform.h"
#include "GrassBlock.h"
#include "LavaBlock.h"
#include "Checkpoint.h"
#include <string>
#include "Zombie.h"

using namespace std;


class Level
{
    private:


    public:
        Level();
        virtual ~Level();
        Level(const Level& other);
        Level& operator=(const Level& other);


        vector<Platform*> createLevel1()const;

        vector<Zombie*> createZombiesLevel1()const;
};

#endif // LEVEL_H
