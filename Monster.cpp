#include "Monster.h"
Monster::Monster ( ) {
	exp = 0;
	deadLeft = 0;
}
Monster::Monster ( int basicTotalBlood_, int immediateBlood_, int basicAttack_, int basicDefence_ , int exp_, int deadLeft_) :Human ( basicTotalBlood_, immediateBlood_, basicAttack_, basicDefence_ ) {
	exp = exp_;
	deadLeft = deadLeft_;
}
void Monster::newExp ( int newNumber ) {
	exp += newNumber;
}
void Monster::newDeadLeft ( int changeNumber) {
	deadLeft = changeNumber;
}
int Monster::getExp ( ) {
	return exp;
}
int Monster::getDeadLeft ( ) {
	return deadLeft;
}

