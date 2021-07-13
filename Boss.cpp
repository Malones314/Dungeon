#include "Boss.h"
Boss::Boss ( ) {
	beHatedTimes = 0;
	damageReduction = 0;
	damageReductionTimes = 0;
}
Boss::Boss ( int basicTotalBlood_, int immediateBlood_, int basicAttack_, int basicDefence_ ):Human ( basicTotalBlood_, immediateBlood_, basicAttack_, basicDefence_ ) {
	beHatedTimes = 0;
	damageReduction = 0;
	damageReductionTimes = 0;
}
void Boss::addBeHatedTimes ( ) {
	beHatedTimes++;
}
void Boss::reduceDamageReductionTimes ( ) {
	damageReductionTimes--;
}
double Boss::getDamageReduction ( ) {
	return damageReduction;
}
void Boss::newDamageReduction ( double newNumber ) {
	damageReduction = newNumber;
}
void Boss::resetBeHatedTimes ( ) {
	beHatedTimes = 0;
}
void Boss::resetDamageReductionTimes ( ) {
	damageReductionTimes = 3;
}
int Boss::getBeHatedTimes ( ) {
	return beHatedTimes;
}
int Boss::getDamageReductionTimes ( ) {
	return damageReductionTimes;
}
