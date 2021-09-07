#pragma once

#include "Dollar.h"
#include <iostream>
#include <string>

/*
	USD DOLLAR CLASS
*/
class USD : public Dollar
{
private:
	std::string uSDName = "USD";
public:
	std::string getCountry() { return uSDName; }

};

/*
	AUD DOLLAR CLASS
*/
class AUD : public Dollar
{
private:
	std::string aUDName = "AUD";
public:
	std::string getCountry() { return aUDName; }

};

/*
	CAD DOLLAR CLASS
*/
class CAD : public Dollar
{
private:
	std::string cADName = "CAD";
public:
	std::string getCountry() { return cADName; }

};
