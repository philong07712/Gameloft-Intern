#pragma once
#include "FluVirus.h"
#include <time.h>
#define RED 0xff0000
#define BLUE 0x0000ff

FluVirus::FluVirus()
{
	this->DoBorn();
	this->InitResistance();
}
void FluVirus::DoBorn()
{
	this->LoadADNInformation();
	int *colorArray = new int[2]{ BLUE, RED };
	// set Random value change eachtime call
	// random [0, 1]
	int index = rand() % 2;
	this->m_color = colorArray[index];
	delete[] colorArray;
}

int FluVirus::getColor()
{
	return this->m_color;
}

void FluVirus::setColor(int color)
{
	this->m_color = color;
}
list<Virus *> FluVirus::DoClone()
{
	list<Virus *> l;
	FluVirus *v = new FluVirus(*this);
	l.push_back(v);
	return l;
}

void FluVirus::InitResistance()
{
	int resit;
	// random value for color blue
	if (this->m_color == BLUE)
	{
		resit = 10 + rand() % 11;
	}
	// random value for color red;
	else
	{
		resit = 10 + rand() % 6;
	}
	this->setResistance(resit);
}

void FluVirus::DoDie()
{
	// cout << "FluVirus died" << endl; 
}

FluVirus::~FluVirus()
{
	this->DoDie();
}