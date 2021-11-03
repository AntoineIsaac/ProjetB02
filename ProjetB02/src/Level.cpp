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
    int level[6][8] = {{0, 1, 1, 1, 1, 1, 1, 1},
                        {0, 1, 0, 0, 0, 0, 0, 1},
                        {0, 1, 0, 0, 0, 0, 0, 1},
                        {0, 1, 0, 0, 0, 0, 0, 1},
                        {0, 1, 0, 0, 0, 0, 0, 1},
                        {0, 1, 1, 1, 1, 1, 1, 1}};
    vector<Platform*> platform;


    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j<8; j++)
        {
            if(level[i][j] == 1)
            {
                platform.push_back(new GrassBlock(75*j, 75*i));
            }
            else if(level[i][j] == 2)
            {
                platform.push_back(new LavaBlock(75*j, 75*i));
            }
        }
    }

    return platform;
}
