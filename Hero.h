#ifndef HERO_H
#define HERO_H
#include "Human.h"
#include"Sword.h"
#include"Shield.h"
class Hero :
    public Human { 
        private:
        Sword mySword;
        Shield myShield;
        int immeditateExp;
        int totalExp;
        int level;
        bool withSword;
        bool withShield;
    public:
        Hero ( );
        Hero ( int basicTotalBlood_, int immediateBlood_, int basicAttack_, int basicDefence_, int immeditateExp_, int totalExp_, int level_ );
        void changeTotalExp ( int changeNumber );
        void changeImmeditateExp ( int changeNumber );
        void heroNewSword ( Sword* newSword_ );
        void heroNewShield ( Shield* newShield_ );
        void newTotalExp ( );
        int getImmeditateExp ( );
        int getTotalExp ( );
        int getLevel ( );
        bool getWithSword ( );
        bool getWithShield ( );
        void changeWithSword ( );
        void changeWithShield ( );
        friend class Sword;
        friend class Shield;
};
#endif
