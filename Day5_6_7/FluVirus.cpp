#pragma once
#include "FluVirus.h"
#include <time.h>
FluVirus::FluVirus()
{
    srand(time(0));
    this->DoBorn();
    this->InitResistance();
}
void FluVirus::DoBorn()
{
    this->LoadADNInformation();
    int *colorArray = new int[2]{0x0000ff, 0xff0000};
    // set Random value change eachtime call
    // random [0, 1]
    int index = rand() % 2;
    this->m_color = colorArray[index];
    delete[] colorArray;
}

int FluVirus::getM_color()
{
    return this->m_color;
}

void FluVirus::setM_color(int color)
{
    this->m_color = color;
}
Virus *FluVirus::DoClone()
{
    FluVirus *v = new FluVirus();
    v->setM_dna(this->getM_dna());
    v->setM_resistance(this->getM_resistance());
    v->setM_color(this->getM_color());
    return v;
}

void FluVirus::DoDie()
{
    cout << "Released all virus data";
}

void FluVirus::InitResistance()
{
    int resit;
    // random value for color blue
    if (this->m_color == 0x0000ff)
    {
        resit = 10 + rand() % 11;
    }
    // random value for color red;
    else
    {
        resit = 10 + rand() % 6;
    }
    this->setM_resistance(resit);
}

FluVirus::~FluVirus()
{
    this->DoDie();
}