#include "Personnage1984.h"

Personnage1984::Personnage1984(string nom1984, int vie1984, Position1984 position1984):nom1984(nom1984), vie1984(vie1984), position1984(position1984)
{

}

Personnage1984::~Personnage1984()
{

}

Personnage1984::Personnage1984(const Personnage1984& other):nom1984(other.nom1984), vie1984(other.vie1984), position1984(other.position1984)
{

}

Personnage1984& Personnage1984::operator=(const Personnage1984& rhs)
{
    if (this != &rhs)
    {
        nom1984 = rhs.nom1984;
        vie1984 = rhs.vie1984;
        position1984 = rhs.position1984;
    }
    return *this;
}

bool Personnage1984::operator==(const Personnage1984& perso1984) const
{
    return nom1984 == perso1984.nom1984;
}

Personnage1984* Personnage1984::clone() const
{
    return new Personnage1984(*this);
}

string Personnage1984::str() const
{
    return nom1984 +", "+ to_string(vie1984) +", "+ position1984.str();
}

string Personnage1984::getInfo()const
{
    stringstream ss;

    ss << nom1984[0] << "-" << vie1984;

    return ss.str();
}


Position1984 Personnage1984::getPosition()
{
    return position1984;
}


void Personnage1984::setPosition(int x1984, int y1984)
{
    position1984.setX1984(x1984);
    position1984.setY1984(y1984);
}

int Personnage1984::getVie()
{
    return vie1984;
}


void Personnage1984::prendreDegat(int vie1984)
{
    this->vie1984 -= vie1984;
}

int Personnage1984::attaquer()const
{
    return vie1984;
}


