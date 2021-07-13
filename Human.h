#ifndef HUMAN_H
#define HUMAN_H
class Human {
	private:
		int basicTotalBlood;
		int immediateBlood;
		int basicAttack;
		int basicDefence;
	public:
		Human ( );
		Human ( int basicTotalBlood_, int immediateBlood_, int basicAttack_, int basicDefence_ );

		int getBasicTotalBlood ( );
		int getImmediateBlood ( );
		int getBasicAttack ( );
		int getBasicDefence ( );
		void changeBasicTotalBlood ( int changeNumber );
		void changeBasicAttack ( int changeNumber );
		void changeImmediateBlood ( int changeNumber);
		void changeBasicDefence ( int chanageNumber );
		void newBasicTotalBlood ( int newNumber );
		void newBasicAttack ( int newNumber );
		void newImmediateBlood ( int newNumber );
		void newBasicDefence ( int newNumber );
};
#endif
