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
    int level[4][8] = {{1, 1, 1, 1, 1, 0, 2, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {1, 1, 1, 1, 1, 0, 2, 0},
                        {0, 2, 2, 1, 1, 0, 2, 0}};
    vector<Platform*> platform;


    for(int j = 0; j < 8; j++)
    {
        for(int i = 0; i<8; i++)
        {
            if(level[j][i] == 1)
            {
                platform.push_back(new GrassBlock(75*i, 75*j));
            }
            else if(level[j][i] == 2)
            {
                platform.push_back(new LavaBlock(75*i, 75*j));
            }
        }
    }

    return platform;
}
