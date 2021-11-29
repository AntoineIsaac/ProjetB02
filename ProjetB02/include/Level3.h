#ifndef LEVEL3_H
#define LEVEL3_H
#include "Level.h"

class Level3 : public Level
{


    public:
        Level3();
        virtual ~Level3();
        Level3(const Level3& other);
        Level3& operator=(const Level3& other);

        //Redefinitions
        vector<Platform*> createLevel()const;
        vector<Platform*> createDecorLevel()const;
        vector<Zombie*> createZombiesLevel()const;



};

#endif // LEVEL3_H
