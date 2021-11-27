#ifndef LEVEL1_H
#define LEVEL1_H
#include "Level.h"


class Level1 : public Level
{
    public:
        Level1();
        virtual ~Level1();
        Level1(const Level1& other);
        Level1& operator=(const Level1& other);

        //Redefinitions
        vector<Platform*> createLevel()const;
        vector<Platform*> createDecorLevel()const;
        vector<Zombie*> createZombiesLevel()const;
};

#endif // LEVEL1_H
