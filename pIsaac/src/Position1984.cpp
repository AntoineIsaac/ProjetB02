#include "Position1984.h"

Position1984::Position1984(int x1984, int y1984):x1984(x1984), y1984(y1984)
{
    //ctor
}

Position1984::~Position1984()
{
    //dtor
}

Position1984::Position1984(const Position1984& other):x1984(other.x1984), y1984(other.y1984)
{
    //copy ctor
}

Position1984& Position1984::operator=(const Position1984& rhs)
{
    if (this != &rhs)
    {
        x1984 = rhs.x1984;
        y1984 = rhs.y1984;
    }
    return *this;
}


string Position1984::str() const
{
    return "("+ to_string(x1984)+", "+ to_string(y1984) +")";
}

bool Position1984::operator==(const Position1984& pos1984) const
{
    return x1984 == pos1984.x1984 && y1984 == pos1984.y1984;
}


int Position1984::getX1984() const
{
    return x1984;
}


void Position1984::setX1984(int x1984)
{
    this->x1984 = x1984;
}

int Position1984::getY1984() const
{
    return y1984;
}

void Position1984::setY1984(int y1984)
{
    this->y1984 = y1984;
}




