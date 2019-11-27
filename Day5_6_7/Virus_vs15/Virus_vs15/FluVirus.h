#pragma once
#include "Virus.h"
#include <list>
using namespace std;
class FluVirus : public Virus
{
	int m_color;

public:
	FluVirus();
	int getColor();
	void setColor(int);
	void DoBorn();
	list<Virus *> DoClone();
	void DoDie();
	void InitResistance();
	~FluVirus();
};