#include "HealthPot.h"
HealthPot::HealthPot ( ) :value ( 0 ), blood ( 0 ) { }
HealthPot::HealthPot ( int blood_, int  value_ ):blood ( blood_ ), value ( value_ ) { }
int HealthPot::getValue ( ) {
	return value;
}
int HealthPot::getBlood ( ) {
	return blood;
}
void HealthPot::newBlood ( int newNumber ) {
	blood = newNumber;
}
void HealthPot::newValue ( int newNumber ) {
	value = newNumber;
}
void HealthPot::changeBlood ( int changeNumber ) {
	blood += changeNumber;
}
void HealthPot::changeValue ( int changeNumber ) {
	value += changeNumber;
}
