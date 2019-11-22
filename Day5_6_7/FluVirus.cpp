#pragma once
#include "FluVirus.h"
#include <time.h>
void FluVirus::DoBorn()
{
    this->LoadADNInformation();
    int *colorArray = new int[2]{0x0000ff, 0xff0000};
    // set Random value change eachtime call
    srand(time(0));
    // random [0, 1]
    int index = rand() % 2;
    this->m_color = colorArray[index];
    delete[] colorArray;
}

void FluVirus::DoClone()
{
    cout << "Clone";
}

void FluVirus::DoDie()
{
    cout << "Die";
}

void FluVirus::InitResistance()
{
    int resit;
    srand(time(0));
    if (this->m_color == 0x0000ff)
    {
        resit = 10 + rand() % 11;
    }
    else
    {
        resit = 10 + rand() % 6;
    }
    this->setM_resistance(resit);
}