#ifndef DRUIDE1984_H
#define DRUIDE1984_H
#include "Personnage1984.h"


class Druide1984 : public Personnage1984
{
    private:
        int magie1984;

    public:
        Druide1984(string nom1984, int vie1984, Position1984 position1984, int magie1984);
        virtual ~Druide1984();
        Druide1984(const Druide1984& other);
        Druide1984& operator=(const Druide1984& other);

        Druide1984* clone()const;
        string str()const;
        string getInfo()const;

        void prendreDegat(int vie1984);
        int attaquer()const;


};

#endif // DRUIDE1984_H
