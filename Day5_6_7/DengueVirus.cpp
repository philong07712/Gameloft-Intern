#include "DengueVirus.h"
#include <time.h>
DengueVirus::DengueVirus()
{
    this->DoBorn();
    this->InitResistance();
}

void DengueVirus::DoBorn()
{
    this->LoadADNInformation();
    string *proteinArray = new string[3]{"NS3", "NS5", "E"};
    // set Random value change eachtime call
    srand(time(0));
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
    srand(time(0));
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
    cout << "Clone";
}

DengueVirus::~DengueVirus()
{
    this->DoDie();
}