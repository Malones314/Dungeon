#ifndef SHIELD_H
#define SHIELD_H
#include<string>
using namespace std;
class Shield {
	private:
		int defence;
		int attack;
		int value;
	public:
		int getValue ( );
		int getDefence ( );
		int getAttack ( );
		string getName ( );
		Shield ( );
		Shield ( int addDefence_, int addAttack_, int value_);
		void newAttack ( int newNumber );
		void newDefence ( int newNumber );
		void newValue ( int newNumber );
		void newShield ( Shield* newShield );
}; 
#endif // !SHIELD_H


