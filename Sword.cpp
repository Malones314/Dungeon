#include "Sword.h"
#include<string>
using namespace std;
int Sword::getValue ( ) {
	return value;
}
int Sword::getDefence ( ) {
	return defence;
}
int Sword::getAttack ( ) {
	return attack;
}
Sword::Sword ( ) {
	attack = 0;
	defence = 0;
	value = 0;
}
Sword::Sword ( int defence_, int attack_, int value_ ) {
	defence = defence_;
	attack = attack_;
	value = value_;
}
void Sword::newAttack ( int newNumber ) {
	attack = newNumber;
}
void Sword::newDefence ( int newNumber ) {
	defence = newNumber;
}
void Sword::newValue ( int newNumber ) {
	value = newNumber;
}
void Sword::newSword ( Sword* newSword ) {
	this->attack = newSword->attack;
	this->defence = newSword->defence;
	this->value = newSword->value;
}
