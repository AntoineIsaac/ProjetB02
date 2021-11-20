#ifndef ARENE1984_H
#define ARENE1984_H
#include <vector>
#include <stdlib.h>
#include "Personnage1984.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Arene1984
{
    private:
        vector<Personnage1984 *> personnages1984;

    public:
        Arene1984();
        virtual ~Arene1984();
        Arene1984(const Arene1984& other);
        Arene1984& operator=(const Arene1984& other);

        int rechercherPersonnage(const Personnage1984& perso1984)const;
        bool ajouterPersonnage(const Personnage1984& perso1984);
        bool retirerPersonnage(const Personnage1984& perso1984);

        void deplacer();
        void combat();
        bool gameOver()const;
        string str()const;
        string to_string()const;



};

#endif // ARENE1984_H
