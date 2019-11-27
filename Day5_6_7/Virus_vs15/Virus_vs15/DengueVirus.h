#pragma once
#include "Virus.h"
class DengueVirus : public Virus
{
	char m_protein[4];

public:
	DengueVirus();
	char *getProtein();
	void setProtein(char*);
	//
	void DoBorn();
	list<Virus*> DoClone();
	void DoDie();
	void InitResistance();
	~DengueVirus();
};