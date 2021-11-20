#include <iostream>
#include "Position1984.h"
#include "Arene1984.h"
#include "Personnage1984.h"
#include "Druide1984.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Position1984 p(1,2);
    cout<<p.str()<<endl;
    Personnage1984 pet("Petunia",10,p);
    cout<<pet.str()<<endl;
    Position1984 p2(2,2);
    Druide1984 harry("Harry",30,p2,4);
    cout<<harry.getInfo()<<endl;
    cout<<"*** Personnages presents dans le jeu ***"<<endl;
    Position1984 p3(2,4);
    Druide1984 ron("Ron",30,p3,1);
    Position1984 p5(1,1);
    Personnage1984 bob("Bob",5,p5);
    Arene1984 arene;
    arene.ajouterPersonnage(pet);
    arene.ajouterPersonnage(pet);
    arene.ajouterPersonnage(harry);
    arene.ajouterPersonnage(ron);
    arene.ajouterPersonnage(bob);
    cout<<arene.str()<<endl;
    cout<<endl;
    cout<<"***********************retirerPersonnage***********************"<<endl;
    arene.retirerPersonnage(bob);
    cout<<arene.str()<<endl;
    cout<<"***************************************************************"<<endl;
    cout<<endl;
    cout<<"*************************to_string*****************************"<<endl;
    cout<<arene.to_string();
    cout<<endl;
    cout<<"***********************    copie    ***************************"<<endl;
    Arene1984 copie;
    copie=arene;
    cout<<copie.to_string();
    cout<<endl;
    cout<<"***************************************************************"<<endl;
    cout<<"********************LANCEMENT DE LA PARTIE*********************"<<endl;
    while(!arene.gameOver()){
        cout<<"***************************************************************"<<endl;
        arene.deplacer();
        cout<<arene.to_string();
    }
    cout<<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"+++++++++++++++++++++++ FIN DE PARTIE +++++++++++++++++++++++++"<<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<arene.to_string();
    return 0;
}
