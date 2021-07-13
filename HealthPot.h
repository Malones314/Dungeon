#ifndef HEALTHPOT_H
#define HEALTHPOT_H
class HealthPot {
	private:
		int blood;
		int value;
	public:
		HealthPot ( );
		HealthPot ( int blood_, int value_ );
		int getValue ( );
		int getBlood ( );
		void newBlood ( int newNumber );
		void newValue ( int newNumber );
		void changeBlood ( int changeNumber );
		void changeValue ( int changeNumber );
};
#endif
