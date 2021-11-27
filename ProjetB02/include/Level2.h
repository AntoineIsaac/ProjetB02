#ifndef LEVEL2_H
#define LEVEL2_H
#include "Level.h"

class Level2 : public Level
{
    public:
        Level2();
        virtual ~Level2();
        Level2(const Level2& other);
        Level2& operator=(const Level2& other);

        //Redefinitions
        vector<Platform*> createLevel()const;
        vector<Platform*> createDecorLevel()const;
        vector<Zombie*> createZombiesLevel()const;
};

#endif // LEVEL2_H
