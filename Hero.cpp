#include "Hero.h"
#include"Sword.h"
#include"Shield.h"
Hero::Hero ( ) {
	immeditateExp = 0;
	totalExp = 0;
	level = 0;
	withSword = 0;
	withShield = 0;
}
Hero::Hero ( int basicTotalBlood_, int immediateBlood_, int basicAttack_, int basicDefence_, int immeditateExp_, int totalExp_, int level_ ):Human ( basicTotalBlood_, immediateBlood_, basicAttack_, basicDefence_ ) {
	immeditateExp = immeditateExp_;
	totalExp = totalExp_;
	level = level_;
	withShield = false;
	withSword = false;
}
void Hero::changeTotalExp ( int changeNumber ) {
	totalExp += changeNumber;
}
void Hero::changeImmeditateExp ( int changeNumber ) {
	immeditateExp += changeNumber;
}
void Hero::heroNewSword ( Sword* newSword_ ) {
	this->mySword.newSword ( newSword_ );
}
void Hero::heroNewShield ( Shield* newShield_ ) {
	myShield.newShield ( newShield_ );
}
int Hero::getImmeditateExp ( ) {
	return immeditateExp;
}
int Hero::getTotalExp ( ) {
	return totalExp;
}
int Hero::getLevel ( ) {
	return level;
}
bool Hero::getWithSword ( ) {
	return withSword;
}
bool Hero::getWithShield ( ) {
	return withShield;
}
void Hero::newTotalExp ( ) {
	totalExp = 100 * ( level / 10 + 1 );
}
void Hero::changeWithShield ( ) {
	withShield = ( withShield ? 0 : 1 );
}
void Hero::changeWithSword ( ) {
	withSword = ( withSword ? 0 : 1 );
}
