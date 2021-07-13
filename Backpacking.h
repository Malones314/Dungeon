#ifndef BACKPACKING_H
#define BACKPACKING_H
class Backpacking { 
	private:
		int money;
		int shieldNumber;
		int swordNumber;
		int healthPotNumber;
	public:
		Backpacking ( );
		Backpacking ( int money_, int shieldNumber_, int swordNumber_, int healthPotNumber_ );
		int getMoney ( );
		int getShieldNumber ( );
		int getSwordNumber ( );
		int getHealthPotNumber ( );
		void changeMoney ( int changeNumber );
		void changeShieldNumber ( int changeNumber );
		void changeSwordNumber ( int changeNumber );
		void changeHealthPotNumber ( int changeNumber );
};

#endif // !BACKPACKING_H


