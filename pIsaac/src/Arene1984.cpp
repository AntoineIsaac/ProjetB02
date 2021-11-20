#include "Arene1984.h"

Arene1984::Arene1984()
{

}

Arene1984::~Arene1984()
{
    for(int i = 0; i < personnages1984.size(); i++)
    {
        delete personnages1984[i];
    }
    personnages1984.clear();
}

Arene1984::Arene1984(const Arene1984& other)
{
    for(int i = 0; i < personnages1984.size(); i++)
    {
        personnages1984.push_back(other.personnages1984[i]->clone());
    }
}

Arene1984& Arene1984::operator=(const Arene1984& rhs)
{
    if (this != &rhs)
    {
        for(int i = 0; i < personnages1984.size(); i++)
        {
            delete personnages1984[i];
        }
        personnages1984.clear();

        for(int i = 0; i < rhs.personnages1984.size(); i++)
        {
            personnages1984.push_back(rhs.personnages1984[i]->clone());
        }
    }
    return *this;
}

int Arene1984::rechercherPersonnage(const Personnage1984& perso1984) const
{
    for(int i = 0; i<personnages1984.size(); i++)
    {
        if(*(personnages1984[i]) == perso1984)
        {
            return i;
        }
    }
    return -1;
}


bool Arene1984::ajouterPersonnage(const Personnage1984& perso1984)
{
    if(rechercherPersonnage(perso1984) == -1)
    {
        personnages1984.push_back(perso1984.clone());
        return true;
    }
    return false;
}

bool Arene1984::retirerPersonnage(const Personnage1984& perso1984)
{
    int indice = rechercherPersonnage(perso1984);

    if(indice != - 1)
    {
        delete personnages1984[indice];
        personnages1984.erase(personnages1984.begin() + indice);
        return true;
    }
    return false;
}

void Arene1984::deplacer()
{
    for(int i = 0; i < personnages1984.size(); i++)
    {
        int randomX1984 = rand()%5;
        int randomY1984 = rand()%5;

        personnages1984[i]->setPosition(randomX1984, randomY1984);
    }
    combat();
}

void Arene1984::combat()
{
    for(int i = 0; i < personnages1984.size(); i++)
    {
        for(int j = 0; j < personnages1984.size(); j++)
        {
            if(i == j)
            {
                continue;
            }
            Personnage1984& a = *(personnages1984[i]);
            Personnage1984& b = *(personnages1984[j]);

            if(a.getPosition() == b.getPosition())
            {
                if(a.getVie() == b.getVie())
                {
                    retirerPersonnage(a);
                    retirerPersonnage(b);
                }

                else if(a.getVie() > b.getVie())
                {
                    a.prendreDegat(b.attaquer());
                    retirerPersonnage(b);

                }
                else if(a.getVie() < b.getVie())
                {
                    b.prendreDegat(a.attaquer());
                    retirerPersonnage(a);

                }
            }
        }
    }
}

bool Arene1984::gameOver() const
{
    return personnages1984.size() < 2;
}

string Arene1984::str() const
{
    string s = "";
    for(int i = 0; i<personnages1984.size(); i++)
    {
        s += personnages1984[i]->str()+"\n";
    }
    return s;
}

string Arene1984::to_string() const
{
    stringstream s;

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            bool caseLibre = true;

            for(int k = 0; k < personnages1984.size(); k++)
            {
                if(personnages1984[k]->getPosition().getX1984() == i && personnages1984[k]->getPosition().getY1984() == j)
                {
                    s << setw(10) << personnages1984[k]->getInfo();
                    caseLibre = false;
                }
            }

            if(caseLibre == true)
            {
                s << internal;
                s << setw(10) << "+";
            }
        }
        s << endl;
    }
    return s.str();
}



