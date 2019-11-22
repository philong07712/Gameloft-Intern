#pragma once
# include "FluVirus.h"
# include <time.h>
void FluVirus::DoBorn() {
    this->LoadADNInformation();
    int *colorArray = new int[2]{0x0000ff, 0xff0000};
    srand(time(0));
    int index = rand() % 2; 
    this->m_color = colorArray[index];
    delete[] colorArray;
}

void FluVirus::DoClone() {
    cout << "Clone";
}

void FluVirus::DoDie() {
    cout << "Die";
}

void FluVirus::InitResistance() {
    srand(time(0));
    cout << "Resit";
}