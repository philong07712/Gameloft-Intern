#pragma once
#include "DengueVirus.h"
#include <time.h>
#include <list>
# include "string"
using namespace std;
DengueVirus::DengueVirus()
{
	this->DoBorn();
	this->InitResistance();
}

void DengueVirus::DoBorn()
{
	this->LoadADNInformation();
	string *proteinArray = new string[3]{ "NS3", "NS5", "E" };
	// set Random value change eachtime call
	// random [0, 2]
	int index = rand() % 3;
	// get string type
	string type = proteinArray[index];
	// turn string to char*
	strcpy_s(this->m_protein, 4, type.c_str());
	delete[] proteinArray;
}

void DengueVirus::InitResistance()
{
	int resit;
	// random value for color NS3
	string protein = this->m_protein;
	if (protein == "NS3")
	{
		resit = 1 + rand() % 10;
	}
	// random value for color NS5;
	else if (protein == "NS5")
	{
		resit = 11 + rand() % 10;
	}
	else
	{
		resit = 21 + rand() % 10;
	}

	this->setResistance(resit);
}


list<Virus*> DengueVirus::DoClone()
{
	list<Virus*> l;
	for (int i = 0; i < 2; i++)
	{
		DengueVirus *v = new DengueVirus(*this);
		l.push_back(v);
	}
	return l;
}

char *DengueVirus::getProtein()
{
	return this->m_protein;
}

void DengueVirus::setProtein(char *c)
{
	for (int i = 0; i < 4; i++) {
		this->m_protein[i] = c[i];
	}
}

void DengueVirus::DoDie()
{
	// cout << "DengueVirus died" << endl;
}

DengueVirus::~DengueVirus()
{
	this->DoDie();
}