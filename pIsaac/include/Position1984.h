#ifndef POSITION1984_H
#define POSITION1984_H
#include <string>

using namespace std;


class Position1984
{
    private:
        int x1984;
        int y1984;

    public:
        Position1984();
        Position1984(int x1984, int y1984);
        virtual ~Position1984();
        Position1984(const Position1984& other);
        Position1984& operator=(const Position1984& other);

        string str()const;
        bool operator==(const Position1984& pos1984)const;

        int getX1984()const;
        void setX1984(int x1984);

        int getY1984()const;
        void setY1984(int y1984);
};

#endif // POSITION1984_H
