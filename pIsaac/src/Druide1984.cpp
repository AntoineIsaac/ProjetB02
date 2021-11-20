#include "Druide1984.h"

Druide1984::Druide1984(string nom1984, int vie1984, Position1984 position1984, int magie1984):Personnage1984(nom1984, vie1984, position1984), magie1984(magie1984)
{
    //ctor
}

Druide1984::~Druide1984()
{
    //dtor
}

Druide1984::Druide1984(const Druide1984& other):Personnage1984(other), magie1984(other.magie1984)
{
    //copy ctor
}

Druide1984& Druide1984::operator=(const Druide1984& rhs)
{
    if (this != &rhs)
    {
        Personnage1984::operator=(rhs);
        magie1984 = rhs.magie1984;
    }
    return *this;
}

Druide1984* Druide1984::clone() const
{
    return new Druide1984(*this);
}

string Druide1984::str() const
{
    return Personnage1984::str();
}

string Druide1984::getInfo() const
{
    return Personnage1984::getInfo() + "-" + to_string(magie1984);
}

void Druide1984::prendreDegat(int vie1984)
{
    this->vie1984 -= vie1984 - magie1984;
}

int Druide1984::attaquer()const
{
    return Personnage1984::attaquer() + magie1984;
}



