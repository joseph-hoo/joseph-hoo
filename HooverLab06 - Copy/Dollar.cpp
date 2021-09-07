#include "Dollar.h"
#include <iostream>

//DEFAULT CONSTRUCTOR
Dollar::Dollar()
{
	noteVal = 0;
	coinVal = 0;
}

//CONSTRUCTOR WITH PARAMETERS
Dollar::Dollar(int noteValue, int coinValue)
{
	noteVal = noteValue;
	coinVal = coinValue;
}

//COPY CONSTRUCTOR
Dollar::Dollar(const Dollar& copiedDollar)
{
	setNoteVal(copiedDollar.noteVal);
	setCoinVal(copiedDollar.coinVal);

}

//DESTRUCTOR
Dollar::~Dollar()
{

}

//SETTERS FOR NOTE VAL, THEN COIN VAL
void Dollar::setNoteVal(int noteValToSet) // Set the note value
{
	noteVal = noteValToSet;
}
void Dollar::setCoinVal(int coinValToSet) // Set the coin value
{
	while (coinValToSet >= 100)
	{
		coinValToSet -= 100;
		noteVal += 1;
	}
	coinVal = coinValToSet;
}

//GETTERS FOR NOTE VAL, THEN COIN VAL
int Dollar::getNoteVal() // Get total note value
{
	return noteVal;
}
int Dollar::getCoinVal() // Get total coin value
{
	return coinVal;
}

