#ifndef STATE_H
#define STATE_H

class Player;

//Ce DP State permet de gérer la vitesse d'un Player en fonction de la surface sur laquelle il marche.
//Si il traverse des toiles d'araignées ou de l'eau, la méthode setSlow() sera appelée et sa vitesse sera réduite.
//Si il marche sur des SpeedBlock, la méthode setSpeed() sera appelée et sa vitesse se augmentée.
//Sinon, la méthode setNormal sera appelée et sa vitesse sera remise à la vitesse normale.
//Les méthodes setSlow, setNormal et setSpeed sont appelées dans la classe enfant correspondant à l'état en vigueur.
class State
{
    //Instance de Player dont la vitesse sera modifiée.
    protected:
        Player* player;

    public:
        State();
        State(Player* player);
        virtual ~State();
        State(const State& other);
        State& operator=(const State& other);

        // Méthodes qui vont implémenter le DP
        virtual void setSlow(float fps) = 0;
        virtual void setNormal(float fps) = 0;
        virtual void setSpeed(float fps) = 0;

        virtual void setPlayer(Player* player);

};

#endif // STATE_H
