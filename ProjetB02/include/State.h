#ifndef STATE_H
#define STATE_H

class Player;

class State
{
    public:
        State();
        State(Player* player);
        virtual ~State();
        State(const State& other);
        State& operator=(const State& other);

        // Méthodes qui vont implémenter le DP
        virtual void setSlow(float fps) = 0;
        virtual void setNormal(float fps) = 0;

        virtual void setPlayer(Player* player);
    protected:
        Player* player;
};

#endif // STATE_H
