#include "Virus.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

Virus::Virus() : m_dna(NULL), m_resistance(10)
{
}

Virus::Virus(const Virus &v)
{
    this->m_dna = v.getM_dna();
    this->m_resistance = v.getM_resistance();
}

char *Virus::getM_dna() const
{
    return this->m_dna;
}

int Virus::getM_resistance() const
{
    return this->m_resistance;
}

void Virus::setM_dna(char *dna)
{
    this->m_dna = dna;
}

void Virus::setM_resistance(int resit)
{
    this->m_resistance = resit;
}

void Virus::ReduceResistance(int medicine_resistance)
{
    this->m_resistance = m_resistance - medicine_resistance;
}
void Virus::LoadADNInformation()
{
    // take value form ATGX.bin
    ifstream myfileLoad("ATGX.bin");
    string line;
    getline(myfileLoad, line);
    this->m_dna = new char[line.length() + 1];
    strcpy(this->m_dna, line.c_str());
}

Virus::~Virus()
{
}
