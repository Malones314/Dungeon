#include "Shield.h"
#include<string>
using namespace std;
int Shield::getValue ( ) {
	return value;
}
int Shield::getDefence ( ) {
	return defence;
}
int Shield::getAttack ( ) {
	return attack;
}
Shield::Shield ( ) {
	attack = 0;
	defence = 0;
	value = 0;
}
Shield::Shield ( int defence_, int attack_, int value_ ) {
	defence = defence_;
	attack = attack_;
	value = value_;
}
void Shield::newAttack ( int newNumber ) {
	attack = newNumber;
}
void Shield::newDefence ( int newNumber ) {
	defence = newNumber;
}
void Shield::newValue ( int newNumber ) {
	value = newNumber;
}
void Shield::newShield ( Shield* newShield ) {
	this->attack = newShield->attack;
	this->defence = newShield->defence;
	this->value = newShield->value;
}
