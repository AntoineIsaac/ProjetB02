#include "../include/Level.h"

Level::Level()
{
    //ctor
}

Level::~Level()
{
    //dtor
}

Level::Level(const Level& other)
{
    //copy ctor
}

Level& Level::operator=(const Level& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}


vector<Platform*> Level::createLevel1()const
{
    int level[8][18] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
                        {0, 3, 0, 0, 0, 0, 0, 0, 3 ,0, 0 ,0, 0, 1, 1, 0, 0, 0},
                        {1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 0, 2, 1, 0, 0, 0, 0, 0}};
    vector<Platform*> platform;

    Platform* p;


    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j<18; j++)
        {
            if(level[i][j] == 1)
            {
                platform.push_back(new GrassBlock(p->size*j, p->size*i));
            }
            else if(level[i][j] == 2)
            {
                platform.push_back(new LavaBlock(p->size*j, p->size*i));
            }
            else if(level[i][j] == 3)
            {
                platform.push_back(new Checkpoint(p->size*j, p->size*i));
            }
        }
    }

    return platform;
}


//vector<Zombie*> Level::createZombiesLevel1()const
//{
//    int level[8][18] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
//                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 1, 1, 0},
//                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
//                        {0, 3, 0, 0, 0, 0, 0, 0, 3 ,0, 0 ,0, 0, 1, 1, 0, 0, 0},
//                        {1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 0, 2, 1, 0, 0, 0, 0, 0}};
//    vector<Zombie*> zombies;
//
//    Platform* p;
//
//
//    for(int i = 0; i < 8; i++)
//    {
//        for(int j = 0; j<18; j++)
//        {
//            if(level[i][j] == 9)
//            {
//                zombies.push_back(new Zombie(p->size*j, p->size*i, "Images/zombie2.gif"));
//            }
//        }
//    }
//
//    return zombies;
//}
