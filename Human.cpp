#include "Human.h"
Human::Human ( ) {
	basicAttack = 0;
	basicTotalBlood = 0;
	immediateBlood = 0;
	basicDefence = 0;
}
Human::Human ( int basicTotalBlood_, int immediateBlood_, int basicAttack_, int basicDefence_ ) {
	basicTotalBlood = basicTotalBlood_;
	immediateBlood = immediateBlood_;
	basicAttack = basicAttack_;
	basicDefence = basicDefence_;
}
void Human::changeBasicAttack ( int changeNumber ) {
	basicAttack += changeNumber;
}
void Human::changeBasicTotalBlood ( int changeNumber ) {
	basicTotalBlood += changeNumber;
}
void Human::changeImmediateBlood ( int changeNumber ) {
	immediateBlood += changeNumber;
	if ( immediateBlood > basicTotalBlood )
		immediateBlood = basicTotalBlood;
}
void Human::changeBasicDefence ( int changeNumber ) {
	basicDefence += changeNumber;
}
int Human::getBasicAttack ( ) {
	return basicAttack;
}
int Human::getBasicDefence ( ) {
	return basicDefence;
}

int Human::getBasicTotalBlood ( ) {
	return basicTotalBlood;
}
int Human::getImmediateBlood ( ) {
	return immediateBlood;
}
void Human::newBasicTotalBlood ( int newNumber ) {
	basicTotalBlood = newNumber;
}
void Human::newBasicAttack ( int newNumber ) {
	basicAttack = newNumber;
}
void Human::newImmediateBlood ( int newNumber ) {
	immediateBlood = newNumber;
}
void Human::newBasicDefence ( int newNumber ) {
	basicDefence = newNumber;
}
