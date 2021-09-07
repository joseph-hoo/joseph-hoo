#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

class Dollar
{
private:
	int noteVal;
	int coinVal;

public:
	// get the name of the currency type
	std::string getCountry();

	// default constructor
	Dollar();

	// overload constructor
	Dollar(int noteValue, int coinValue);

	// copy constructor
	Dollar(const Dollar& copiedDollar);

	// destructor
	~Dollar();

	// setNoteVal
	void setNoteVal(int noteValToSet);

	// setCoinVal
	void setCoinVal(int coinValToSet);

	// getNoteVal
	int getNoteVal();

	// getCoinVal
	int getCoinVal();

	// compare lessthan greaterthan
	bool lessThan(Dollar& right)
	{
		if (this->getCountry() == right.getCountry())
		{
			if (this->noteVal < right.noteVal)
			{
				return true;
			}
			else if (this->coinVal < right.coinVal) {
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			throw "Mismatched Types";
		}
	}


	// Adding two objects of the same currency
	void add(Dollar& right)
	{
		if (this->getCountry() == right.getCountry())
		{
			this->noteVal += right.noteVal;
			this->coinVal += right.coinVal;
		}
		else
		{
			throw "Mismatched Types";
		}
	}

	// Subtracting one object from another
	void subtract(Dollar& right)
	{
		if (this->getCountry() == right.getCountry())
		{
			this->noteVal -= right.noteVal;
			this->coinVal -= right.coinVal;
		}
		else
		{
			throw "Mismatched Types";
		}
	}

	// Comparing equality or inequality
	bool equality(Dollar& right)
	{
		if (this->getCountry() != right.getCountry())
		{
			throw "Mismatched Types";
		}
		else
		{
			if ((this->noteVal == right.noteVal) && (this->coinVal == right.noteVal))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	// print details of the currency object
	void print(Dollar& toPrint)
	{
		std::cout << toPrint.getNoteVal() << "."
			<< toPrint.getCoinVal();

	}

	bool const operator<(Dollar right) {
		if (this->getNoteVal() < right.noteVal) {
			return true;
		}
		else if (right.noteVal < this->getNoteVal()) {
			return false;
		}
		else if (this->getCoinVal() < right.coinVal) {
			return true;
		}
		else {
			return false;
		}
	}

	bool const operator==(Dollar right) {
		if (this->getNoteVal() == right.getNoteVal() &&
			(this->getCoinVal() == right.getCoinVal())) {
			return true;
		}
		else {
			return false;
		}
	}

	friend std::ostream& operator<<(std::ostream& output, const Dollar& dollar) {
		output << dollar.noteVal << "." << dollar.coinVal;

		return output;
	}
};
