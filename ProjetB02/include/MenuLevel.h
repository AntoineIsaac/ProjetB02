#ifndef MENULEVEL_H
#define MENULEVEL_H

#include "Menu.h"

class MenuLevel : public Menu
{

    private:
        bool level1Succeed = false;
        bool level2Succeed = false;
        bool level3Succeed = false;

    public:
        MenuLevel();
        virtual ~MenuLevel();
        MenuLevel(const MenuLevel& other);
        MenuLevel& operator=(const MenuLevel& other);

        void startMenu();
        void levelFinish(int level);


};

#endif // MENULEVEL_H
