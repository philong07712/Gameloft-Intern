#pragma once
#include "DengueVirus.h"
#include <time.h>
#include <list>
DengueVirus::DengueVirus()
{
    srand(time(0));
    this->DoBorn();
    this->InitResistance();
}

void DengueVirus::DoBorn()
{
    this->LoadADNInformation();
    string *proteinArray = new string[3]{"NS3", "NS5", "E"};
    // set Random value change eachtime call
    // random [0, 2]
    int index = rand() % 3;
    // get string type
    string type = proteinArray[index];
    // turn string to char*
    strcpy(this->m_protein, type.c_str());
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

    this->setM_resistance(resit);
}

void DengueVirus::DoDie()
{
    cout << "Died";
}

Virus *DengueVirus::DoClone()
{
    DengueVirus *list = new DengueVirus[2];
    for (int i = 0; i < 2; i++)
    {
        list[i].setM_dna(this->getM_dna());
        list[i].setM_resistance(this->getM_resistance());
        list[i].setM_protein(this->getM_protein());
    }
    for (int i = 0; i < 2; i++)
    {
        cout << list[i].getM_resistance();
    }
    return list;
}

char *DengueVirus::getM_protein()
{
    return this->m_protein;
}

void DengueVirus::setM_protein(char *c)
{
    strcpy(this->m_protein, c);
}

DengueVirus::~DengueVirus()
{
    this->DoDie();
}