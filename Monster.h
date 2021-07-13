#ifndef MONSTER_H
#define MONSTER_H
#include "Human.h"
class Monster :
    public Human {
    private:
        int exp;   //死亡掉落经验         level/10+10
        int deadLeft;   //死亡掉落物品：1为血瓶，2为装备
    public:
        Monster ( );
        Monster ( int basicTotalBlood_, int immediateBlood_, int basicAttack_, int basicDefence_, int exp_, int deadLeft_ );
        void newExp ( int newNumber );
        void newDeadLeft ( int newNumber );
        int getDeadLeft ( );
        int getExp ( );
};

#endif // !
