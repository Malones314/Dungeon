#include "Backpacking.h"
Backpacking::Backpacking ( ) {
	money = 0;
	shieldNumber = 0;
	swordNumber = 0;
	healthPotNumber = 0;
}
Backpacking::Backpacking ( int money_, int shieldNumber_, int swordNumber_, int healthPotNumber_ ) {
	money = money_;
	shieldNumber = shieldNumber_;
	swordNumber = swordNumber_;
	healthPotNumber = healthPotNumber_;
}
int Backpacking::getMoney ( ) {
	return money;
}
int Backpacking::getShieldNumber ( ) {
	return shieldNumber;
}
int Backpacking::getSwordNumber ( ) {
	return swordNumber;
}
int Backpacking::getHealthPotNumber ( ) {
	return healthPotNumber;
}
void Backpacking::changeMoney ( int changeNumber ) {
	money += changeNumber;
}
void Backpacking::changeShieldNumber ( int changeNumber ) {
	shieldNumber += changeNumber;
}
void Backpacking::changeSwordNumber ( int changeNumber ) {
	swordNumber += changeNumber;
}
void Backpacking::changeHealthPotNumber ( int changeNumber ) {
	healthPotNumber += changeNumber;
}
