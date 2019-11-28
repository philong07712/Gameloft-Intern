#pragma once
#include "Patient.h"
#include <time.h>
# include "iostream"
using namespace std;
Patient::Patient()
{
	srand((int)time(0));
	this->InitResistance();
	this->DoStart();
}

void Patient::DoStart()
{
	int numV = 10 + rand() % 11;
	for (int i = 0; i < numV; i++)
	{
		// Random virus type
		int type = rand() % 2;
		// Case flu
		if (type == 0)
		{
			Virus *v = new FluVirus();
			this->m_virusList.push_back(v);
		}

		// case Dengue
		else
		{
			Virus *v = new DengueVirus();
			this->m_virusList.push_back(v);

		}
	}
	// this->m_virusList.push_back
	this->m_state = 1;
}
void Patient::InitResistance()
{
	int resit = 1000 + rand() % 8001;
	this->m_resistance = resit;
}

void Patient::TakeMedicine(int medicine_resitance)
{
	int resVirus = 0;
	list<Virus *>::iterator it = this->m_virusList.begin();
	// iteator all the Viruses
	while (it != this->m_virusList.end())
	{
		(*it)->ReduceResistance(medicine_resitance);
		// Clone virus stage
		if ((*it)->getResistance() > 0)
		{
			list<Virus *> cloned = (*it)->DoClone();
			m_virusList.insert(it, cloned.begin(), cloned.end());
			++it;
		}
		// If virus was died
		else
		{
			delete *it;
			*it = nullptr;
			it = this->m_virusList.erase(it);
		}
	}
	int sum = 0;
	// Testing after cloned
	for (it = this->m_virusList.begin(); it != this->m_virusList.end(); ++it)
	{
		sum += (*it)->getResistance();
	}
	cout << "Sum: " << sum << endl;
	if (this->m_resistance < sum)
	{
		this->DoDie();
	}
}

list<Virus*> Patient::getVirusList() {
	return this->m_virusList;
}

int Patient::GetState()
{
	return this->m_state;
}

void Patient::DoDie()
{
	cout << "Patient died\n";
	this->m_state = 0;
	list<Virus*> ::iterator it;
	for (it = this->m_virusList.begin(); it != this->m_virusList.end(); ++it) {
		delete *it;
	}
}

Patient::~Patient()
{
	// this->DoDie();
}