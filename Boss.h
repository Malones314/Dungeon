#ifndef BOSS_H
#define BOSS_H
#include "Human.h"
class Boss :   //被攻击五次自己攻击一次，每自己攻击一次减少英雄50%目前血量，自己减少20%承受伤害3回合
    public Human {
    private:
        int beHatedTimes;
        double damageReduction;   //伤害减免(0-1之间)
        int damageReductionTimes;   //伤害减免剩余回合, 默认3回合
    public:
        void addBeHatedTimes ( );
        void resetBeHatedTimes ( );
        int getBeHatedTimes ( );
        double getDamageReduction( );
        void newDamageReduction ( double newNumber);
        int getDamageReductionTimes ( );
        void reduceDamageReductionTimes ( );
        void resetDamageReductionTimes ( );
        Boss ( );
        Boss ( int basicTotalBlood_, int immediateBlood_, int basicAttack_, int basicDefence_ );
};



#endif // !BOSS_H
