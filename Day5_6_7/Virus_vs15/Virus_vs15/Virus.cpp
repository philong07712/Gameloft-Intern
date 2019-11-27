#include "Virus.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
Virus::Virus() : m_dna(NULL), m_resistance(10)
{
}
Virus::Virus(const Virus & v)
{
	this->setDna(v.getDna());
	this->setResistance(v.getResistance());
}
void Virus::LoadADNInformation()
{
	// take value form ATGX.bin
	ifstream myfileLoad("ATGX.bin");
	string line;
	getline(myfileLoad, line);
	this->m_dna = new char[line.length() + 1];
	strcpy_s(this->m_dna, line.length() + 1, line.c_str());
}

void Virus::ReduceResistance(int medicine_resistance)
{
	this->m_resistance = m_resistance - medicine_resistance;
}

char* Virus::getDna() const
{
	return this->m_dna;
}

int Virus::getResistance() const
{
	return this->m_resistance;
}

void Virus::setDna(char * dna)
{
	delete[] this->m_dna;
	this->m_dna = new char[48];
	for (int i = 0; i < 48; i++) {
		this->m_dna[i] = dna[i];
	}
}

void Virus::setResistance(int resit)
{
	this->m_resistance = resit;
}

Virus::~Virus()
{
	delete[] this->m_dna;
}
