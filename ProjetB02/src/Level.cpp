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
    int level[6][8] = {{0, 1, 1, 1, 1, 0, 0, 1},
                        {0, 1, 2, 0, 0, 0, 0, 1},
                        {0, 1, 0, 0, 0, 0, 0, 1},
                        {0, 1, 0, 0, 0, 0, 0, 1},
                        {0, 1, 0, 3, 0, 0, 0, 1},
                        {0, 1, 1, 1, 1, 1, 1, 1}};
    vector<Platform*> platform;

    Platform* p;


    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j<8; j++)
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
