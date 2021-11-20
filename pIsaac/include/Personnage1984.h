#ifndef PERSONNAGE1984_H
#define PERSONNAGE1984_H
#include <string>
#include "Position1984.h"
#include <sstream>

using namespace std;


class Personnage1984
{
    private:

    protected:
        string nom1984;
        int vie1984;
        Position1984 position1984;


    public:
        Personnage1984(string nom1984, int vie1984, Position1984 position1984);
        virtual ~Personnage1984();
        Personnage1984(const Personnage1984& other);
        Personnage1984& operator=(const Personnage1984& other);

        virtual bool operator==(const Personnage1984& perso1984)const;
        virtual Personnage1984* clone()const;
        virtual string str()const;

        virtual string getInfo()const;
        virtual Position1984 getPosition();
        virtual void setPosition(int x1984, int y1984);

        virtual int getVie();
        virtual void prendreDegat(int vie1984);
        virtual int attaquer()const;



};

#endif // PERSONNAGE1984_H
